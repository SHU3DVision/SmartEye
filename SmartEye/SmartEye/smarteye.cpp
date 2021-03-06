#include "smarteye.h"

using namespace cv;
int SmartEye::showImgID = 0;
SmartEye::SmartEye(QWidget *parent)
	: QMainWindow(parent)
{
	
#ifdef QT_NO_DEBUG
	vtkObject::GlobalWarningDisplayOff();  //屏蔽Release下的VTK告警
#endif
	
	ui.setupUi(this);

	ui.pointCloudDock->hide();	//隐藏点云界面
	ui.imageDock->hide();		//隐藏图像界面
	ui.ampDock->hide();
	getCameraParameterFromFile();	//从config.ini读取相机配置参数

	//点云初始化
	cloud.reset(new PointCloudT);
	cloud->resize(1);

	//点云ui界面元素绑定
	viewer.reset(new pcl::visualization::PCLVisualizer("viewer", false));
	ui.screen->SetRenderWindow(viewer->getRenderWindow());
	viewer->setupInteractor(ui.screen->GetInteractor(), ui.screen->GetRenderWindow());
	viewer->setCameraPosition(151, -6402, -10771, 0.0133335, 0.945376, -0.325708);	//设置相机视角
	ui.screen->update();	
	
	g_dcam = new DCam();

	//lable颜色设置
	ui.statelabel->setAlignment(Qt::AlignCenter);	//连接状态剧中
	ui.statelabel->setAutoFillBackground(true);		//填充背景
	QPalette pa;
	pa.setColor(QPalette::Background, Qt::darkRed);
	ui.statelabel->setPalette(pa);					//更改颜色
	
	//savestatelable颜色设置
	ui.savestatelabel->setAlignment(Qt::AlignCenter);	//连接状态剧中
	ui.savestatelabel->setAutoFillBackground(true);		//填充背景
	ui.savestatelabel->setPalette(pa);					//更改颜色

	//savePcdStateLable颜色设置
	ui.savePCDStateLable->setAlignment(Qt::AlignCenter);//连接状态居中
	ui.savePCDStateLable->setAutoFillBackground(true);		//填充背景
	ui.savePCDStateLable->setPalette(pa);					//更改颜色

	//设置窗口大小
	this->resize(409, 409);
	//this->setBaseSize(408, 409);
	//this->setFixedSize(408, 408);

	//图像点击事件
	ui.Img_label->installEventFilter(this);		//label点击事件会调用eventFilter函数

	//点云点击回调
	cloud_clicked.reset(new PointCloudT);
	viewer->registerPointPickingCallback(&SmartEye::pp_callback, *this, NULL);


	//槽连接
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
	QObject::connect(ui.setMaxAmplineEdit, SIGNAL(editingFinished()), this, SLOT(setMaxAmpSlot()));
	QObject::connect(ui.HFlip, SIGNAL(clicked()), this, SLOT(horizontalFlipSlot()));
	QObject::connect(ui.VFlip, SIGNAL(clicked()), this, SLOT(verticalFlipSlot()));
	QObject::connect(ui.checkBoxHDR, SIGNAL(clicked()), this, SLOT(setHDRSlot()));
	QObject::connect(ui.IntegrationtimeHDRlineEdit, SIGNAL(editingFinished()), this,SLOT(setIntegrationTime3DHDRSlot()));
	QObject::connect(ui.checkBoxDRNU, SIGNAL(clicked()), this, SLOT(setDRNUSlot()));
	QObject::connect(ui.checkBoxSetABS, SIGNAL(clicked()), this, SLOT(setABSSlot()));
	QObject::connect(ui.checkBoxAmp, SIGNAL(clicked()), this, SLOT(setAmpSlot()));
	QObject::connect(ui.checkBoxCalibration, SIGNAL(clicked()), this, SLOT(setCalibrationSlot()));
	QObject::connect(ui.CXlineEdit, SIGNAL(editingFinished()), this, SLOT(setCameraParametersSlot()));
	QObject::connect(ui.CYlineEdit, SIGNAL(editingFinished()), this, SLOT(setCameraParametersSlot()));
	QObject::connect(ui.FXlineEdit, SIGNAL(editingFinished()), this, SLOT(setCameraParametersSlot()));
	QObject::connect(ui.FYlineEdit, SIGNAL(editingFinished()), this, SLOT(setCameraParametersSlot()));
	QObject::connect(ui.k1lineEdit, SIGNAL(editingFinished()), this, SLOT(setCameraParametersSlot()));
	QObject::connect(ui.k2lineEdit, SIGNAL(editingFinished()), this, SLOT(setCameraParametersSlot()));

	QObject::connect(ui.DepthImgMultiSave, SIGNAL(clicked()), this, SLOT(MultiSaveFileSlot()));
	QObject::connect(ui.PclImgMultiSave, SIGNAL(clicked()), this, SLOT(MultiSavePclSlot()));
	
	//更新初始状态
	setHDRSlot();
	setDRNUSlot();
	setABSSlot();
	setAmpSlot();
	setIntegrationTime3DSlot();
	setIntegrationTime3DHDRSlot();
	setMinAmpSlot();
	setCameraParametersSlot();
}

