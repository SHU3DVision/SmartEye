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

	clock_t start = clock();
	clock_t end;

	char ptr_buf[MAXLINE];  //存储缓存区
	int n = -1;

	//相机参数
	g_Tcpsocket._ip = ip;
	g_Tcpsocket._port = port;

	//初始化相机指令
	QString inter;


#ifdef COMMUNICATION_TCP
	//固件版本信息
	inter = send_version;
	n = g_Tcpsocket.socket_com(inter.toLatin1().data(), bytecount, (char*)g_Tcpsocket._ip.c_str(), g_Tcpsocket._port, ptr_buf);	//查询相机版本号
	emit getImage(cv::Mat(),frame, n);
	if (n != 0)
		return;
	ushort *uc = (ushort*)ptr_buf;
	version = *uc;
	g_depthprocess.version = version;
	emit getVersion(version);

	//过曝点使能
	inter = send_adcOverflow + "1";
	n = g_Tcpsocket.socket_com(inter.toLatin1().data(), bytecount, (char*)g_Tcpsocket._ip.c_str(), g_Tcpsocket._port, ptr_buf);	//发送过曝点使能
	emit getImage(cv::Mat(),frame, n);
	if (n != 0)
		return;

	//积分时间500
	inter = send_integrationtime3D + "500";
	n = g_Tcpsocket.socket_com(inter.toLatin1().data(), bytecount, (char*)g_Tcpsocket._ip.c_str(), g_Tcpsocket._port, ptr_buf);	//发送3D积分时间
	emit getImage(cv::Mat(), frame,n);
	if (n != 0)
		return;

	//最小信号强度10
	inter = send_minamp + "5";
	n = g_Tcpsocket.socket_com(inter.toLatin1().data(), bytecount, (char*)g_Tcpsocket._ip.c_str(), g_Tcpsocket._port, ptr_buf);	//发送最小信号强度
	emit getImage(cv::Mat(),frame, n);
	if (n != 0)
		return;
#endif

	//主循环
	while (isRun)
	{
		
		//图像处理参数
		g_depthprocess.maxdepth = maxdepth;
		g_depthprocess.mindepth = mindepth;
		g_depthprocess.saveimagestate = saveimagestate;
		g_depthprocess.savestr = savestr;
		//点云pcd保存参数
		g_pclConvert.savestate = savepcdstate;
		g_pclConvert.savestr = string(savePcdStr.toLocal8Bit());
		
#ifdef COMMUNICATION_TCP
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
		else if (isHDRflag)
		{
			//发送HDR使能/关闭命令
			QString send_inter = send_hdr;
			if (isHDR)
				send_inter += " 1";
			else
				send_inter += " 0";
			n = g_Tcpsocket.socket_com(send_inter.toLatin1().data(), bytecount, (char*)g_Tcpsocket._ip.c_str(), g_Tcpsocket._port, ptr_buf);	//发送HDR功能命令
			isHDRflag = 0;
		}
		else if (integrationtime3DHDRflag)
		{
			//发送3D HDR积分时间
			QString send_inter = send_integrationtime3DHDR + integrationtime3DHDR;
			n = g_Tcpsocket.socket_com(send_inter.toLatin1().data(), bytecount, (char*)g_Tcpsocket._ip.c_str(), g_Tcpsocket._port, ptr_buf);	//发送HDR 积分时间
			integrationtime3DHDRflag = 0;
		}
		else if (tempReadEnable)
		{
			//获取温度数据
			n = g_Tcpsocket.socket_com(send_temp, bytecount, (char*)g_Tcpsocket._ip.c_str(), g_Tcpsocket._port, ptr_buf);	//获取温度数据
			tempReadEnable = 0;
		}
		else
		{
			if (isHDR)
			{
				start = clock();
				//获取深度数据
				n = g_Tcpsocket.socket_com(send_distance, bytecount, (char*)g_Tcpsocket._ip.c_str(), g_Tcpsocket._port, ptr_buf);	//获取ROI区域原始图与合成图数据
				//tempReadDelay++;
				end = clock();
				//计算帧率
				frame = (float)frametime / (end - start);

			}
			else
			{
				start = clock();
				//获取深度数据
				n = g_Tcpsocket.socket_com(send_distance, bytecount, (char*)g_Tcpsocket._ip.c_str(), g_Tcpsocket._port, ptr_buf);	//获取深度数据
				//tempReadDelay++;
				end = clock();
				//计算帧率
				frame = (float)frametime/ (end - start);
				//qDebug() << "frame=" << frame;
			}
		}
#else

		char t_ip[64];		//地址
		int nport = 0;		//端口号
		const int  maxsize = 1024 * 60;
		char buf[maxsize];
		int packetnum = 0;

		//clock_t start = clock();
		//循环接收数据
		while (isRun)
		{
			n = g_Udpsocket.Recvfrom(buf, MAXLINE, t_ip, nport);
			if (n > 1)
			{
				if (strcmp(ip.c_str(), t_ip) == 0)		//判断IP地址
				{
					if (buf[0] <= 12 && buf[1] == 'x')	//检查包格式
					{
						packetnum++;
						int size = n - 2;
						memcpy((char*)ptr_buf + size*((int)buf[0]), buf + 2, size);

						if (buf[0] == 3)
						{
							//接受完一帧数据，跳出循环
							n = 1;
							clock_t end = clock();
							float frame_temp = (float)frametime / (end - start);
							frame = frame_temp >40?frame:frame_temp;
							start = end;
							break;
						}
					}
				}
				
			}
		}
		
#endif
		
		cv::Mat img_show;

		if (n == 1)
		{
			//获取数据成功
			g_depthprocess.ptr_buf_unsigned = (unsigned char*)ptr_buf;	//设置图像处理数据指针
			img_show = g_depthprocess.depthProcess(isHDR);					//获取处理图像
			if (g_depthprocess.saveimagestate == 2)						//及时切换保存状态  不能写成 saveimagestate == 2  
			{
				saveimagestate = 0;
				g_depthprocess.saveimagestate = 0;
			}
			if (isPointCloudConvert)
			{
				//点云变换
				PointCloudT::Ptr cloud = g_pclConvert.getPointCloud(g_depthprocess.getDepth(),img_show,isColormapPoint,pointFilterSize);
				if (g_pclConvert.savestate == 2)						//及时切换保存状态  不能写成 savepcdstate == 2  
				{
					savepcdstate = 0;
					g_pclConvert.savestate = 0;
				}
				emit(getPointCloud(cloud));
			}

		}
		else if (n == 12)
		{
			g_depthprocess.realTempChip=setRealTemperature(ptr_buf);
			n = 0;
		}

		emit getImage(img_show,frame,n);		//成功得到图片，返回uchar图片，否则返回img的size为0*0

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
cv::Mat DCam::getDepth()
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


//设置图像水平翻转
//isCheck：设置水平翻转标志 0不反转 1翻转
void DCam::setHorizontalFlip(bool isChecked)
{
	this->horizontalFlipFlag = isChecked;
	g_depthprocess.isHorizontalFlip = isChecked;
}

//设置图像垂直翻转
//isCheck：设置垂直翻转标志 0不反转 1翻转
void DCam::setVerticalFlip(bool isChecked)
{

	this->verticalFlipFlag = isChecked;
	g_depthprocess.isVerticalFlip = isChecked;
}


//获取相机固件版本号
//10900 1.9.0
//20600 2.6.0
//21200 2.12.0
ushort DCam::getVersion()
{
	return version;
}

//设置偏移量
//输入：value 偏移量
void DCam::setOffset(int value)
{
	g_depthprocess.offset = value;
}