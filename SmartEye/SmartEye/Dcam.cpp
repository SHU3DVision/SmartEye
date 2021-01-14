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

	clock_t start = clock();
	clock_t end;

	char ptr_buf[MAXLINE];  //�洢������
	int n = -1;

	//�������
	g_Tcpsocket._ip = ip;
	g_Tcpsocket._port = port;

	//��ʼ�����ָ��
	QString inter;


#ifdef COMMUNICATION_TCP
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

	//����ʱ��500
	inter = send_integrationtime3D + "500";
	n = g_Tcpsocket.socket_com(inter.toLatin1().data(), bytecount, (char*)g_Tcpsocket._ip.c_str(), g_Tcpsocket._port, ptr_buf);	//����3D����ʱ��
	emit getImage(cv::Mat(), frame,n);
	if (n != 0)
		return;

	//��С�ź�ǿ��10
	inter = send_minamp + "5";
	n = g_Tcpsocket.socket_com(inter.toLatin1().data(), bytecount, (char*)g_Tcpsocket._ip.c_str(), g_Tcpsocket._port, ptr_buf);	//������С�ź�ǿ��
	emit getImage(cv::Mat(),frame, n);
	if (n != 0)
		return;
#endif

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
		
#ifdef COMMUNICATION_TCP
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
		else if (isHDRflag)
		{
			//����HDRʹ��/�ر�����
			QString send_inter = send_hdr;
			if (isHDR)
				send_inter += " 1";
			else
				send_inter += " 0";
			n = g_Tcpsocket.socket_com(send_inter.toLatin1().data(), bytecount, (char*)g_Tcpsocket._ip.c_str(), g_Tcpsocket._port, ptr_buf);	//����HDR��������
			isHDRflag = 0;
		}
		else if (integrationtime3DHDRflag)
		{
			//����3D HDR����ʱ��
			QString send_inter = send_integrationtime3DHDR + integrationtime3DHDR;
			n = g_Tcpsocket.socket_com(send_inter.toLatin1().data(), bytecount, (char*)g_Tcpsocket._ip.c_str(), g_Tcpsocket._port, ptr_buf);	//����HDR ����ʱ��
			integrationtime3DHDRflag = 0;
		}
		else if (tempReadEnable)
		{
			//��ȡ�¶�����
			n = g_Tcpsocket.socket_com(send_temp, bytecount, (char*)g_Tcpsocket._ip.c_str(), g_Tcpsocket._port, ptr_buf);	//��ȡ�¶�����
			tempReadEnable = 0;
		}
		else
		{
			if (isHDR)
			{
				start = clock();
				//��ȡ�������
				n = g_Tcpsocket.socket_com(send_distance, bytecount, (char*)g_Tcpsocket._ip.c_str(), g_Tcpsocket._port, ptr_buf);	//��ȡROI����ԭʼͼ��ϳ�ͼ����
				//tempReadDelay++;
				end = clock();
				//����֡��
				frame = (float)frametime / (end - start);

			}
			else
			{
				start = clock();
				//��ȡ�������
				n = g_Tcpsocket.socket_com(send_distance, bytecount, (char*)g_Tcpsocket._ip.c_str(), g_Tcpsocket._port, ptr_buf);	//��ȡ�������
				//tempReadDelay++;
				end = clock();
				//����֡��
				frame = (float)frametime/ (end - start);
				//qDebug() << "frame=" << frame;
			}
		}
#else

		char t_ip[64];		//��ַ
		int nport = 0;		//�˿ں�
		const int  maxsize = 1024 * 60;
		char buf[maxsize];
		int packetnum = 0;

		//clock_t start = clock();
		//ѭ����������
		while (isRun)
		{
			n = g_Udpsocket.Recvfrom(buf, MAXLINE, t_ip, nport);
			if (n > 1)
			{
				if (strcmp(ip.c_str(), t_ip) == 0)		//�ж�IP��ַ
				{
					if (buf[0] <= 12 && buf[1] == 'x')	//������ʽ
					{
						packetnum++;
						int size = n - 2;
						memcpy((char*)ptr_buf + size*((int)buf[0]), buf + 2, size);

						if (buf[0] == 3)
						{
							//������һ֡���ݣ�����ѭ��
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
			//��ȡ���ݳɹ�
			g_depthprocess.ptr_buf_unsigned = (unsigned char*)ptr_buf;	//����ͼ��������ָ��
			img_show = g_depthprocess.depthProcess(isHDR);					//��ȡ����ͼ��
			if (g_depthprocess.saveimagestate == 2)						//��ʱ�л�����״̬  ����д�� saveimagestate == 2  
			{
				saveimagestate = 0;
				g_depthprocess.saveimagestate = 0;
			}
			if (isPointCloudConvert)
			{
				//���Ʊ任
				PointCloudT::Ptr cloud = g_pclConvert.getPointCloud(g_depthprocess.getDepth(),img_show,isColormapPoint,pointFilterSize);
				if (g_pclConvert.savestate == 2)						//��ʱ�л�����״̬  ����д�� savepcdstate == 2  
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
cv::Mat DCam::getDepth()
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

//����ƫ����
//���룺value ƫ����
void DCam::setOffset(int value)
{
	g_depthprocess.offset = value;
}