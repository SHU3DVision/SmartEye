#include "smarteye.h"



SmartEye::SmartEye(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

#ifdef COMMUNICATION_UDP
	setWindowTitle(this->windowTitle() + " UDP");
#endif

	ui.pointCloudDock->hide();	//���ص��ƽ���
	ui.imageDock->hide();		//����ͼ�����

	getCameraParameterFromFile();	//��config.ini��ȡ������ò���

	//���Ƴ�ʼ��
	cloud.reset(new PointCloudT);
	cloud->resize(1);

	//����ui����Ԫ�ذ�
	viewer.reset(new pcl::visualization::PCLVisualizer("viewer", false));
	ui.screen->SetRenderWindow(viewer->getRenderWindow());
	viewer->setupInteractor(ui.screen->GetInteractor(), ui.screen->GetRenderWindow());
	viewer->setCameraPosition(151, -6402, -10771, 0.0133335, 0.945376, -0.325708);	//��������ӽ�
	ui.screen->update();	
	
	g_dcam = new DCam();

	//lable��ɫ����
	ui.statelabel->setAlignment(Qt::AlignCenter);	//����״̬����
	ui.statelabel->setAutoFillBackground(true);		//��䱳��
	QPalette pa;
	pa.setColor(QPalette::Background, Qt::darkRed);
	ui.statelabel->setPalette(pa);					//������ɫ
	
	//savestatelable��ɫ����
	ui.savestatelabel->setAlignment(Qt::AlignCenter);	//����״̬����
	ui.savestatelabel->setAutoFillBackground(true);		//��䱳��
	ui.savestatelabel->setPalette(pa);					//������ɫ

	//savePcdStateLable��ɫ����
	ui.savePCDStateLable->setAlignment(Qt::AlignCenter);//����״̬����
	ui.savePCDStateLable->setAutoFillBackground(true);		//��䱳��
	ui.savePCDStateLable->setPalette(pa);					//������ɫ

	//���ô��ڴ�С
	this->resize(409, 409);
	//this->setBaseSize(408, 409);
	//this->setFixedSize(408, 408);

	//ͼ�����¼�
	ui.Img_label->installEventFilter(this);		//label����¼������eventFilter����

	//���Ƶ���ص�
	cloud_clicked.reset(new PointCloudT);
	viewer->registerPointPickingCallback(&SmartEye::pp_callback, *this, NULL);


	//������
	QObject::connect(ui.connectButton, SIGNAL(clicked()), this, SLOT(connectButtonPressedSlot()));
	QObject::connect(ui.pclBtn, SIGNAL(clicked()), this, SLOT(pclButtonPressedSlot()));
	QObject::connect(ui.IntegrationtimelineEdit, SIGNAL(editingFinished()), this, SLOT(setIntegrationTime3DSlot()));
	QObject::connect(ui.maxdepthlineEdit, SIGNAL(editingFinished()), this, SLOT(setMappingDistanceSlot()));
	QObject::connect(ui.mindepthlineEdit, SIGNAL(editingFinished()), this, SLOT(setMappingDistanceSlot()));
	QObject::connect(ui.Savebutton, SIGNAL(clicked()), this, SLOT(saveFileSlot()));
	QObject::connect(ui.savePcdButton, SIGNAL(clicked()), this, SLOT(savePCDSlot()));
	QObject::connect(ui.pointSizeSlider, SIGNAL(sliderReleased()), this, SLOT(pointSizeSliderReleaseSlot()));
	QObject::connect(ui.offsetSpinBox, SIGNAL(editingFinished()), this, SLOT(setOffsetSlot()));
	QObject::connect(ui.offsetSpinBox, SIGNAL(valueChanged(int)), this, SLOT(setOffsetSlot()));
	QObject::connect(ui.colormapPointCheckBox, SIGNAL(stateChanged(int)), this, SLOT(colormapPointCheckBoxSlot(int)));
	QObject::connect(ui.pointFilterEdit, SIGNAL(editingFinished()), this, SLOT(pointFilterSlot()));
	QObject::connect(ui.setAmplineEdit, SIGNAL(editingFinished()), this, SLOT(setMinAmpSlot()));
	QObject::connect(ui.HFlip, SIGNAL(clicked()), this, SLOT(horizontalFlipSlot()));
	QObject::connect(ui.VFlip, SIGNAL(clicked()), this, SLOT(verticalFlipSlot()));

	QObject::connect(ui.btnStart, SIGNAL(clicked()), this, SLOT(sendStartCommand()));
	QObject::connect(ui.btnStop, SIGNAL(clicked()), this, SLOT(sendStopCommand()));
	QObject::connect(ui.btnSendPcConfig, SIGNAL(clicked()), this, SLOT(sendNewIpCommand()));
	
}

