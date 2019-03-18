#include "PCLConvert.h"


PCLConvert::PCLConvert()
{
	setConvertParameter(296,296,160,120,0,0,0,0,0);
}


PCLConvert::~PCLConvert()
{
}

void PCLConvert::setConvertParameter(double fx = 296, double fy = 296, double cx = 160, double cy = 120, double k1 = 0, double k2 = 0, double p1 = 0, double p2 = 0, double k3 = 0)
{
	this->fx = fx;
	this->fy = fy;
	this->cx = cx;
	this->cy = cy;
	this->k1 = k1;
	this->k2 = k2;
	this->k3 = k3;
	this->p1 = p1;
	this->p2 = p2;

}

PointCloudT::Ptr PCLConvert::getPointCloud(cv::Mat img)
{
	PointCloudT::Ptr pointcloud(new PointCloudT);

	img = undistImg(img);		//畸变矫正
	
	//点云变换
	int imgWidth = img.size().width;
	int imgHeight = img.size().height;

	for (int i = 0; i < imgHeight; i++)
	{
		for (int j = 0; j < imgWidth; j++)
		{
			float picDist = sqrt((i - imgHeight / 2.0)*(i - imgHeight / 2.0) + (j - imgWidth / 2.0)*(j - imgWidth / 2.0));	//图像上点到中心的像素点个数
			float picAngle = atan2(fx*(i - imgHeight / 2.0), fy*(j - imgWidth / 2.0));												//图像上x,y和中心点角度关系
			float angle = atan(sqrt((j - imgWidth / 2.0)*(j - imgWidth / 2.0) / fx / fx + (i - imgHeight / 2.0)*(i - imgHeight / 2.0) / fy / fy));
			float dist = img.at<ushort>(i, j);				//原始图像深度

			//降低点云数量
			if ((i % 3) || (j % 3))
				continue;

			//过滤无效点
			if (dist == 0 || dist >= 30000)
				continue;

			pcl::PointXYZRGBA p;
			p.z = dist*cos(angle);									//坐标变换后的深度
			p.x = -dist*sin(angle)*cos(picAngle);
			p.y = -dist*sin(angle)*sin(picAngle);

			p.r = 250;
			p.g = 250;
			p.b = 250;
			p.a = 255;

			pointcloud->points.push_back(p);
		}
	}
	
	//检查点数量
	if (pointcloud->size() <= 0)
	{
		pointcloud->resize(1);
	}

	return pointcloud;
}

cv::Mat PCLConvert::undistImg(cv::Mat src)
{
	cv::Mat dst;

	//内参矩阵
	cv::Mat cameraMatrix = cv::Mat::eye(3, 3, CV_64F);		//3*3单位矩阵
	cameraMatrix.at<double>(0, 0) = fx;
	cameraMatrix.at<double>(0, 1) = 0;
	cameraMatrix.at<double>(0, 2) = cx;
	cameraMatrix.at<double>(1, 1) = fy;
	cameraMatrix.at<double>(1, 2) = cy;
	cameraMatrix.at<double>(2, 2) = 1;

	//畸变参数
	cv::Mat distCoeffs = cv::Mat::zeros(5, 1, CV_64F);		//5*1全0矩阵
	distCoeffs.at<double>(0, 0) = k1;
	distCoeffs.at<double>(1, 0) = k2;
	distCoeffs.at<double>(2, 0) = p1;
	distCoeffs.at<double>(3, 0) = p2;
	distCoeffs.at<double>(4, 0) = k3;

	cv::Size imageSize = src.size();
	cv::Mat map1, map2;

	//参数1：相机内参矩阵
	//参数2：畸变矩阵
	//参数3：可选输入，第一和第二相机坐标之间的旋转矩阵
	//参数4：校正后的3X3相机矩阵
	//参数5：无失真图像尺寸
	//参数6：map1数据类型，CV_32FC1或CV_16SC2
	//参数7、8：输出X/Y坐标重映射参数
	initUndistortRectifyMap(cameraMatrix, distCoeffs, cv::Mat(), cameraMatrix, imageSize, CV_32FC1, map1, map2);	//计算畸变映射
	//参数1：畸变原始图像
	//参数2：输出图像
	//参数3、4：X\Y坐标重映射
	//参数5：图像的插值方式
	//参数6：边界填充方式
	remap(src, dst, map1, map2, cv::INTER_LINEAR);

	return dst.clone();
}