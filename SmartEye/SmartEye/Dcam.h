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
	void setPointcloudConvert(bool isConvert);	//���õ�����ʾ
	cv::Mat  getDepth();							//��ȡ���ͼ��
	void setCameraParameters(double fx, double fy, double cx, double cy, double k1, double k2, double p1, double p2, double k3);	//��������ڲΡ�����ϵ��
	int  setRealTemperature(char *buf);			//��ȡ����¶�
	bool getRunState();							//��ȡ����״̬
	void setColormapPoint(bool stat);			//���õ���α��ɫ��־
	void setPointFilterSize(int value);			//���õ����ܶ�
	void setHorizontalFlip(bool isChecked);		//����ͼ��ˮƽ��ת
	void setVerticalFlip(bool isChecked);			//����ͼ��ֱ��ת
	ushort getVersion();						//��ȡ����̼��汾
	void setOffset(int value);					//����ƫ����

	int maxdepth=25000;					//ӳ����Զ����    
	int mindepth=0;						//ӳ���������
	int saveimagestate = 0;             //save״̬	0������ 1����ͼ��
	int savepcdstate = 0;				//PCD����״̬ 0������ 1����
	bool integrationtime3Dflag = 0;		//����ʱ���־λ��1���ͻ���ʱ��ָ�� 0��
	bool setAmpFlag = 0;                //�����ź�ǿ�ȣ�1������С�ź�ǿ��ָ��
	bool horizontalFlipFlag = 0;		//ˮƽ��ת��־λ
	bool verticalFlipFlag = 0;			//��ֱ��ת��־λ
	bool isHDR = false;					//�Ƿ���HDR
	bool isHDRflag = false;				//HDRָ��ͱ�־λ��1���ͣ�0��(�Ƿ����HDRָ����־)
	bool integrationtime3DHDRflag = 0;	//HDR����ʱ���־λ,1���� 0��
	bool DRNUchanged = false;			//DRNU״̬����
	int DRNUmodel = 0;					//drnuģʽ��0���رգ�1��ģʽ1(fast DRNU); ģʽ2(��ȷDRNU)
	bool AbsChanged = true;				//������У׼״̬
	bool isABS = true;					//�Ƿ񻷾���У׼
	bool isAmp = false;					//�Ƿ���ʾǿ��ͼ
	bool isRawCalibration = false;		//��������У����־
	QString integrationtime3D="500";	//�������ʱ��
	QString integrationtime3DHDR = "2500";//HDR����ʱ��
	QString MinAmp = "100";             //���ǿ��
	QString MaxAmp = "500";				//���ǿ��
	QString savestr;					//����·��
	QString saveAmpstr;
	QString savePcdStr;					//���Ʊ���·��
	

signals:
	void getImage(cv::Mat,float, int);//��ȡͼ����ź�,Mat��ʽ����ͼ����Ϣ����һ��intΪ����֡�ʣ��ڶ�int�����Ƿ���ͼ��0����ͼ��1��ͼ��-1�쳣
	void getAmpImage(cv::Mat, int);
	void getPointCloud(PointCloudT::Ptr);	//��ȡ�����ź�
	void getVersion(ushort);				//��ȡ�汾��Ϣ

protected:
	void run();							//�̳���QThread���߳����к���

private:
	Imagedepthprocess g_depthprocess;	//ԭʼͼ������
	CTinySocket	g_Tcpsocket;			//SOCKET��
	UTinySocket g_Udpsocket = UTinySocket(1, UDP_SERVER_PORT);
	PCLConvert	g_pclConvert;			//����ת��ʹ��
	bool isRun = false;					//�Ƿ�����
	bool isPointCloudConvert = false;	//�Ƿ����ת��
	bool isColormapPoint = true;		//�Ƿ����α��ɫ
	int  pointFilterSize = 0;			//�����ܶ����ã�ƽ����ƺ��ٶȣ�
	std::string ip = "192.168.7.2";		//���IP
	int port = 50660;					//����˿�
	float frame = 0;                       //���֡��
	ushort version = 0;					//����̼��汾
	char* send_distance = "getDistanceSorted";   //���ͻ�ȡ�������ָ��
	char* send_dist_amp = "getDistanceAndAmplitudeSorted";      //���ͻ�ȡHDR�ϳ�ͼ��HDRԭʼͼָ��
	char* send_temp = "getTemperature";//���ͻ�ȡ�¶�����ָ��
	QString send_integrationtime3D = "setIntegrationTime3D ";   //����3D����ʱ��ָ��
	QString send_integrationtime3DHDR = "setIntegrationTime3DHDR ";	//����3D HDR����ʱ��ָ��
	QString send_minamp = "setMinAmplitude ";				//����������Сǿ��ָ��
	QString send_adcOverflow = "enableAdcOverflow ";		//����adc��������أ�ʹ��ָ��
	QString send_hdr = "enableHDR";                            //���Ϳ���HDRָ��
	QString send_version = "version";						//��ȡ����汾��
	ushort	realTempChip;		//�¶�
	
	

};

