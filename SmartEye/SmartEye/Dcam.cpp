#include "DCam.h"

DCam::DCam(QObject *parent)
	: QThread(parent)
{
	DCam();
}

DCam::DCam(std::string ip, int port)
{
	setNet(ip, port);
	DCam();
}

DCam::DCam()
{
	qRegisterMetaType<cv::Mat >("cv::Mat");
	qRegisterMetaType<PointCloudT::Ptr>("PointCloudT::Ptr");
}

DCam::~DCam()
{
}

void DCam::run()
{
	
	isRun = true;

	//主循环
	while (isRun)
	{
		g_Tcpsocket._ip = ip;
		g_Tcpsocket._port = port;
		char ptr_buf[MAXLINE];  //存储缓存区
		int n = g_Tcpsocket.socket_com(send_distance, bytecount, (char*)g_Tcpsocket._ip.c_str(), g_Tcpsocket._port, ptr_buf);	//获取数据
		cv::Mat img_show;

		if (n == 1)
		{
			//获取数据成功
			g_depthprocess.ptr_buf_unsigned = (unsigned char*)ptr_buf;
			img_show = g_depthprocess.depthProcess();
			if (isPointCloudConvert)
			{
				PointCloudT::Ptr cloud = g_pclConvert.getPointCloud(g_depthprocess.getDepth());
				emit(getPointCloud(cloud));
			}
		}
		else if (n == 12)
		{

		}

		emit getImage(img_show,1);		//成功得到图片，返回uchar图片，否则返回img的size为0*0

	}
}

void DCam::setRun(bool isRun = false)
{
	this->isRun = isRun;
}

void DCam::setNet(std::string ip, int port)
{
	this->ip = ip;
	this->port = port;
}

void DCam::setPointcloudConvert(bool isConvert)
{
	this->isPointCloudConvert = isConvert;
}

void DCam::setCameraParameters(double fx, double fy, double cx, double cy, double k1, double k2, double p1, double p2, double k3)
{
	g_pclConvert.setConvertParameter(fx, fy, cx, cy, k1, k2, 0, 0, 0);
}

bool DCam::getRunState()
{
	return isRun;
}
//显示相机温度
//输入：buf 温度数据指针（16位
int DCam::setrealtemperature(char *buf)
{
	int i;
	ushort temp = 0;
	for (i = 0; i < 4; i++){
		temp += (uchar)*(buf + i * 2) + (ushort)(*(buf + i * 2 + 1)) * 256;
	}
	//温度转换
	realTempChip = temp / 4;
	realTempBoard1 = (uchar)*(buf + 8) + (ushort)(*(buf + 9)) * 256;
	realTempBoard2 = (uchar)*(buf + 10) + (ushort)(*(buf + 11)) * 256;
	return realTempChip;
}