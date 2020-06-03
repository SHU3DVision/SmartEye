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
#define LOW_AMPLITUDE_V26 	32500   //ǿ�ȹ���ֵ
#define OVER_EXPOSED_V26	32700	//����ֵ
#define LOW_AMPLITUDE_V212	65300
#define OVER_EXPOSED_V212	65500
#define MAX_PHASE       30000.0 //�¶Ƚ���
#define MAX_DIST_VALUE 	30000 //��Զ����ֵ
#define OFFSET_PHASE_DEFAULT 0  //��Ȳ���ֵ
#define IMG_B(img,y,x) img.at<Vec3b>(y,x)[0]
#define IMG_G(img,y,x) img.at<Vec3b>(y,x)[1]
#define IMG_R(img,y,x) img.at<Vec3b>(y,x)[2]

class Imagedepthprocess
{
public:
	Imagedepthprocess();
	~Imagedepthprocess();
	cv::Mat depthProcess();
	cv::Mat ampProcess();
	cv::Mat getDepth();
	cv::Mat getAmp();
	unsigned char* ptr_buf_unsigned;
	unsigned char* ptr_amp_buf_unsigned;		//���ڴ��amp����ָ��
	cv::Mat _matimg_short;			//16bit����
	cv::Mat _matimg_amp_short;		//16bit����
	cv::Mat _matimg_amp_color;		//�ź�ǿ��α��ɫͼ
	cv::Mat  img_color;				//α��ɫ����
	ushort realTempChip;			//����¶�
	int maxdepth=30000;				//ӳ����Զ����    
	int mindepth=0;					//ӳ���������
	int saveimagestate = 0;			//����ͼƬ״̬
	int imagecount = 0;				//����ͼƬ���
	QString  savestr;				//����·��
	ushort version;					//����汾����Ҫα��ɫ����
	bool isHorizontalFlip = 0;		//ͼƬˮƽ��ת��־
	bool isVerticalFlip = 0;		//ͼƬ��ֱ��ת��־
	int offset = 0;					//���ƫ����
	int ampImageType = 1;			//�ź�ǿ��ͼչʾ���� 0 �Ҷ�ͼ 1 α��ɫͼ 2 �Ҷ�ͼHDR��ǿ

private:
	void calibrate(ushort *img);							//�˲�
	void imageAverageEightConnectivity(ushort *depthdata);  //��ֵ�˲�
	void calculationAddOffset(ushort *img);					//��Ȳ���
	int calculationCorrectDRNU(ushort * img);				//�¶Ƚ���
	void setColorImage(Mat &src_img, Mat &rst_img, int max, int min, int flag = 0);		//����α��ɫͼ
	void saveImage(Mat img, string str, int flag = 0);		//�������ͼ
	int realindex, realrow, realcol;
	//int		drnuLut[50][252][328];						//�¶Ƚ����ñ�
	
};