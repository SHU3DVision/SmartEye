#include "smarteye.h"
#include"TinySocket.h"
#include<qtimer.h>

CTinySocket		g_Tcpsocket;
QTimer    *timer;
char sendline[] = "getDistanceSorted";
unsigned char* ptr_buf_unsigned = (unsigned char*)g_Tcpsocket.ptr_buf2;
int k = 0;
uint16_t fameDepthArray2[MAXLINE];
Mat src_1(240, 320, CV_16UC1, Scalar(0));
Mat imshowsrc(240, 320, CV_8UC1, Scalar(0));
SmartEye::SmartEye(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	//槽连接
	QObject::connect(ui.connectButton, SIGNAL(triggered()), this, SLOT(connectStateSlot()));
	timer = new QTimer(this);
	QObject::connect(timer, SIGNAL(timeout()), this, SLOT(TCPSocketSlot()));
}

SmartEye::~SmartEye()
{
	
}
//通信状态
void SmartEye::connectStateSlot()
{
	k++;
	TCPSocketSlot();
}
//TCP通信
void SmartEye::TCPSocketSlot()
{
	if (k % 2 == 1)
	{
		g_Tcpsocket._ip = ui.IplineEdit->text().toStdString();    //获取相机IP
		g_Tcpsocket._port = ui.PortlineEdit->text().toInt();      //获取相机端口号
		int flag = g_Tcpsocket.socket_com(sendline, bytecount, (char*)g_Tcpsocket._ip.c_str(), g_Tcpsocket._port);
		if (flag == 1)
		{
			ui.statelabel->setText("Success");
			ui.connectButton->setText("Disconnect");
		}
		depthprocess();
		showImage();
		timer->start();//启动计时器
	}
	else
	{
		ui.statelabel->setText("No");
		ui.connectButton->setText("Connect");
	}
		
	
	
}
//数据处理
void SmartEye::depthprocess()
{
	for (int j = 0; j < bytecount / 2; j++)
	{
		raw_dep = ptr_buf_unsigned[j * 2 + 1] * 256 + ptr_buf_unsigned[2 * j];
		//cout << raw_dep << " ";
		realindex = bytecount / 2 - (j / Img_width + 1) * Img_width + j % Img_width;   //镜像
		realrow = Img_height - 1 - j / Img_width;
		realcol = j % Img_width;
		fameDepthArray2[realindex] = raw_dep;

		//cout << fameDepthArray2[j] << " ";
	}
	uint16_t depth[240][320];
	for (int i = 0; i < 240; i++)
	{
		for (int j = 0; j < 320; j++)
		{
			depth[i][j] = fameDepthArray2[i * 320 + j];
		}
	}
	//16bit原始数据
	for (int i = 0; i < 240; i++)
	{
		for (int j = 0; j < 320; j++)
		{
			src_1.at<ushort>(i, j) = depth[i][j];

		}

	}
	//8bit显示数据
	for (int i = 0; i < 240; i++)
	{
		for (int j = 0; j < 320; j++)
		{
			imshowsrc.at<uchar>(i, j) = 255 - src_1.at<ushort>(i, j) * 25 / 3000;
			//cout << src2.at<uchar>(i, j) << endl;
		}

	}
}
//QT显示图像
void SmartEye::showImage()
{
	QImage img = QImage((const unsigned char*)(imshowsrc.data), imshowsrc.cols, imshowsrc.rows, QImage::Format_Indexed8);
	label = new QLabel();
	ui.Img_label->setAlignment(Qt::AlignCenter);		//居中显示
	ui.Img_label->setPixmap(QPixmap::fromImage(img));
}

