#ifndef SMARTEYE_H
#define SMARTEYE_H

#include <vtkAutoInit.h> 
VTK_MODULE_INIT(vtkRenderingOpenGL2);
VTK_MODULE_INIT(vtkInteractionStyle);

#include <QtWidgets/QMainWindow>
#include "ui_smarteye.h"
#include <opencv2\opencv.hpp>
#include <thread>
#include <QThread>
#include <Windows.h>
#include <tchar.h>
#include <iostream>
#include <fstream>
#include <direct.h>
#include <io.h>
#include "Depthprocess.h"
#include "TinySocket.h"
#include "PCLConvert.h"
#include <qtimer.h>
#include <qdebug.h>

#include "QVTKWidget.h"
#include <vtkRenderWindow.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/visualization/common/common.h>
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>

using namespace std;
using namespace cv;



class SmartEye : public QMainWindow
{
	Q_OBJECT

public:
	SmartEye(QWidget *parent = 0);
	~SmartEye();
	QLabel *label;
	
	//void depthprocess(); //深度图像处理
	void showImage(Mat imshowsrc);//显示图像

private:
	Ui::SmartEyeClass ui;
	int connectState = 0;
	CTinySocket		g_Tcpsocket;
	Imagedepthprocess g_depthprocess;
	PCLConvert		g_pclConvert;			//点云转换使用
	QTimer    *timer;
	char* sendline = "getDistanceSorted";   //发送获取深度数据指令
	bool isPCLShow = false;					//是否点云转换标志
	boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer;	//PCL可视化窗口
	PointCloudT::Ptr cloud;					//点云指针
	int i = 0;	//临时
	
	void showPointCloud();	  //点云显示

private slots:
     int TCPSocketSlot();//建立TCP通信
	 void connectStateSlot();//通信状态
	 void pointCloudConvert();//点云转换功能 
	 

};

#endif // SMARTEYE_H