SmartEye::~SmartEye()
{
	
}

//���Ӱ�ť����¼���
void SmartEye::connectButtonPressedSlot()
{
	if (connectState == 0)
	{
		//�����������ȡͼ��
		std::string ip = ui.IplineEdit->text().toStdString();    //��ȡ���IP
		int port = ui.PortlineEdit->text().toInt();      //��ȡ����˿ں�
		g_dcam->setNet(ip,port);						 //��ʼ�������
		connect(g_dcam, SIGNAL(getImage(cv::Mat,float,int)), this, SLOT(imageUpdateSlot(cv::Mat,float,int)));	//�������Ӳ�
		connect(g_dcam, SIGNAL(getVersion(ushort)), this, SLOT(versionUpdateSlot(ushort)));			//�汾��ȡ���Ӳ�
		g_dcam->start();	//�߳�����
		
		//��ť״̬�ı�
		QPalette pa;
		pa.setColor(QPalette::Background, Qt::darkYellow);
		ui.statelabel->setPalette(pa);					//������ɫ
		ui.statelabel->setText(tr("Connecting"));			//��������
		ui.connectButton->setText(tr("Disconnect"));

		//dock��ʾ
		ui.imageDock->show();

		connectState++;
	}
	else
	{
		g_dcam->setRun(false);

		//��ť״̬�ı�
		QPalette pa;
		pa.setColor(QPalette::Background, Qt::darkRed);
		ui.statelabel->setPalette(pa);					//������ɫ
		ui.statelabel->setText(tr("No"));
		ui.connectButton->setText(tr("Connect"));

		disconnect(g_dcam, SIGNAL(getImage(cv::Mat,float,int)), this, SLOT(imageUpdateSlot(cv::Mat,float,int)));	//�Ͽ���
		disconnect(g_dcam, SIGNAL(getVersion(ushort)), this, SLOT(versionUpdateSlot(ushort)));			//�Ͽ��汾���²�

		//dock����
		ui.imageDock->hide();

		connectState--;
	}

	if (connectState == 0)
	{
		saveFileSlot();				//��������
		pclButtonPressedSlot();		//����������ʾ
	}
	
}

//����ͼƬ��
//���룺img ����ͼ��Mat��ʽ
//���룺isImg �Ƿ���ͼ�񣬱����ȡ�¶������֡
void SmartEye::imageUpdateSlot(cv::Mat img,float frame,int isImg)
{
	if (isImg == 1)			//����ͼƬ
	{
		if (img.size().height != 0 && g_dcam->getRunState())		//��ȡ��������
		{
			//ui����
			QPalette pa;
			pa.setColor(QPalette::Background, Qt::darkGreen);
			ui.statelabel->setPalette(pa);					//������ɫ
			ui.statelabel->setText(tr("Connected"));
			ui.connectButton->setText(tr("Disconnect"));

			//����ԭʼ����
			cv::Mat imshowsrc = img;
			//��ʾα��ɫͼ
			showImage(imshowsrc);
			showFrame(frame);
			
		}
		else							//��ȡ����ʧ��
		{
			g_dcam->setRun(false);

			//ui����
			QPalette pa;
			pa.setColor(QPalette::Background, Qt::darkRed);
			ui.statelabel->setPalette(pa);					//������ɫ
			ui.statelabel->setText(tr("No"));
			ui.connectButton->setText(tr("Connect"));
			return;
		}
	}
	else if (isImg == -1)		//��ȡ�쳣
	{
		g_dcam->setRun(false);

		//ui����
		QPalette pa;
		pa.setColor(QPalette::Background, Qt::darkRed);
		ui.statelabel->setPalette(pa);					//������ɫ
		ui.statelabel->setText(tr("No"));
		ui.connectButton->setText(tr("Connect"));
		return;
	}
	
	return;
		
}

//�������ݸ���
//���룺c ����ָ��
void SmartEye::pointCloudUpdateSlot(PointCloudT::Ptr c)
{
	//�������ݸ���
	cloud = c;
	showPointCloud();
}

