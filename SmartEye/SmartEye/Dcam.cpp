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
	//声明信号传递变量类型
	qRegisterMetaType<cv::Mat >("cv::Mat");
	qRegisterMetaType<PointCloudT::Ptr>("PointCloudT::Ptr");
}

DCam::~DCam()
{
}

//相机主线程
void DCam::run()
{
	
	isRun = true;
	int tempReadDelay = 0;		//读取温度计数
	int tempReadEnable = 0;     //获取相机温度信号

	//主循环
	while (isRun)
	{
		//相机参数
		g_Tcpsocket._ip = ip;
		g_Tcpsocket._port = port;
		//图像处理参数
		g_depthprocess.maxdepth = maxdepth;
		g_depthprocess.mindepth = mindepth;
		g_depthprocess.saveimagestate = saveimagestate;
		g_depthprocess.savestr = savestr;
		char ptr_buf[MAXLINE];  //存储缓存区
		int n = -1;
		if (integrationtime3Dflag)
		{
			//发送积分时间指令
			QString send_inter;
			send_inter = send_integrationtime3D + integrationtime3D;
			n = g_Tcpsocket.socket_com(send_inter.toLatin1().data(), bytecount, (char*)g_Tcpsocket._ip.c_str(), g_Tcpsocket._port, ptr_buf);	//发送3D积分时间

			integrationtime3Dflag = 0;
		}
		else if (setAmpFlag)
		{
			//发送信号强度指令
			QString send_inter;
			send_inter = send_minamp + MinAmp;
			n = g_Tcpsocket.socket_com(send_inter.toLatin1().data(), bytecount, (char*)g_Tcpsocket._ip.c_str(), g_Tcpsocket._port, ptr_buf);	//发送信号强度
			setAmpFlag = 0;
		}
		else if (tempReadEnable)
		{
			//获取温度数据
			n = g_Tcpsocket.socket_com(send_temp, bytecount, (char*)g_Tcpsocket._ip.c_str(), g_Tcpsocket._port, ptr_buf);	//获取温度数据
			tempReadEnable = 0;
		}
		else
		{
			//获取深度数据
			n = g_Tcpsocket.socket_com(send_distance, bytecount, (char*)g_Tcpsocket._ip.c_str(), g_Tcpsocket._port, ptr_buf);	//获取深度数据
			tempReadDelay++;
		}


		
		
		//读取深度五十次后，读取温度
		if (tempReadDelay > 5)
		{
			tempReadDelay = 0;
			tempReadEnable = 1;
		}
		cv::Mat img_show;

		if (n == 1)
		{
			//获取数据成功
			g_depthprocess.ptr_buf_unsigned = (unsigned char*)ptr_buf;	//设置图像处理数据指针
			img_show = g_depthprocess.depthProcess();					//获取处理图像
			if (isPointCloudConvert)
			{
				//点云变换
				PointCloudT::Ptr cloud = g_pclConvert.getPointCloud(g_depthprocess.getDepth(),img_show,isColormapPoint,pointFilterSize);
				emit(getPointCloud(cloud));
			}

		}
		else if (n == 12)
		{
			g_depthprocess.realTempChip=setRealTemperature(ptr_buf);
			n = 0;
		}

		emit getImage(img_show,n);		//成功得到图片，返回uchar图片，否则返回img的size为0*0

	}
}

//设置相机线程启动
//输入：isRun ture启动；false停止
void DCam::setRun(bool isRun = false)
{
	this->isRun = isRun;
}

//输入：ip 相机IP
//输入：port 相机端口
void DCam::setNet(std::string ip, int port)
{
	this->ip = ip;
	this->port = port;
}

//设置点云是否转换
//输入：isConvert ture 转换；false 不转换
void DCam::setPointcloudConvert(bool isConvert)
{
	this->isPointCloudConvert = isConvert;
}

//设置相机内参、畸变系数
void DCam::setCameraParameters(double fx, double fy, double cx, double cy, double k1, double k2, double p1, double p2, double k3)
{
	g_pclConvert.setConvertParameter(fx, fy, cx, cy, k1, k2, 0, 0, 0);
}

//获取运行状态
bool DCam::getRunState()
{
	return isRun;
}

//显示相机温度
//输入：buf 温度数据指针（16位)
int DCam::setRealTemperature(char *buf)
{
	int i;
	ushort	realTempBoard1;
	ushort	realTempBoard2;
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

//获取深度图像
Mat DCam::getDepth()
{
	cv::Mat dcam_imageinfor;            //深度图像
	dcam_imageinfor = g_depthprocess.getDepth();
	return dcam_imageinfor.clone();
}

//设置点云是否需要加伪彩色
//stat true加伪彩色 false全白色
void DCam::setColormapPoint(bool stat = true)
{
	isColormapPoint = stat;
}

//平衡显示效果与点密度，设置点密度
//value： 过滤密度
void DCam::setPointFilterSize(int value)
{
	pointFilterSize = value;
}