SmartEye::~SmartEye()
{
	
}

//连接按钮点击事件槽
void SmartEye::connectButtonPressedSlot()
{
	if (connectState == 0)
	{
		//启动相机，获取图像
		std::string ip = ui.IplineEdit->text().toStdString();    //获取相机IP
		int port = ui.PortlineEdit->text().toInt();      //获取相机端口号
		g_dcam->setNet(ip,port);						 //初始化相机类
		connect(g_dcam, SIGNAL(getImage(cv::Mat,float,int)), this, SLOT(imageUpdateSlot(cv::Mat,float,int)));	//设置连接槽
		connect(g_dcam, SIGNAL(getAmpImage(cv::Mat, int)), this, SLOT(ampImageUpdateSlot(cv::Mat, int)));	//设置连接槽
		connect(g_dcam, SIGNAL(getVersion(ushort)), this, SLOT(versionUpdateSlot(ushort)));			//版本获取连接槽
		g_dcam->start();	//线程启动
		
		//按钮状态改变
		QPalette pa;
		pa.setColor(QPalette::Background, Qt::darkYellow);
		ui.statelabel->setPalette(pa);					//更改颜色
		ui.statelabel->setText(tr("Connecting"));			//更改文字
		ui.connectButton->setText(tr("Disconnect"));

		//dock显示
		ui.imageDock->show();
		if (isAmpShow)
		{
			ui.ampDock->show();
			ui.ampDock->setGeometry(900, 500, 320, 240);
		}
		connectState++;
	}
	else
	{
		g_dcam->setRun(false);

		//按钮状态改变
		QPalette pa;
		pa.setColor(QPalette::Background, Qt::darkRed);
		ui.statelabel->setPalette(pa);					//更改颜色
		ui.statelabel->setText(tr("No"));
		ui.connectButton->setText(tr("Connect"));

		disconnect(g_dcam, SIGNAL(getImage(cv::Mat,float,int)), this, SLOT(imageUpdateSlot(cv::Mat,float,int)));	//断开槽
		disconnect(g_dcam, SIGNAL(getAmpImage(cv::Mat, float, int)), this, SLOT(ampImageUpdateSlot(cv::Mat, int)));	//设置连接槽
		disconnect(g_dcam, SIGNAL(getVersion(ushort)), this, SLOT(versionUpdateSlot(ushort)));			//断开版本更新槽

		//dock隐藏
		ui.imageDock->hide();
		ui.ampDock->hide();
		connectState--;
	}

	if (connectState == 0)
	{
		saveFileSlot();				//结束保存
		pclButtonPressedSlot();		//结束点云显示
	}
	
}