//QT��ʾͼ��
//���룺imshowsrc α��ɫͼ��
void SmartEye::showImage(Mat imshowsrc)
{
	Mat imgShow = imshowsrc.clone();
	cv::cvtColor(imgShow, imgShow, CV_BGR2RGB);//OpencvĬ��BGR�洢��Qt��ҪRGB
	QImage img = QImage((uchar*)(imgShow.data), imgShow.cols, imgShow.rows, QImage::Format_RGB888);
	
	int width = ui.Img_label->size().width();
	int height = ui.Img_label->size().height();
	//����Ӧ�����
	if ((height / 240.0) > (width / 320.0))
	{
		//���տ������С
		height = width / 320.0 * 240.0;
	}
	else
	{
		//���ոߵ�����С
		width = height / 240.0 * 320.0;
	}

	img = img.scaled(width,height, Qt::KeepAspectRatio, Qt::SmoothTransformation);	//ͼ������
	ui.Img_label->setAlignment(Qt::AlignCenter);		//������ʾ
	ui.Img_label->setPixmap(QPixmap::fromImage(img));	//����ͼ��
	

}
//֡����ʾ
void SmartEye::showFrame(float frame)
{
	float imgframe = frame;
	ui.FramelineEdit->setText(QString::number(imgframe));
}

//����ת����ť����¼���
void SmartEye::pclButtonPressedSlot()
{
	//��ȡ����������
	double fx = ui.FXlineEdit->text().toDouble();
	double fy = ui.FYlineEdit->text().toDouble();
	double cx = ui.CXlineEdit->text().toDouble();
	double cy = ui.CYlineEdit->text().toDouble();
	double k1 = ui.k1lineEdit->text().toDouble();
	double k2 = ui.k2lineEdit->text().toDouble();

	//���û���ϵ��
	g_dcam->setCameraParameters(fx, fy, cx, cy, k1, k2, 0, 0, 0);


	if (isPCLShow || !(g_dcam->getRunState()))
	{
		//�رո���
		isPCLShow = false;
		ui.pointCloudDock->hide();		//dock����
		disconnect(g_dcam, SIGNAL(getPointCloud(PointCloudT::Ptr)), this, SLOT(pointCloudUpdateSlot(PointCloudT::Ptr)));	//�Ͽ�������
		g_dcam->setPointcloudConvert(false);
	}
	else
	{
		//��ʾ����
		isPCLShow = true;
		ui.pointCloudDock->show();		//dock��ʾ
		connect(g_dcam, SIGNAL(getPointCloud(PointCloudT::Ptr)), this, SLOT(pointCloudUpdateSlot(PointCloudT::Ptr)));		//���ò�����
		g_dcam->setPointcloudConvert(true);
	}
}

//���ƽ������
void SmartEye::showPointCloud()
{
	viewer->removePointCloud("cloud");
	viewer->addPointCloud(cloud, "cloud");
	viewer->updatePointCloud(cloud, "cloud");
	viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, pointSize, "cloud");
	ui.screen->update();
}

//��config�ļ���ȡ�������
void SmartEye::getCameraParameterFromFile()
{
	QFile file("config.ini");
	if (file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		int count = 0;
		while (!file.atEnd())
		{
			//��ȡһ������
			QByteArray line = file.readLine();
			if (line[0] == '\n')
				break;

			//����ע��
			if (line[0] != '#')
			{
				QString str(line);
				switch (count++)
				{
				case 0: ui.FXlineEdit->setText(str); break;
				case 1: ui.FYlineEdit->setText(str); break;
				case 2: ui.CXlineEdit->setText(str); break;
				case 3: ui.CYlineEdit->setText(str); break;
				case 5: ui.k1lineEdit->setText(str); break;
				case 6: ui.k2lineEdit->setText(str); break;
				default:
					break;
				}
			}
		}
		file.close();
	}
}

//����3D����ʱ��
void SmartEye::setIntegrationTime3DSlot()
{
	QTcpSocket tcpSock;
	int time = ui.IntegrationtimelineEdit->text().toInt();
	QString command = "setIntegrationTime3D " + QString::number(time);
	QString ip = ui.IplineEdit->text();
	int port = ui.PortlineEdit->text().toInt();
	tcpSock.connectToHost(ip, port);
	if (tcpSock.waitForConnected(1000))
	{
		tcpSock.write(command.toStdString().c_str(), command.size() + 1);
		if (tcpSock.waitForBytesWritten(1000))
		{
			if (tcpSock.waitForReadyRead(1000))
			{
				QByteArray rst;
				rst = tcpSock.read(2);
				if (rst[0] == '\0' && rst[1] == '\0')
				{
					ui.statusBar->showMessage("Command send", 3000);
					return;
				}
			}
			
		}
	}	
	ui.statusBar->showMessage("Command error", 3000);

	//g_dcam->integrationtime3D = ui.IntegrationtimelineEdit->text();
	//g_dcam->integrationtime3Dflag = 1;
}

