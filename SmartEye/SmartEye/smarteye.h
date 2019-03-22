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
#include "DCam.h"
#include <qtimer.h>
#include <qdebug.h>
#include <qfile.h>
#include <qfiledialog.h>  
#include<QMouseEvent>

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
	DCam *g_dcam;
	
	//void depthprocess(); //深度图像处理
	void showImage(Mat imshowsrc);//显示图像

protected:
	bool eventFilter(QObject *, QEvent *);	//过滤图片label点击事件，获取坐标位置

private:
	Ui::SmartEyeClass ui;
	int connectState = 0;					//socket连接状态，用于更新连接按钮ui 0无连接 1连接
	int savestate = 0;						//保存状态 0未保存 1正在保存
	bool isPCLShow = false;					//是否点云转换标志
	boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer;	//PCL可视化窗口
	PointCloudT::Ptr cloud;					//点云指针          
	int pointSize=1;						//点云显示大小

	

	void showPointCloud();				//点云显示更新
	void getCameraParameterFromFile();	//从config.ini获取参数
	

private slots:
	void imageUpdateSlot(cv::Mat img,int isImg);	//更新图像信号
	void pointCloudUpdateSlot(PointCloudT::Ptr c);	//更新点云信息
	void connectButtonPressedSlot();	//连接按钮点击槽
	void pclButtonPressedSlot();		//点云转换功能 
	void setIntegrationTime3DSlot();	//设置3D积分时间
	void setMappingDistanceSlot();		//设置映射距离
	void saveFileSlot();				//保存数据
	void pointSizeSliderReleaseSlot();	//点云大小设置
	void colormapPointCheckBoxSlot(int value);	//伪彩色点云槽
	void pointFilterSlot();				//点云过滤槽（为了平衡显示和点云密度，设置点的过滤程度）

};

#endif // SMARTEYE_H
