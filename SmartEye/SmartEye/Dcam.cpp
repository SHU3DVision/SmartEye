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
	//�����źŴ��ݱ�������
	qRegisterMetaType<cv::Mat >("cv::Mat");
	qRegisterMetaType<PointCloudT::Ptr>("PointCloudT::Ptr");
}

DCam::~DCam()
{
}

//������߳�
void DCam::run()
{
	
	isRun = true;
	int tempReadDelay = 0;		//��ȡ�¶ȼ���
	int tempReadEnable = 0;     //��ȡ����¶��ź�

	char ptr_buf[MAXLINE];  //�洢������
	int n = -1;

	//�������
	g_Tcpsocket._ip = ip;
	g_Tcpsocket._port = port;

	//��ʼ�����ָ��
	QString inter;

	//�̼��汾��Ϣ
	inter = send_version;
	n = g_Tcpsocket.socket_com(inter.toLatin1().data(), bytecount, (char*)g_Tcpsocket._ip.c_str(), g_Tcpsocket._port, ptr_buf);	//��ѯ����汾��
	emit getImage(cv::Mat(),frame, n);
	if (n != 0)
		return;
	ushort *uc = (ushort*)ptr_buf;
	version = *uc;
	g_depthprocess.version = version;
	emit getVersion(version);

	//���ص�ʹ��
	inter = send_adcOverflow + "1";
	n = g_Tcpsocket.socket_com(inter.toLatin1().data(), bytecount, (char*)g_Tcpsocket._ip.c_str(), g_Tcpsocket._port, ptr_buf);	//���͹��ص�ʹ��
	emit getImage(cv::Mat(),frame, n);
	if (n != 0)
		return;

	//����ʱ��1000
	inter = send_integrationtime3D + "1000";
	n = g_Tcpsocket.socket_com(inter.toLatin1().data(), bytecount, (char*)g_Tcpsocket._ip.c_str(), g_Tcpsocket._port, ptr_buf);	//����3D����ʱ��
	emit getImage(cv::Mat(), frame,n);
	if (n != 0)
		return;

	//��С�ź�ǿ��10
	inter = send_minamp + "10";
	n = g_Tcpsocket.socket_com(inter.toLatin1().data(), bytecount, (char*)g_Tcpsocket._ip.c_str(), g_Tcpsocket._port, ptr_buf);	//������С�ź�ǿ��
	emit getImage(cv::Mat(),frame, n);
	if (n != 0)
		return;

	//��ѭ��
	while (isRun)
	{
		
		//ͼ�������
		g_depthprocess.maxdepth = maxdepth;
		g_depthprocess.mindepth = mindepth;
		g_depthprocess.saveimagestate = saveimagestate;
		g_depthprocess.savestr = savestr;
		//����pcd�������
		g_pclConvert.savestate = savepcdstate;
		g_pclConvert.savestr = string(savePcdStr.toLocal8Bit());
		
		if (integrationtime3Dflag)
		{
			//���ͻ���ʱ��ָ��
			QString send_inter;
			send_inter = send_integrationtime3D + integrationtime3D;
			n = g_Tcpsocket.socket_com(send_inter.toLatin1().data(), bytecount, (char*)g_Tcpsocket._ip.c_str(), g_Tcpsocket._port, ptr_buf);	//����3D����ʱ��

			integrationtime3Dflag = 0;
		}
		else if (setAmpFlag)
		{
			//�����ź�ǿ��ָ��
			QString send_inter;
			send_inter = send_minamp + MinAmp;
			n = g_Tcpsocket.socket_com(send_inter.toLatin1().data(), bytecount, (char*)g_Tcpsocket._ip.c_str(), g_Tcpsocket._port, ptr_buf);	//�����ź�ǿ��
			setAmpFlag = 0;
		}
		else if (tempReadEnable)
		{
			//��ȡ�¶�����
			n = g_Tcpsocket.socket_com(send_temp, bytecount, (char*)g_Tcpsocket._ip.c_str(), g_Tcpsocket._port, ptr_buf);	//��ȡ�¶�����
			tempReadEnable = 0;
		}
		else
		{
			clock_t start = clock();
			//��ȡ�������
			n = g_Tcpsocket.socket_com(send_distance, bytecount, (char*)g_Tcpsocket._ip.c_str(), g_Tcpsocket._port, ptr_buf);	//��ȡ�������
			//tempReadDelay++;
			clock_t end = clock();
			//����֡��
			frame = (float)frametime/ (end - start);
			//qDebug() << "frame=" << frame;
		}

		
		//��ȡ�����ʮ�κ󣬶�ȡ�¶�
		/*if (tempReadDelay > 5)
		{
			tempReadDelay = 0;
			tempReadEnable = 1;
		}*/
		cv::Mat img_show;

		if (n == 1)
		{
			//��ȡ���ݳɹ�
			g_depthprocess.ptr_buf_unsigned = (unsigned char*)ptr_buf;	//����ͼ��������ָ��
			img_show = g_depthprocess.depthProcess();					//��ȡ����ͼ��
			if (isPointCloudConvert)
			{
				//���Ʊ任
				PointCloudT::Ptr cloud = g_pclConvert.getPointCloud(g_depthprocess.getDepth(),img_show,isColormapPoint,pointFilterSize);
				emit(getPointCloud(cloud));
			}

		}
		else if (n == 12)
		{
			g_depthprocess.realTempChip=setRealTemperature(ptr_buf);
			n = 0;
		}

		emit getImage(img_show,frame,n);		//�ɹ��õ�ͼƬ������ucharͼƬ�����򷵻�img��sizeΪ0*0

	}
}