//�����ź�ǿ��
void SmartEye::setMinAmpSlot()
{

	QTcpSocket tcpSock;
	int time = ui.setAmplineEdit->text().toInt();
	QString command = "setMinAmplitude " + QString::number(time);
	QString ip = ui.IplineEdit->text();
	int port = ui.PortlineEdit->text().toInt();
	tcpSock.connectToHost(ip, port);
	if (tcpSock.waitForConnected(1000))
	{
		tcpSock.write(command.toStdString().c_str(), command.size() + 1);
		if (tcpSock.waitForBytesWritten(1000))
		{
			if (tcpSock.waitForReadyRead(1000))
			{
				QByteArray rst;
				rst = tcpSock.read(2);
				int temp = (int)rst[1] << 8 | rst[0];
				if (temp == time)
				{
					ui.statusBar->showMessage("Command send", 3000);
					return;
				}
			}

		}
	}
	ui.statusBar->showMessage("Command error", 3000);

	//g_dcam->MinAmp = ui.setAmplineEdit->text();
	//int MinAmpsize = g_dcam->MinAmp.toInt();
	///*if (MinAmpsize < 10)
	//{
	//	g_dcam->MinAmp = "10";
	//	ui.setAmplineEdit->setText("10");
	//}*/
	//g_dcam->setAmpFlag = 1;
}

//����ӳ�����
void SmartEye::setMappingDistanceSlot()
{
	int maxDepth = (ui.maxdepthlineEdit->text()).toInt();
	int minDepth = (ui.mindepthlineEdit->text()).toInt();

	//�������Χ
	if (maxDepth > COLORMAP_MAX_DEPTH)
	{
		maxDepth = COLORMAP_MAX_DEPTH;
		ui.maxdepthlineEdit->setText(QString::number(COLORMAP_MAX_DEPTH));
	}
	
	//������С��Χ
	if (minDepth < COLORMAP_MIN_DEPTH)
	{
		minDepth = COLORMAP_MIN_DEPTH;
		ui.mindepthlineEdit->setText(QString::number(COLORMAP_MIN_DEPTH));
	}

	g_dcam->maxdepth = maxDepth;
	g_dcam->mindepth = minDepth;

	
	//������������
	if (g_dcam->mindepth > g_dcam->maxdepth)
	{
		QMessageBox::information(this, tr("Error Message"), tr("Please Enter The Correct Format"));
	}
}

//�����������
void SmartEye::saveFileSlot()
{
	if (g_dcam->getRunState() == true)
	{
			if (savestate % 2 == 0)
			{
				
				g_dcam->savestr = QFileDialog::getExistingDirectory(this, tr("Open Directory"), "/home", QFileDialog::ShowDirsOnly);
				if (g_dcam->savestr.isEmpty())//���δѡ���ļ���ȷ�ϣ�������
					return;
				QPalette pac;
				pac.setColor(QPalette::Background, Qt::darkYellow);
				ui.savestatelabel->setPalette(pac);					//������ɫ
				ui.savestatelabel->setText(tr("Saving"));			//��������
				ui.Savebutton->setText(tr("Dis_save"));
				if (savestate == 0)
					savestate++;
				g_dcam->saveimagestate=1;
			}
			else
			{
				QPalette pac;
				pac.setColor(QPalette::Background, Qt::darkRed);
				ui.savestatelabel->setPalette(pac);					//������ɫ
				ui.savestatelabel->setText(tr("Saved"));			//��������
				ui.Savebutton->setText(tr("Save PNG"));
				if (savestate == 1)
					savestate--;
				g_dcam->saveimagestate = 0;
			}
		
	}
	else
	{
		QPalette pac;
		pac.setColor(QPalette::Background, Qt::darkRed);
		ui.savestatelabel->setPalette(pac);					//������ɫ
		ui.savestatelabel->setText(tr("Saved"));			//��������
		ui.Savebutton->setText(tr("Save PNG"));
		if (savestate == 1)
			savestate--;
		g_dcam->saveimagestate = 0;
	}

}


