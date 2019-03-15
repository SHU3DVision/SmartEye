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
	viewer->setCameraPosition(-557.379, 9640.31, -6123, -0.00374522, -0.795958, -0.60534);
	ui.screen->update();

	ui.screen->hide();


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
	
	if (connectState == 0)
	{
		//启动相机，获取图像
		std::string ip = ui.IplineEdit->text().toStdString();    //获取相机IP
		int port = ui.PortlineEdit->text().toInt();      //获取相机端口号
		g_dcam = new DCam(ip,port);						 //初始化相机类
		connect(g_dcam, SIGNAL(getImage(cv::Mat)), this, SLOT(imageUpdateSlot(cv::Mat)));	//设置连接槽
		g_dcam->start();	//线程启动

		ui.statelabel->setText("Success");
		ui.connectButton->setText("Disconnect");
		connectState++;
	}
	else
	{
		g_dcam->setRun(false);
		ui.statelabel->setText("No");
		ui.connectButton->setText("Connect");
		connectState--;
	}
	
}
//TCP通信
//正常连接断开，返回0
//异常连接，返回-1
void SmartEye::imageUpdateSlot(cv::Mat img)
{
	if (img.size().height != 0)
	{
			//处理原始数据
			cv::Mat imshowsrc = img;
			//显示灰度图
			showImage(imshowsrc);
			
			////点云展示
			//if (isPCLShow)
			//{
			//	cloud = g_pclConvert.getPointCloud(g_depthprocess.getDepth());
			//	showPointCloud();
			//}
	}
	else
	{
		ui.statelabel->setText("No");
		ui.connectButton->setText("Connect");
		return;
	}
	return;
		
}

//点云数据更新
void SmartEye::pointCloudUpdateSlot(PointCloudT::Ptr c)
{
	//点云数据更新
	cloud = c;
	showPointCloud();
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

	g_dcam->setCameraParameters(fx, fy, cx, cy, k1, k2, 0, 0, 0);


	if (isPCLShow)
	{
		//关闭更新
		isPCLShow = false;
		ui.screen->hide();
		g_dcam->setPointcloudConvert(false);
	}
	else
	{
		//显示点云
		isPCLShow = true;
		ui.screen->show();
		connect(g_dcam, SIGNAL(getPointCloud(PointCloudT::Ptr)), this, SLOT(pointCloudUpdateSlot(PointCloudT::Ptr)));
		g_dcam->setPointcloudConvert(true);
	}
}

void SmartEye::showPointCloud()
{
	viewer->removeAllPointClouds();
	viewer->addPointCloud(cloud, "cloud");
	viewer->updatePointCloud(cloud, "cloud");
	//if (!i++)
		//viewer->resetCamera();
	pcl::visualization::Camera c;
	viewer->getCameraParameters(c);
	qDebug() << "pos1:" << c.pos[0] << "\tpos2:" << c.pos[1] <<"\tpos3:"<< c.pos[2] << endl;
	qDebug() << "view1:" << c.view[0] << "\tview2:" << c.view[1] << "\tview3:" << c.view[2] << endl;
	ui.screen->update();
}