//��������߳�����
//���룺isRun ture������falseֹͣ
void DCam::setRun(bool isRun = false)
{
	this->isRun = isRun;
}

//���룺ip ���IP
//���룺port ����˿�
void DCam::setNet(std::string ip, int port)
{
	this->ip = ip;
	this->port = port;
}

//���õ����Ƿ�ת��
//���룺isConvert ture ת����false ��ת��
void DCam::setPointcloudConvert(bool isConvert)
{
	this->isPointCloudConvert = isConvert;
}

//��������ڲΡ�����ϵ��
void DCam::setCameraParameters(double fx, double fy, double cx, double cy, double k1, double k2, double p1, double p2, double k3)
{
	g_pclConvert.setConvertParameter(fx, fy, cx, cy, k1, k2, 0, 0, 0);
}

//��ȡ����״̬
bool DCam::getRunState()
{
	return isRun;
}

//��ʾ����¶�
//���룺buf �¶�����ָ�루16λ)
int DCam::setRealTemperature(char *buf)
{
	int i;
	ushort	realTempBoard1;
	ushort	realTempBoard2;
	ushort temp = 0;

	for (i = 0; i < 4; i++){
		temp += (uchar)*(buf + i * 2) + (ushort)(*(buf + i * 2 + 1)) * 256;
	}
	//�¶�ת��
	realTempChip = temp / 4;
	realTempBoard1 = (uchar)*(buf + 8) + (ushort)(*(buf + 9)) * 256;
	realTempBoard2 = (uchar)*(buf + 10) + (ushort)(*(buf + 11)) * 256;
	return realTempChip;
}

//��ȡ���ͼ��
Mat DCam::getDepth()
{
	cv::Mat dcam_imageinfor;            //���ͼ��
	dcam_imageinfor = g_depthprocess.getDepth();
	return dcam_imageinfor.clone();
}

//���õ����Ƿ���Ҫ��α��ɫ
//stat true��α��ɫ falseȫ��ɫ
void DCam::setColormapPoint(bool stat = true)
{
	isColormapPoint = stat;
}

//ƽ����ʾЧ������ܶȣ����õ��ܶ�
//value�� �����ܶ�
void DCam::setPointFilterSize(int value)
{
	pointFilterSize = value;
}


//����ͼ��ˮƽ��ת
//isCheck������ˮƽ��ת��־ 0����ת 1��ת
void DCam::setHorizontalFlip(bool isChecked)
{
	this->horizontalFlipFlag = isChecked;
	g_depthprocess.isHorizontalFlip = isChecked;
}

//����ͼ��ֱ��ת
//isCheck�����ô�ֱ��ת��־ 0����ת 1��ת
void DCam::setVerticalFlip(bool isChecked)
{

	this->verticalFlipFlag = isChecked;
	g_depthprocess.isVerticalFlip = isChecked;
}


//��ȡ����̼��汾��
//10900 1.9.0
//20600 2.6.0
//21200 2.12.0
ushort DCam::getVersion()
{
	return version;
}