//�����������
void SmartEye::savePCDSlot()
{
	if (g_dcam->getRunState() == true)
	{
		if (isPCLShow)
		{
			//���ڻ�ȡͼ������ʾ����
			if (savepcdstate % 2 == 0)
			{
				g_dcam->savePcdStr = QFileDialog::getExistingDirectory(this, tr("Open Directory"), "/home", QFileDialog::ShowDirsOnly);
				if (g_dcam->savePcdStr.isEmpty())//���δѡ���ļ���ȷ�ϣ�������
					return;
				QPalette pac;
				pac.setColor(QPalette::Background, Qt::darkYellow);
				ui.savePCDStateLable->setPalette(pac);					//������ɫ
				ui.savePCDStateLable->setText(tr("Saving"));			//��������
				ui.savePcdButton->setText(tr("Dis_save"));
				if (savepcdstate == 0)
					savepcdstate++;
				g_dcam->savepcdstate = 1;

				return;
			}

		}
	}

	QPalette pac;
	pac.setColor(QPalette::Background, Qt::darkRed);
	ui.savePCDStateLable->setPalette(pac);					//������ɫ
	ui.savePCDStateLable->setText(tr("Saved"));			//��������
	ui.savePcdButton->setText(tr("Save PCD"));
	if (savepcdstate == 1)
		savepcdstate--;
	g_dcam->savepcdstate = 0;


}


//label����¼�������
bool SmartEye::eventFilter(QObject *obj, QEvent *e)
{
	if (e->type() == QEvent::MouseButtonPress)
	{
		QMouseEvent *env = static_cast<QMouseEvent *>(e);
		if (ui.Img_label == obj)
		{
			//label�������ȡͼ������
			int img_x;
			int img_y;
			//��ȡlabel����
			int width = ui.Img_label->size().width();
			int height = ui.Img_label->size().height();
			//�жϳ����
			if ((height / 240.0) > (width / 320.0))
			{
				img_x = env->x() * 320 / ui.Img_label->size().width();
				int img_height = width / 320.0 * 240.0;
				int div = (height - img_height) / 2.0;
				img_y = (env->y() - div) * 240.0 / img_height;
			}
			else
			{
				img_y = env->y() * 240 / ui.Img_label->size().height();
				int img_width = height / 240.0 * 320.0;
				int div = (width - img_width) / 2.0;
				img_x = (env->x() - div) * 320.0 / img_width;
			}

			//��ȫ���˼��
			if (img_x >= 320)
				return true;
			if (img_x < 0)
				return true;
			if (img_y >= 240)
				return true;
			if (img_y < 0)
				return true;

			//ui��ʾ
			ui.xlineEdit->setText(QString::number(img_x));
			ui.ylineEdit->setText(QString::number(img_y));
			//ȷ��ͼ��������ֵ
			Mat img_infor = g_dcam->getDepth();
			int point_depth = img_infor.at<ushort>(img_y, img_x);
			ui.depthlineEdit->setText(QString::number(point_depth));
			//������룬��λmm
			int distance = point_depth * 125 / 300;
			ui.disLineEdit->setText(QString::number(distance));

			return true;		//��ֹ�¼�����
		}
	}
	
	return false;				//�¼�����������������
}

//���Ƶ��С���ò�
void SmartEye::pointSizeSliderReleaseSlot()
{
	pointSize = ui.pointSizeSlider->value();
	showPointCloud();
}

//����α��ɫȾɫ����
void SmartEye::colormapPointCheckBoxSlot(int value)
{
	switch (value)
	{
	case 0:
		g_dcam->setColormapPoint(false);
		break;
	case 2:
		g_dcam->setColormapPoint(true);
		break;
	}

	ui.screen->update();
}

//���õ�����ʾ����ܶ�
void SmartEye::pointFilterSlot()
{
	int value = ui.pointFilterEdit->text().toInt();
	//����
	if (value < 0)
		value = 0;
	ui.pointFilterEdit->setText(QString::number(value));

	g_dcam->setPointFilterSize(value);
}

