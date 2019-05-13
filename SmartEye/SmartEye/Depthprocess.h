#pragma once

#include <stdio.h>
#include <stdint.h>
#include <opencv2\opencv.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <string>
#include <qmessagebox.h>
using namespace std;
using namespace cv;
#define bytecount 153600
#define   Img_width   (320)
#define   Img_height  (240)
#define MAXLINE 253600     
#define MAX_NUM_PIX	82656	//328 * 252
#define LOW_AMPLITUDE 	32500   //强度过低值
#define OVER_EXPOSED	32700	//过曝值
#define MAX_PHASE       30000.0 //温度矫正
#define MAX_DIST_VALUE 	30000 //最远距离值
#define OFFSET_PHASE_DEFAULT 0  //深度补偿值
#define IMG_B(img,y,x) img.at<Vec3b>(y,x)[0]
#define IMG_G(img,y,x) img.at<Vec3b>(y,x)[1]
#define IMG_R(img,y,x) img.at<Vec3b>(y,x)[2]

class Imagedepthprocess
{
public:
	Imagedepthprocess();
	~Imagedepthprocess();
	cv::Mat depthProcess();
	cv::Mat getDepth();
	unsigned char* ptr_buf_unsigned;
	cv::Mat _matimg_short;   //16bit数据
	cv::Mat _matimg_show;    //16bit数据
	cv::Mat  img_color;  //伪彩色数据
	ushort realTempChip;    //相机温度
	int maxdepth=30000;           //映射最远距离    
	int mindepth=0;           //映射最近距离
	int saveimagestate = 0;     //保存图片状态
	int imagecount = 0;   //保存图片序号
	QString  savestr;              //保存路径
private:
	void calibrate(ushort *img);       //滤波
	void imageAverageEightConnectivity(ushort *depthdata);  //均值滤波
	void calculationAddOffset(ushort *img);     //深度补偿
	int calculationCorrectDRNU(ushort * img);   //温度矫正
	void setColorImage();                     //设置伪彩色图
	void saveImage();                        //保存深度图
	uint16_t raw_dep;
	int realindex, realrow, realcol;
	//int		drnuLut[50][252][328];				//温度矫正用表
	
};