//更新图片槽
//输入：img 传入图像Mat格式
//输入：isImg 是否是图像，避免读取温度造成跳帧
void SmartEye::imageUpdateSlot(cv::Mat img,float frame,int isImg)
{
	if (isImg == 1)			//读入图片
	{
		if (img.size().height != 0 && g_dcam->getRunState())		//获取数据正常
		{
			//ui更新
			QPalette pa;
			pa.setColor(QPalette::Background, Qt::darkGreen);
			ui.statelabel->setPalette(pa);					//更改颜色
			ui.statelabel->setText(tr("Connected"));
			ui.connectButton->setText(tr("Disconnect"));

			//处理原始数据
			cv::Mat imshowsrc = img;
			//显示伪彩色图
			showImage(imshowsrc);
			showFrame(frame);
			
		}
		else							//获取数据失败
		{
			g_dcam->setRun(false);

			//ui更新
			QPalette pa;
			pa.setColor(QPalette::Background, Qt::darkRed);
			ui.statelabel->setPalette(pa);					//更改颜色
			ui.statelabel->setText(tr("No"));
			ui.connectButton->setText(tr("Connect"));
			return;
		}
	}
	else if (isImg == -1)		//读取异常
	{
		g_dcam->setRun(false);

		//ui更新
		QPalette pa;
		pa.setColor(QPalette::Background, Qt::darkRed);
		ui.statelabel->setPalette(pa);					//更改颜色
		ui.statelabel->setText(tr("No"));
		ui.connectButton->setText(tr("Connect"));
		return;
	}
	
	return;
		
}

//更新强度图片槽
//输入：img 传入图像Mat格式
//输入：isImg 是否是图像，避免读取温度造成跳帧
void SmartEye::ampImageUpdateSlot(cv::Mat img, int isImg)
{
	if (isImg == 1)			//读入图片
	{
		if (img.size().height != 0 && g_dcam->getRunState())		//获取数据正常
		{
			//处理原始数据
			cv::Mat imshowsrc = img;
			//显示灰度图
			QImage img = QImage((uchar*)(imshowsrc.data), imshowsrc.cols, imshowsrc.rows, QImage::Format_Grayscale8);

			int width = ui.amp_label->size().width();
			int height = ui.amp_label->size().height();
			//自适应长宽比
			if ((height / 240.0) > (width / 320.0))
			{
				//按照宽调整大小
				height = width / 320.0 * 240.0;
			}
			else
			{
				//按照高调整大小
				width = height / 240.0 * 320.0;
			}

			img = img.scaled(width, height, Qt::KeepAspectRatio, Qt::SmoothTransformation);	//图像缩放
			ui.amp_label->setAlignment(Qt::AlignCenter);		//居中显示
			ui.amp_label->setPixmap(QPixmap::fromImage(img));	//更新图像
		}
	}
}

//点云数据更新
//输入：c 点云指针
void SmartEye::pointCloudUpdateSlot(PointCloudT::Ptr c)
{
	//点云数据更新
	cloud = c;
	showPointCloud();
}

//QT显示图像
//输入：imshowsrc 伪彩色图像
void SmartEye::showImage(Mat imshowsrc)
{
	Mat imgShow = imshowsrc.clone();

	cv::cvtColor(imgShow, imgShow, COLOR_BGR2RGB);//Opencv默认BGR存储，Qt需要RGB
	QImage img = QImage((uchar*)(imgShow.data), imgShow.cols, imgShow.rows, QImage::Format_RGB888);
	
	int width = ui.Img_label->size().width();
	int height = ui.Img_label->size().height();
	//自适应长宽比
	if ((height / 240.0) > (width / 320.0))
	{
		//按照宽调整大小
		height = width / 320.0 * 240.0;
	}
	else
	{
		//按照高调整大小
		width = height / 240.0 * 320.0;
	}

	img = img.scaled(width,height, Qt::KeepAspectRatio, Qt::SmoothTransformation);	//图像缩放
	ui.Img_label->setAlignment(Qt::AlignCenter);		//居中显示
	ui.Img_label->setPixmap(QPixmap::fromImage(img));	//更新图像
	

}
//帧率显示
void SmartEye::showFrame(float frame)
{
	float imgframe = frame;
	ui.FramelineEdit->setText(QString::number(imgframe));
}

