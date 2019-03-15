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
#define LOW_AMPLITUDE 	32500  //强度过低值
#define MAX_PHASE        30000.0 //温度矫正
#define MAX_DIST_VALUE 	30000 //最远距离值
#define OFFSET_PHASE_DEFAULT 0  //深度补偿值
class Imagedepthprocess
{
public:
	Imagedepthprocess();
	~Imagedepthprocess();
	cv::Mat depthProcess();
	cv::Mat getDepth();
	unsigned char* ptr_buf_unsigned;
	cv::Mat _matimg_short;   //16bit数据
	cv::Mat _matimg_show;    //8bit数据
	//void calibrate();
private:
	void calibrate(ushort *img);       //滤波
	void imageAverageEightConnectivity(ushort *depthdata);  //均值滤波
	void calculationAddOffset(ushort *img);     //深度补偿
	int calculationCorrectDRNU(ushort * img);   //温度矫正

	uint16_t raw_dep;
	int realindex, realrow, realcol;
};