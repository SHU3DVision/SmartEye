#include "smarteye.h"



SmartEye::SmartEye(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//点云初始化
	cloud.reset(new PointCloudT);
	cloud->resize(1);

	//点云ui界面元素绑定
	viewer.reset(new pcl::visualization::PCLVisualizer("viewer", false));
	ui.screen->SetRenderWindow(viewer->getRenderWindow());
	viewer->setupInteractor(ui.screen->GetInteractor(), ui.screen->GetRenderWindow());
	viewer->setCameraPosition(114, -500, 44000, 0, 1, 0);
	ui.screen->update();


	//槽连接
	QObject::connect(ui.connectButton, SIGNAL(triggered()), this, SLOT(connectStateSlot()));
	timer = new QTimer(this);
	QObject::connect(timer, SIGNAL(timeout()), this, SLOT(TCPSocketSlot()));
	QObject::connect(ui.pclBtn, SIGNAL(clicked()), this, SLOT(pointCloudConvert()));
}

SmartEye::~SmartEye()
{
	
}
//通信状态
void SmartEye::connectStateSlot()
{
	connectState++;
	if (TCPSocketSlot()!=0)
	{
		QMessageBox::information(this, "Error Message", "Connect failed,Please Reconnect");
		connectState--;
	}

	
}
//TCP通信
//正常连接断开，返回0
//异常连接，返回-1
int SmartEye::TCPSocketSlot()
{
	if (connectState % 2 == 1)
	{
		g_Tcpsocket._ip = ui.IplineEdit->text().toStdString();    //获取相机IP
		g_Tcpsocket._port = ui.PortlineEdit->text().toInt();      //获取相机端口号
		int flag = g_Tcpsocket.socket_com(sendline, bytecount, (char*)g_Tcpsocket._ip.c_str(), g_Tcpsocket._port);
		if (flag == 1)
		{
			ui.statelabel->setText("Success");
			ui.connectButton->setText("Disconnect");
			g_depthprocess.ptr_buf_unsigned = (unsigned char*)g_Tcpsocket.ptr_buf2;
			//处理原始数据
			cv::Mat imshowsrc = g_depthprocess.depthProcess();
			//显示灰度图
			showImage(imshowsrc);
			
			//点云展示
			if (isPCLShow)
			{
				cloud = g_pclConvert.getPointCloud(g_depthprocess.getDepth());
				showPointCloud();
			}
			

			timer->start();//启动计时器
		}
		else
		{
			ui.statelabel->setText("No");
			ui.connectButton->setText("Connect");
			return -1;
		}
	}
	else
	{
		ui.statelabel->setText("No");
		ui.connectButton->setText("Connect");
		return 0;
	}
	return 0;
		
}

//QT显示图像
void SmartEye::showImage(Mat imshowsrc)
{
	QImage img = QImage((const unsigned char*)(imshowsrc.data), imshowsrc.cols, imshowsrc.rows, QImage::Format_Indexed8);
	label = new QLabel();
	ui.Img_label->setAlignment(Qt::AlignCenter);		//居中显示
	ui.Img_label->setPixmap(QPixmap::fromImage(img));
}

void SmartEye::pointCloudConvert()
{
	//获取畸变矩阵参数
	double fx = ui.FXlineEdit->text().toDouble();
	double fy = ui.FYlineEdit->text().toDouble();
	double cx = ui.CXlineEdit->text().toDouble();
	double cy = ui.CYlineEdit->text().toDouble();
	double k1 = ui.k1lineEdit->text().toDouble();
	double k2 = ui.k2lineEdit->text().toDouble();

	g_pclConvert.setConvertParameter(fx, fy, cx, cy, k1, k2,0,0,0);

	if (isPCLShow)
	{
		//关闭更新
		isPCLShow = false;
	}
	else
	{
		isPCLShow = true;
	}
}

void SmartEye::showPointCloud()
{
	viewer->removeAllPointClouds();
	viewer->addPointCloud(cloud, "cloud");
	viewer->updatePointCloud(cloud, "cloud");
	if (!i++)
		viewer->resetCamera();
	pcl::visualization::Camera c;
	viewer->getCameraParameters(c);
	qDebug() << "pos1:" << c.pos[0] << "\tpos2:" << c.pos[1] <<"\tpos3:"<< c.pos[2] << endl;
	qDebug() << "view1:" << c.view[0] << "\tview2:" << c.view[1] << "\tview3:" << c.view[2] << endl;
	ui.screen->update();
}