#ifndef SMARTEYE_H
#define SMARTEYE_H

#include <QtWidgets/QMainWindow>
#include "ui_smarteye.h"
#include<opencv2\opencv.hpp>
#include<thread>
#include<QThread>
#include<Windows.h>
#include<tchar.h>
#include<iostream>
#include <fstream>
#include<direct.h>
#include <io.h>

using namespace std;
using namespace cv;

#define   Img_width   (320)
#define   Img_height  (240)

class SmartEye : public QMainWindow
{
	Q_OBJECT

public:
	SmartEye(QWidget *parent = 0);
	~SmartEye();
	QLabel *label;
	uint16_t raw_dep;
	int realindex, realrow, realcol;

private:
	Ui::SmartEyeClass ui;
	
private slots:
     void TCPSocketSlot();//建立udp通信
	 void depthprocess(); //深度图像处理
	 void showImage();//显示图像


};

#endif // SMARTEYE_H