//���Ƶ���ص�����
void SmartEye::pp_callback(const pcl::visualization::PointPickingEvent& event, void *args)
{
	PointT curent_point;
	event.getPoint(curent_point.x, curent_point.y, curent_point.z);
	cloud_clicked->points.clear();
	cloud_clicked->points.push_back(curent_point);

	//��ʾ��������Ϣ
	string pos_info = "X:" + to_string((int)curent_point.x) + " Y:" + to_string((int)curent_point.y) + " Z:" + to_string((int)curent_point.z);
	viewer->removeShape("text");
	int h = ui.screen->height() - 20;
	viewer->addText(pos_info, 5, h, "text");

	//��ɫ����ѡ���
	pcl::visualization::PointCloudColorHandlerCustom<PointT> red(cloud_clicked, 255, 0, 0);
	viewer->removePointCloud("clicked_points");
	viewer->addPointCloud(cloud_clicked, red, "clicked_points");
	viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 10, "clicked_points");
}

//ˮƽ��ת��ѡ���
void SmartEye::horizontalFlipSlot()
{

	g_dcam->setHorizontalFlip(ui.HFlip->isChecked());

}

//��ֱ��ת��ѡ��
void SmartEye::verticalFlipSlot()
{
	g_dcam->setVerticalFlip(ui.VFlip->isChecked());
}

//״̬�����°汾��
void SmartEye::versionUpdateSlot(ushort version)
{
	uint8_t major = version / 10000;
	uint8_t minor = version % 10000 / 100;
	uint8_t patch = version % 100;
	QString strVersion = QString::number(major) + "." + QString::number(minor) + "." + QString::number(patch);
	ui.statusBar->showMessage(tr("Firmware Version: ") + strVersion);
}

//����ƫ������Ӧ��
void SmartEye::setOffsetSlot()
{
	int value = ui.offsetSpinBox->text().toInt();
	g_dcam->setOffset(value);

}


//TCP���Ϳ�ʼ�ɼ�ָ��
void SmartEye::sendStartCommand()
{
	QTcpSocket tcpSock;
	QString command = "start";
	QString ip = ui.IplineEdit->text();
	int port = ui.PortlineEdit->text().toInt();
	tcpSock.connectToHost(ip, port);
	if (tcpSock.waitForConnected(1000))
	{
		tcpSock.write(command.toStdString().c_str(), command.size() + 1);
		if (tcpSock.waitForBytesWritten(1000))
		{
			if (tcpSock.waitForReadyRead(1000))
			{
				QByteArray rst;
				rst = tcpSock.read(2);
				if (rst[0] == '\0' && rst[1] == '\0')
				{
					ui.statusBar->showMessage("Command send", 3000);
					return;
				}
			}

		}
	}
	ui.statusBar->showMessage("Command error", 3000);
}

//TCP����ֹͣ�ɼ�ָ��
void SmartEye::sendStopCommand()
{
	QTcpSocket tcpSock;
	QString command = "stop";
	QString ip = ui.IplineEdit->text();
	int port = ui.PortlineEdit->text().toInt();
	tcpSock.connectToHost(ip, port);
	if (tcpSock.waitForConnected(1000))
	{
		tcpSock.write(command.toStdString().c_str(), command.size() + 1);
		if (tcpSock.waitForBytesWritten(1000))
		{
			if (tcpSock.waitForReadyRead(1000))
			{
				QByteArray rst;
				rst = tcpSock.read(2);
				if (rst[0] == '\0' && rst[1] == '\0')
				{
					ui.statusBar->showMessage("Command send", 3000);
					return;
				}
			}

		}
	}
	ui.statusBar->showMessage("Command error", 3000);
}

//TCP������IP��ַ
void SmartEye::sendNewIpCommand()
{
	QTcpSocket tcpSock;
	QString newIp = ui.lineEditPcIp->text();
	QString command = "newIp " + newIp;
	QString ip = ui.IplineEdit->text();
	int port = ui.PortlineEdit->text().toInt();
	tcpSock.connectToHost(ip, port);
	if (tcpSock.waitForConnected(1000))
	{
		tcpSock.write(command.toStdString().c_str(), command.size() + 1);
		if (tcpSock.waitForBytesWritten(1000))
		{
			if (tcpSock.waitForReadyRead(1000))
			{
				QByteArray rst;
				rst = tcpSock.read(2);
				if (rst[0] == '\0' && rst[1] == '\0')
				{
					ui.statusBar->showMessage("Command send", 3000);
					return;
				}
			}

		}
	}
	ui.statusBar->showMessage("Command error", 3000);
}