//点云转换按钮点击事件槽
void SmartEye::pclButtonPressedSlot()
{
	if (isPCLShow || !(g_dcam->getRunState()))
	{
		//关闭更新
		isPCLShow = false;
		ui.pointCloudDock->hide();		//dock隐藏
		disconnect(g_dcam, SIGNAL(getPointCloud(PointCloudT::Ptr)), this, SLOT(pointCloudUpdateSlot(PointCloudT::Ptr)));	//断开槽连接
		g_dcam->setPointcloudConvert(false);
	}
	else
	{
		//显示点云
		isPCLShow = true;
		ui.pointCloudDock->show();		//dock显示
		connect(g_dcam, SIGNAL(getPointCloud(PointCloudT::Ptr)), this, SLOT(pointCloudUpdateSlot(PointCloudT::Ptr)));		//设置槽连接
		g_dcam->setPointcloudConvert(true);
	}
}

//点云界面更新
void SmartEye::showPointCloud()
{
	viewer->removePointCloud("cloud");
	viewer->addPointCloud(cloud, "cloud");
	viewer->updatePointCloud(cloud, "cloud");
	viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, pointSize, "cloud");
	ui.screen->update();
}

//从config文件获取相机参数
void SmartEye::getCameraParameterFromFile()
{
	QFile file("config.ini");
	if (file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		int count = 0;
		while (!file.atEnd())
		{
			//读取一行数据
			QByteArray line = file.readLine();
			if (line[0] == '\n')
				break;

			//过滤注释
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

//设置3D积分时间
void SmartEye::setIntegrationTime3DSlot()
{
	g_dcam->integrationtime3D = ui.IntegrationtimelineEdit->text();
	g_dcam->integrationtime3Dflag = 1;
}

//设置HDR积分时间槽
void SmartEye::setIntegrationTime3DHDRSlot()
{
	g_dcam->integrationtime3DHDR = ui.IntegrationtimeHDRlineEdit->text();
	g_dcam->integrationtime3DHDRflag = 1;
}

//设置信号强度
void SmartEye::setMinAmpSlot()
{
	g_dcam->MinAmp = ui.setAmplineEdit->text();
	int MinAmpsize = g_dcam->MinAmp.toInt();
	/*if (MinAmpsize < 10)
	{
		g_dcam->MinAmp = "10";
		ui.setAmplineEdit->setText("10");
	}*/
	g_dcam->setAmpFlag = 1;
}

//设置最大信号强度
void SmartEye::setMaxAmpSlot()
{
	g_dcam->MaxAmp = ui.setMaxAmplineEdit->text();
}

//设置映射距离
void SmartEye::setMappingDistanceSlot()
{
	int maxDepth = (ui.maxdepthlineEdit->text()).toInt();
	int minDepth = (ui.mindepthlineEdit->text()).toInt();

	//限制最大范围
	if (maxDepth > COLORMAP_MAX_DEPTH)
	{
		maxDepth = COLORMAP_MAX_DEPTH;
		ui.maxdepthlineEdit->setText(QString::number(COLORMAP_MAX_DEPTH));
	}
	
	//限制最小范围
	if (minDepth < COLORMAP_MIN_DEPTH)
	{
		minDepth = COLORMAP_MIN_DEPTH;
		ui.mindepthlineEdit->setText(QString::number(COLORMAP_MIN_DEPTH));
	}

	g_dcam->maxdepth = maxDepth;
	g_dcam->mindepth = minDepth;

	
	//错误输入提醒
	if (g_dcam->mindepth > g_dcam->maxdepth)
	{
		QMessageBox::information(this, tr("Error Message"), tr("Please Enter The Correct Format"));
	}
}

//保存深度数据
void SmartEye::MultiSaveFileSlot()
{
	if (DepthImgMultiSaveflag == 0)
	{
		DepthImgMultiSaveflag = 1;
	}
	else
	{
		DepthImgMultiSaveflag = 0;
		savestate = 0;
		g_dcam->saveimagestate = 0;							//停止保存
		QPalette pac;
		pac.setColor(QPalette::Background, Qt::darkRed);
		ui.savestatelabel->setPalette(pac);					//更改颜色
		ui.savestatelabel->setText(tr("Saved"));			//更改文字
		ui.Savebutton->setText(tr("Save PNG"));
	}
}
void SmartEye::saveFileSlot()
{
	if (g_dcam->getRunState() == true)
	{
		QString type_png = "PNG(*.png)";

		struct tm *localt;				//获取本地时间
		time_t t;
		t = time(NULL);
		localt = localtime(&t);
		//string path = "/home/" + to_string(localt->tm_mon) + "_" + to_string(localt->tm_mday) + "_" + to_string(localt->tm_hour) + "_" + to_string(localt->tm_min) + "_DepthImg";
		//string path = "/home/DepthImg" + to_string(showImgID++);
		string path = "/home/Depth_" + to_string(localt->tm_mon) + "_" + to_string(localt->tm_mday);
		string pathAmp = "/home/Amp_" + to_string(localt->tm_mon) + "_" + to_string(localt->tm_mday);
		if (DepthImgMultiSaveflag == 0)
		{
			//第三个参数可以是路径， 也可以是路径加文件名
			g_dcam->savestr = QFileDialog::getSaveFileName(this, "Save Image", QString::fromStdString(path), type_png);
			if (ui.checkBoxAmp->isChecked())
			{
				g_dcam->saveAmpstr = QFileDialog::getSaveFileName(this, "Save Amp Image", QString::fromStdString(pathAmp), type_png);
			}
			if (g_dcam->savestr.isEmpty())		//如果未选择文件便确认，即返回
				return;
			g_dcam->saveimagestate = 2;			//保存单帧
		}
		else									//保存多帧
		{
			if (savestate == 0)				//savestate == 0表示未保存状态
			{
				g_dcam->savestr = QFileDialog::getSaveFileName(this, "Save Image", QString::fromStdString(path), type_png);
				if (ui.checkBoxAmp->isChecked())
				{
					g_dcam->saveAmpstr = QFileDialog::getSaveFileName(this, "Save Amp Image", QString::fromStdString(pathAmp), type_png);
				}

				if (g_dcam->savestr.isEmpty())//如果未选择文件便确认，即返回
					return;
				QPalette pac;
				pac.setColor(QPalette::Background, Qt::darkYellow);
				ui.savestatelabel->setPalette(pac);					//更改颜色
				ui.savestatelabel->setText(tr("Saving"));			//更改文字
				ui.Savebutton->setText(tr("Dis_save"));
				if (savestate == 0)
					savestate++;
				g_dcam->saveimagestate = 1;
			}
			else								//savestate == 1表示处于保存状态
			{
				QPalette pac;
				pac.setColor(QPalette::Background, Qt::darkRed);
				ui.savestatelabel->setPalette(pac);					//更改颜色
				ui.savestatelabel->setText(tr("Saved"));			//更改文字
				ui.Savebutton->setText(tr("Save PNG"));
				if (savestate == 1)
					savestate--;
				g_dcam->saveimagestate = 0;
			}
		}

	}
	else
	{
		QPalette pac;
		pac.setColor(QPalette::Background, Qt::darkRed);
		ui.savestatelabel->setPalette(pac);					//更改颜色
		ui.savestatelabel->setText(tr("Saved"));			//更改文字
		ui.Savebutton->setText(tr("Save PNG"));
		if (savestate == 1)
			savestate--;
		g_dcam->saveimagestate = 0;
	}
}

//保存点云数据
void SmartEye::MultiSavePclSlot()
{
	if (PclImgMultiSave == 0)
	{
		PclImgMultiSave = 1;
	}
	else
	{
		PclImgMultiSave = 0;
		savepcdstate = 0;
		g_dcam->savepcdstate = 0;							//停止保存
		QPalette pac;
		pac.setColor(QPalette::Background, Qt::darkRed);
		ui.savePCDStateLable->setPalette(pac);					//更改颜色
		ui.savePCDStateLable->setText(tr("Saved"));				//更改文字
		ui.savePcdButton->setText(tr("Save PCD"));
	}
}
void SmartEye::savePCDSlot()
{
	if (g_dcam->getRunState() == true)
	{
		QString type_pcd = "PCD(*.pcd)";

		struct tm *localt;				//获取本地时间
		time_t t;
		t = time(NULL);
		localt = localtime(&t);

		if (isPCLShow)
		{
			if (PclImgMultiSave == 0)
			{
				string path = "/home/" + to_string(localt->tm_year + 1900) + "_" + to_string(localt->tm_mon) + "_" + to_string(localt->tm_mday) + "_" +
					to_string(localt->tm_hour) + "_" + to_string(localt->tm_min) + "_" + to_string(localt->tm_sec) + "_SinglePclData";

				g_dcam->savePcdStr = QFileDialog::getSaveFileName(this, "Save PCD", QString::fromStdString(path), type_pcd);

				if (g_dcam->savePcdStr.isEmpty())//如果未选择文件便确认，即返回
					return;
				g_dcam->savepcdstate = 2;		//保存单帧
			}
			else								//保存连续帧
			{
				//正在获取图像且显示点云
				if (savepcdstate == 0)
				{
					string path = "/home/" + to_string(localt->tm_year + 1900) + "_" + to_string(localt->tm_mon) + "_" + to_string(localt->tm_mday) + "_" +
						to_string(localt->tm_hour) + "_" + to_string(localt->tm_min) + "_" + to_string(localt->tm_sec) + "_MultiPclData";

					g_dcam->savePcdStr = QFileDialog::getSaveFileName(this, "Save PCD", QString::fromStdString(path), type_pcd);
					if (g_dcam->savePcdStr.isEmpty())//如果未选择文件便确认，即返回
						return;
					QPalette pac;
					pac.setColor(QPalette::Background, Qt::darkYellow);
					ui.savePCDStateLable->setPalette(pac);					//更改颜色
					ui.savePCDStateLable->setText(tr("Saving"));			//更改文字
					ui.savePcdButton->setText(tr("Dis_save"));
					if (savepcdstate == 0)
						savepcdstate++;
					g_dcam->savepcdstate = 1;

					return;
				}
				else
				{
					QPalette pac;
					pac.setColor(QPalette::Background, Qt::darkRed);
					ui.savePCDStateLable->setPalette(pac);					//更改颜色
					ui.savePCDStateLable->setText(tr("Saved"));				//更改文字
					ui.savePcdButton->setText(tr("Save PCD"));
					if (savepcdstate == 1)
						savepcdstate--;
					g_dcam->savepcdstate = 0;
				}
			}
		}
	}
}


//label点击事件过滤器
bool SmartEye::eventFilter(QObject *obj, QEvent *e)
{
	if (e->type() == QEvent::MouseButtonPress)
	{
		QMouseEvent *env = static_cast<QMouseEvent *>(e);
		if (ui.Img_label == obj)
		{
			//label点击，获取图像坐标
			int img_x;
			int img_y;
			//获取label长宽
			int width = ui.Img_label->size().width();
			int height = ui.Img_label->size().height();
			//判断长宽比
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

			//安全过滤检查
			if (img_x >= 320)
				return true;
			if (img_x < 0)
				return true;
			if (img_y >= 240)
				return true;
			if (img_y < 0)
				return true;

			//ui显示
			ui.xlineEdit->setText(QString::number(img_x));
			ui.ylineEdit->setText(QString::number(img_y));
			//确定图像上像素值
			Mat img_infor = g_dcam->getDepth();
			int point_depth = img_infor.at<ushort>(img_y, img_x);
			ui.depthlineEdit->setText(QString::number(point_depth));
			//计算距离，单位mm
			int distance = point_depth * 125 / 300;
			ui.disLineEdit->setText(QString::number(distance));

			return true;		//阻止事件传递
		}
	}
	
	return false;				//事件不做处理，继续传递
}

//点云点大小设置槽
void SmartEye::pointSizeSliderReleaseSlot()
{
	pointSize = ui.pointSizeSlider->value();
	showPointCloud();
}

//点云伪彩色染色设置
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

//设置点云显示点的密度
void SmartEye::pointFilterSlot()
{
	int value = ui.pointFilterEdit->text().toInt();
	//过滤
	if (value < 0)
		value = 0;
	ui.pointFilterEdit->setText(QString::number(value));

	g_dcam->setPointFilterSize(value);
}

//点云点击回调函数
void SmartEye::pp_callback(const pcl::visualization::PointPickingEvent& event, void *args)
{
	PointT curent_point;
	event.getPoint(curent_point.x, curent_point.y, curent_point.z);
	cloud_clicked->points.clear();
	cloud_clicked->points.push_back(curent_point);

	//显示点坐标信息
	string pos_info = "X:" + to_string((int)curent_point.x) + " Y:" + to_string((int)curent_point.y) + " Z:" + to_string((int)curent_point.z);
	viewer->removeShape("text");
	int h = ui.screen->height() - 20;
	viewer->addText(pos_info, 5, h, "text");

	//红色点标出选择点
	pcl::visualization::PointCloudColorHandlerCustom<PointT> red(cloud_clicked, 255, 0, 0);
	viewer->removePointCloud("clicked_points");
	viewer->addPointCloud(cloud_clicked, red, "clicked_points");
	viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 10, "clicked_points");
}

//水平翻转勾选框槽
void SmartEye::horizontalFlipSlot()
{

	g_dcam->setHorizontalFlip(ui.HFlip->isChecked());

}

//垂直翻转勾选框
void SmartEye::verticalFlipSlot()
{
	g_dcam->setVerticalFlip(ui.VFlip->isChecked());
}

//状态栏更新版本号
void SmartEye::versionUpdateSlot(ushort version)
{
	uint8_t major = version / 10000;
	uint8_t minor = version % 10000 / 100;
	uint8_t patch = version % 100;
	QString strVersion = QString::number(major) + "." + QString::number(minor) + "." + QString::number(patch);
	ui.statusBar->showMessage(tr("Firmware Version: ") + strVersion);
}

//设置偏移量相应槽
void SmartEye::setOffsetSlot()
{
	int value = ui.offsetSpinBox->text().toInt();
	g_dcam->setOffset(value);

}

//设置HDR
void SmartEye::setHDRSlot()
{
	g_dcam->isHDR = ui.checkBoxHDR->isChecked(); //更新HDR选中状态
	g_dcam->isHDRflag = true; //更新isHDR命令发送标志
}

//设置DRNU校准
void SmartEye::setDRNUSlot()
{
	//TODO:这里默认DRNU2模式, 后续新增一个模式选择
	g_dcam->DRNUmodel = ui.checkBoxDRNU->isChecked() == true ? 2 : 0;
	g_dcam->DRNUchanged = true;
}

//设置ABS环境光校准
void SmartEye::setABSSlot()
{
	g_dcam->isABS = ui.checkBoxSetABS->isChecked();
	g_dcam->AbsChanged = true;
}

void SmartEye::setAmpSlot()
{
	g_dcam->isAmp = ui.checkBoxAmp->isChecked();
	isAmpShow = ui.checkBoxAmp->isChecked();
	if (isAmpShow)
	{
		ui.ampDock->show();
		ui.ampDock->setGeometry(900, 500, 320, 240);
	}
	else
	{
		ui.ampDock->hide();
	}
}

void SmartEye::setCameraParametersSlot()
{
	//获取畸变矩阵参数
	double fx = ui.FXlineEdit->text().toDouble();
	double fy = ui.FYlineEdit->text().toDouble();
	double cx = ui.CXlineEdit->text().toDouble();
	double cy = ui.CYlineEdit->text().toDouble();
	double k1 = ui.k1lineEdit->text().toDouble();
	double k2 = ui.k2lineEdit->text().toDouble();

	//设置畸变系数
	g_dcam->setCameraParameters(fx, fy, cx, cy, k1, k2, 0, 0, 0);

}

void SmartEye::setCalibrationSlot()
{
	g_dcam->isRawCalibration = ui.checkBoxCalibration->isChecked();
}