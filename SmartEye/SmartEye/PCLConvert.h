#pragma once



#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <pcl/io/pcd_io.h>
#include <opencv2/opencv.hpp>
#include <string>

typedef pcl::PointXYZRGBA PointT;
typedef pcl::PointCloud<PointT> PointCloudT;

class PCLConvert
{
public:
	PCLConvert();
	~PCLConvert();
	void setConvertParameter(double fx, double fy, double cx, double cy, double k1, double k2, double p1, double p2, double k3);	//����ת������
	PointCloudT::Ptr getPointCloud(cv::Mat img, cv::Mat colorMat, bool colormap,int filterLevel);		//�������

	int savestate = 0;
	std::string savestr;

private:
	cv::Mat undistImg(cv::Mat src);		//�������
	cv::Mat filterImg(cv::Mat src);		//�˲�

	double fx;
	double fy;
	double cx;
	double cy;
	double k1;
	double k2;
	double p1;
	double p2;
	double k3;

	int num = 0;	//�����ļ�����
};

