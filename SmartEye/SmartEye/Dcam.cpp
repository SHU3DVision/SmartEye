#include "DCam.h"

DCam::DCam(QObject *parent)
	: QThread(parent)
{
	qRegisterMetaType<cv::Mat >("cv::Mat");
}

DCam::DCam(std::string ip, int port)
{
	setNet(ip, port);
}

DCam::~DCam()
{
}

void DCam::run()
{
	qRegisterMetaType<cv::Mat >("cv::Mat");
	qRegisterMetaType<PointCloudT::Ptr>("PointCloudT::Ptr");
	isRun = true;

	while (isRun)
	{
		g_Tcpsocket._ip = ip;
		g_Tcpsocket._port = port;
		int flag = g_Tcpsocket.socket_com(sendline, bytecount, (char*)g_Tcpsocket._ip.c_str(), g_Tcpsocket._port);	//获取数据
		cv::Mat img_show;

		if (flag == 1)
		{
			//获取数据成功
			g_depthprocess.ptr_buf_unsigned = (unsigned char*)g_Tcpsocket.ptr_buf2;
			img_show = g_depthprocess.depthProcess();
			if (isPointCloudConvert)
			{
				PointCloudT::Ptr cloud = g_pclConvert.getPointCloud(g_depthprocess.getDepth());
				emit(getPointCloud(cloud));
			}
		}

		emit getImage(img_show);		//成功得到图片，返回uchar图片，否则返回img的size为0*0

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