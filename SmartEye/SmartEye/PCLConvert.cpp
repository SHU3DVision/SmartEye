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

//点云生成
//img：原始深度图像，CV_U16格式
//colorMat：伪彩色图像，CV_U8C3格式
//colormap：点云是否染色 true点云根据伪彩色图像染色 false全白色
//filterLevel：点云过滤等级
PointCloudT::Ptr PCLConvert::getPointCloud(cv::Mat img, cv::Mat colorMat, bool colormap, int filterLevel)
{
	PointCloudT::Ptr pointcloud(new PointCloudT);

	//img = undistImg(img);		//畸变矫正
	//因为畸变矫正存在坐标变换，部分坐标点的像素值通最近邻补上
	//仍然存在散点噪声，滤波处理
	img = filterImg(img);		//图像滤波
	
	//点云变换
	int imgWidth = img.size().width;
	int imgHeight = img.size().height;

	for (int i = 0; i < imgHeight; i++)
	{
		for (int j = 0; j < imgWidth; j++)
		{
			//float picDist = sqrt((i - imgHeight / 2.0)*(i - imgHeight / 2.0) + (j - imgWidth / 2.0)*(j - imgWidth / 2.0));	//图像上点到中心的像素点个数
			//float picAngle = atan2(fx*(i - imgHeight / 2.0), fy*(j - imgWidth / 2.0));												//图像上x,y和中心点角度关系
			//float angle = atan(sqrt((j - imgWidth / 2.0)*(j - imgWidth / 2.0) / fx / fx + (i - imgHeight / 2.0)*(i - imgHeight / 2.0) / fy / fy));
			float dist = img.at<ushort>(i, j);				//原始图像深度

			//降低点云数量
			if (filterLevel)
				if ((i % filterLevel) || (j % filterLevel))
					continue;

			//过滤无效点
			if (dist == 0 || dist >= 30000)
				continue;

			pcl::PointXYZRGBA p;
			//p.z = dist*cos(angle);									//坐标变换后的深度
			//p.x = -dist*sin(angle)*cos(picAngle);
			//p.y = -dist*sin(angle)*sin(picAngle);
			p.z = dist / sqrt((j - imgWidth / 2.0)*(j - imgWidth / 2.0) / fx / fx + (i - imgHeight / 2.0)*(i - imgHeight / 2.0) / fy / fy + 1);
			p.x = -(j - imgWidth / 2.0) / fx*p.z;
			p.y = -(i - imgWidth / 2.0) / fy*p.z;

			if (colormap)
			{
				p.b = colorMat.at<cv::Vec3b>(i, j)[0];
				p.g = colorMat.at<cv::Vec3b>(i, j)[1];
				p.r = colorMat.at<cv::Vec3b>(i, j)[2];
			}
			else
			{
				p.r = 250;
				p.g = 250;
				p.b = 250;
			}
			p.a = 255;

			pointcloud->points.push_back(p);
		}
	}
	
	//检查点数量
	if (pointcloud->size() <= 0)
	{
		pointcloud->resize(1);
	}
	else
	{
		if (savestate == 2)					//保存单帧
		{
			//点云保存
			pointcloud->height = 1;
			pointcloud->width = pointcloud->size();
			pcl::io::savePCDFileBinary(savestr, *pointcloud);
		}
		else if (savestate == 1)				//保存多帧
		{
			savestr.pop_back();
			savestr.pop_back();
			savestr.pop_back();
			savestr.pop_back();				//去掉末尾的 .pcd
			//点云保存
			pointcloud->height = 1;
			pointcloud->width = pointcloud->size();
			pcl::io::savePCDFileBinary(savestr + "_" + std::to_string(num++) + ".pcd", *pointcloud);
		}
		else
		{
			num = 0;
		}
	}

	return pointcloud;
}

//图像畸变矫正
//src：CV_U16C1格式图像
//return：畸变矫正后图像
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
	remap(src, dst, map1, map2, cv::INTER_NEAREST);

	return dst.clone();
}

//畸变矫正后图像滤波
//src：待滤波图像CV_16UC1
//return：滤波后图像
cv::Mat PCLConvert::filterImg(cv::Mat src)
{
	cv::Mat rst = src.clone();
	//cv::medianBlur(src, rst, 5);		//中值滤波
	//cv::GaussianBlur(src, rst, cv::Size(3, 3), 0, 0);	//高斯滤波
	for (int y = 0; y < src.size().height; y++)
	{
		for (int x = 0; x < src.size().width; x++)
		{
			if (y == 0 || y == src.size().height - 1 || x == 0 || x == src.size().width - 1)
			{
				rst.at<ushort>(y, x) = 0;
				continue;
			}

			//遍历周围邻居
			ushort dis[8];
			dis[0] = src.at<ushort>(y - 1, x - 1);
			dis[1] = src.at<ushort>(y - 1, x);
			dis[2] = src.at<ushort>(y - 1, x + 1);
			dis[3] = src.at<ushort>(y, x - 1);
			ushort m = src.at<ushort>(y, x);
			dis[4] = src.at<ushort>(y, x + 1);
			dis[5] = src.at<ushort>(y + 1, x - 1);
			dis[6] = src.at<ushort>(y - 1, x);
			dis[7] = src.at<ushort>(y - 1, x + 1);

			//计算周围有效点数量和均值
			int counter = 0;
			ushort min = 30000;
			for (int i = 0; i < 8; i++)
			{
				if (dis[i] != 0 && dis[i] < 30000)
				{
					counter++;
					if (min > dis[i])
						min = dis[i];
				}
			}

			//满足周围点都是有效点的，计算均值
			if (counter >6)
			{
				rst.at<ushort>(y, x) = min;
			}
			else
				rst.at<ushort>(y, x) = 0;

		}
	}

	return rst.clone();
}