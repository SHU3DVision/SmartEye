#pragma once

#include <QThread>
#include <opencv2/opencv.hpp>
#include <string>
#include<qstring.h>
#include <QMetaType>
#include<qdebug.h>

#include "TinySocket.h"
#include "Depthprocess.h"
#include "PCLConvert.h"


#define COLORMAP_MAX_DEPTH 30000
#define COLORMAP_MIN_DEPTH 0


class DCam : public QThread
{
	Q_OBJECT

public:
	DCam(QObject *parent);
	DCam();
	DCam(std::string ip, int port);
	~DCam();
	void setRun(bool isRun);					//设置线程停止
	void setNet(std::string ip, int port);		//设置相机IP，端口
	void setPointcloudConvert(bool isConvert);	//设置点云显示
	Mat  getDepth();							//获取深度图像
	void setCameraParameters(double fx, double fy, double cx, double cy, double k1, double k2, double p1, double p2, double k3);	//设置相机内参、畸变系数
	int  setRealTemperature(char *buf);			//获取相机温度
	bool getRunState();							//获取运行状态
	void setColormapPoint(bool stat);			//设置点云伪彩色标志
	void setPointFilterSize(int value);			//设置点云密度
	void setHorizontalFlip(bool isChecked);		//设置图像水平翻转
	void setVerticalFlip(bool isChecked);			//设置图像垂直翻转
	ushort getVersion();						//获取相机固件版本

	int maxdepth=30000;					//映射最远距离    
	int mindepth=0;						//映射最近距离
	int saveimagestate = 0;             //save状态	0不保存 1保存图像
	int savepcdstate = 0;				//PCD保存状态 0不保存 1保存
	bool integrationtime3Dflag = 0;		//积分时间标志位，1发送积分时间指令 0无
	bool setAmpFlag = 0;                //设置信号强度，1发送最小信号强度指令
	bool horizontalFlipFlag = 0;		//水平翻转标志位
	bool verticalFlipFlag = 0;			//垂直翻转标志位
	QString integrationtime3D="1000";	//相机积分时间
	QString MinAmp = "100";             //相机强度
	QString savestr;					//保存路径
	QString savePcdStr;					//点云保存路径
	

signals:
	void getImage(cv::Mat,int);				//获取图像后信号,Mat格式传回图像信息，int传回是否是图像0不是图像，1是图像，-1异常
	void getPointCloud(PointCloudT::Ptr);	//获取点云信号
	void getVersion(ushort);				//获取版本信息

protected:
	void run();							//继承自QThread，线程运行函数

private:
	Imagedepthprocess g_depthprocess;	//原始图像处理类
	CTinySocket	g_Tcpsocket;			//SOCKET类
	PCLConvert	g_pclConvert;			//点云转换使用
	bool isRun = false;					//是否运行
	bool isPointCloudConvert = false;	//是否点云转换
	bool isColormapPoint = true;		//是否点云伪彩色
	int  pointFilterSize = 0;			//点云密度设置（平衡点云和速度）
	std::string ip = "192.168.7.2";		//相机IP
	int port = 50660;					//相机端口
	ushort version = 0;					//相机固件版本
	char* send_distance = "getDistanceSorted";   //发送获取深度数据指令
	char* send_temp = "getTemperature";//发送获取温度数据指令
	QString send_integrationtime3D = "setIntegrationTime3D ";   //发送3D积分时间指令
	QString send_minamp = "setMinAmplitude ";				//发送设置最小强度指令
	QString send_adcOverflow = "enableAdcOverflow ";		//发送adc溢出（过曝）使能指令
	QString send_version = "version";						//获取相机版本号
	ushort	realTempChip;		//温度
	
	

};

