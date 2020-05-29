#pragma once

#include <QThread>
#include <opencv2/opencv.hpp>
#include <string>
#include<qstring.h>
#include <QMetaType>
#include<qdebug.h>
#include<time.h>

#include "config.h"
#include "TinySocket.h"
#include "UDPTinySocket.h"
#include "Depthprocess.h"
#include "PCLConvert.h"


#define COLORMAP_MAX_DEPTH 30000
#define COLORMAP_MIN_DEPTH 0
#define frametime  1000


class DCam : public QThread
{
	Q_OBJECT

public:
	DCam(QObject *parent);
	DCam();
	DCam(std::string ip, int port);
	~DCam();
	void setRun(bool isRun);					//�����߳�ֹͣ
	void setNet(std::string ip, int port);		//�������IP���˿�
	void setPcNet(std::string ip, int port);	//���õ���IP���˿�
	void setPointcloudConvert(bool isConvert);	//���õ�����ʾ
	Mat  getDepth();							//��ȡ���ͼ��
	void setCameraParameters(double fx, double fy, double cx, double cy, double k1, double k2, double p1, double p2, double k3);	//��������ڲΡ�����ϵ��
	int  setRealTemperature(char *buf);			//��ȡ����¶�
	bool getRunState();							//��ȡ����״̬
	void setColormapPoint(bool stat);			//���õ���α��ɫ��־
	void setPointFilterSize(int value);			//���õ����ܶ�
	void setHorizontalFlip(bool isChecked);		//����ͼ��ˮƽ��ת
	void setVerticalFlip(bool isChecked);			//����ͼ��ֱ��ת
	ushort getVersion();						//��ȡ����̼��汾
	void setOffset(int value);					//����ƫ����

	int maxdepth=30000;					//ӳ����Զ����    
	int mindepth=0;						//ӳ���������
	int saveimagestate = 0;             //save״̬	0������ 1����ͼ��
	int savepcdstate = 0;				//PCD����״̬ 0������ 1����
	bool integrationtime3Dflag = 0;		//����ʱ���־λ��1���ͻ���ʱ��ָ�� 0��
	bool setAmpFlag = 0;                //�����ź�ǿ�ȣ�1������С�ź�ǿ��ָ��
	bool horizontalFlipFlag = 0;		//ˮƽ��ת��־λ
	bool verticalFlipFlag = 0;			//��ֱ��ת��־λ
	QString integrationtime3D="1000";	//�������ʱ��
	QString MinAmp = "100";             //���ǿ��
	QString savestr;					//����·��
	QString savePcdStr;					//���Ʊ���·��
	

signals:
	void getImage(cv::Mat,float, int);//��ȡͼ����ź�,Mat��ʽ����ͼ����Ϣ����һ��intΪ����֡�ʣ��ڶ�int�����Ƿ���ͼ��0����ͼ��1��ͼ��-1�쳣
	void getAmpImage(cv::Mat);		  //��ȡ�ź�ǿ��ͼ��
	void getPointCloud(PointCloudT::Ptr);	//��ȡ�����ź�
	void getVersion(ushort);				//��ȡ�汾��Ϣ

protected:
	void run();							//�̳���QThread���߳����к���

private:
	Imagedepthprocess g_depthprocess;	//ԭʼͼ������
	CTinySocket	g_Tcpsocket;			//SOCKET��
	UTinySocket *g_Udpsocket = new UTinySocket(1, UDP_SERVER_PORT);
	PCLConvert	g_pclConvert;			//����ת��ʹ��
	bool isRun = false;					//�Ƿ�����
	bool isPointCloudConvert = false;	//�Ƿ����ת��
	bool isColormapPoint = true;		//�Ƿ����α��ɫ
	int  pointFilterSize = 0;			//�����ܶ����ã�ƽ����ƺ��ٶȣ�
	std::string ip = "192.168.7.2";		//���IP
	int port = 50660;					//����˿�
	std::string pcIp;					//����IP
	int pcPort;							//����Port
	float frame = 0;                       //���֡��
	ushort version = 0;					//����̼��汾
	char* send_distance = "getDistanceSorted";   //���ͻ�ȡ�������ָ��
	char* send_temp = "getTemperature";//���ͻ�ȡ�¶�����ָ��
	QString send_integrationtime3D = "setIntegrationTime3D ";   //����3D����ʱ��ָ��
	QString send_minamp = "setMinAmplitude ";				//����������Сǿ��ָ��
	QString send_adcOverflow = "enableAdcOverflow ";		//����adc��������أ�ʹ��ָ��
	QString send_version = "version";						//��ȡ����汾��
	ushort	realTempChip;		//�¶�
	
	

};

