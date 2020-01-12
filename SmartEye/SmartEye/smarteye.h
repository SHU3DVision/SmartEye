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
#include <qtcpserver.h>
#include <qtcpsocket.h>

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
	
	//void depthprocess(); //���ͼ����
	void showImage(Mat imshowsrc);//��ʾͼ��
	void showFrame(float frame); //��ʾ֡��

protected:
	bool eventFilter(QObject *, QEvent *);	//����ͼƬlabel����¼�����ȡ����λ��

private:
	Ui::SmartEyeClass ui;
	int connectState = 0;					//socket����״̬�����ڸ������Ӱ�ťui 0������ 1����
	int savestate = 0;						//����״̬ 0δ���� 1���ڱ���
	int savepcdstate = 0;					//����pcd�ļ� 0������ 1���ڱ���
	bool isPCLShow = false;					//�Ƿ����ת����־
	boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer;	//PCL���ӻ�����
	PointCloudT::Ptr cloud;					//����ָ��     
	PointCloudT::Ptr cloud_clicked;			//����¼��������
	int pointSize=1;						//������ʾ��С

	

	void showPointCloud();				//������ʾ����
	void getCameraParameterFromFile();	//��config.ini��ȡ����
	void pp_callback(const pcl::visualization::PointPickingEvent& event, void *args);	//���Ƶ���ص�����
	

private slots:
	void imageUpdateSlot(cv::Mat img,float frame,int isImg);	//����ͼ���ź�
	void pointCloudUpdateSlot(PointCloudT::Ptr c);	//���µ�����Ϣ
	void connectButtonPressedSlot();	//���Ӱ�ť�����
	void pclButtonPressedSlot();		//����ת������ 
	void setIntegrationTime3DSlot();	//����3D����ʱ��
	void setMinAmpSlot();                //������С�ź�ǿ��ָ��
	void setMappingDistanceSlot();		//����ӳ�����
	void saveFileSlot();				//��������
	void savePCDSlot();					//����PCD�ļ�
	void pointSizeSliderReleaseSlot();	//���ƴ�С����
	void colormapPointCheckBoxSlot(int value);	//α��ɫ���Ʋ�
	void pointFilterSlot();				//���ƹ��˲ۣ�Ϊ��ƽ����ʾ�͵����ܶȣ����õ�Ĺ��˳̶ȣ�
	void horizontalFlipSlot();			//ˮƽ��ת��ѡ��
	void verticalFlipSlot();			//��ֱ��ת��ѡ��
	void versionUpdateSlot(ushort);		//�汾������ʾ��
	void setOffsetSlot();				//����ƫ������Ӧ��
	void sendStartCommand();			//TCP���Ϳ�ʼ�ɼ�ָ��
	void sendStopCommand();				//TCP���ͽ����ɼ�ָ��
	void sendNewIpCommand();			//TCP������IP��ַָ��
	void changePcNetSlot();				//�޸ı�������

};

#endif // SMARTEYE_H
