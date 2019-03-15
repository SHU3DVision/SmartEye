#pragma once



#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <opencv2/opencv.hpp>

typedef pcl::PointXYZRGBA PointT;
typedef pcl::PointCloud<PointT> PointCloudT;

class PCLConvert
{
public:
	PCLConvert();
	~PCLConvert();
	void setConvertParameter(double fx, double fy, double cx, double cy, double k1, double k2, double p1, double p2, double k3);	//����ת������
	PointCloudT::Ptr getPointCloud(cv::Mat img);		//�������

private:
	cv::Mat undistImg(cv::Mat src);		//�������

	int fx;
	int fy;
	int cx;
	int cy;
	int k1;
	int k2;
	int p1;
	int p2;
	int k3;
};
