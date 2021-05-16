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

//��������
//img��ԭʼ���ͼ��CV_U16��ʽ
//colorMat��α��ɫͼ��CV_U8C3��ʽ
//colormap�������Ƿ�Ⱦɫ true���Ƹ���α��ɫͼ��Ⱦɫ falseȫ��ɫ
//filterLevel�����ƹ��˵ȼ�
PointCloudT::Ptr PCLConvert::getPointCloud(cv::Mat img, cv::Mat colorMat, bool colormap, int filterLevel)
{
	PointCloudT::Ptr pointcloud(new PointCloudT);

	//img = undistImg(img);		//�������
	//��Ϊ���������������任����������������ֵͨ����ڲ���
	//��Ȼ����ɢ���������˲�����
	img = filterImg(img);		//ͼ���˲�
	
	//���Ʊ任
	int imgWidth = img.size().width;
	int imgHeight = img.size().height;

	for (int i = 0; i < imgHeight; i++)
	{
		for (int j = 0; j < imgWidth; j++)
		{
			//float picDist = sqrt((i - imgHeight / 2.0)*(i - imgHeight / 2.0) + (j - imgWidth / 2.0)*(j - imgWidth / 2.0));	//ͼ���ϵ㵽���ĵ����ص����
			//float picAngle = atan2(fx*(i - imgHeight / 2.0), fy*(j - imgWidth / 2.0));												//ͼ����x,y�����ĵ�Ƕȹ�ϵ
			//float angle = atan(sqrt((j - imgWidth / 2.0)*(j - imgWidth / 2.0) / fx / fx + (i - imgHeight / 2.0)*(i - imgHeight / 2.0) / fy / fy));
			float dist = img.at<ushort>(i, j);				//ԭʼͼ�����

			//���͵�������
			if (filterLevel)
				if ((i % filterLevel) || (j % filterLevel))
					continue;

			//������Ч��
			if (dist == 0 || dist >= 30000)
				continue;

			pcl::PointXYZRGBA p;
			//p.z = dist*cos(angle);									//����任������
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
	
	//��������
	if (pointcloud->size() <= 0)
	{
		pointcloud->resize(1);
	}
	else
	{
		if (savestate == 2)					//���浥֡
		{
			//���Ʊ���
			pointcloud->height = 1;
			pointcloud->width = pointcloud->size();
			pcl::io::savePCDFileBinary(savestr, *pointcloud);
		}
		else if (savestate == 1)				//�����֡
		{
			savestr.pop_back();
			savestr.pop_back();
			savestr.pop_back();
			savestr.pop_back();				//ȥ��ĩβ�� .pcd
			//���Ʊ���
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

//ͼ��������
//src��CV_U16C1��ʽͼ��
//return�����������ͼ��
cv::Mat PCLConvert::undistImg(cv::Mat src)
{
	cv::Mat dst;

	//�ڲξ���
	cv::Mat cameraMatrix = cv::Mat::eye(3, 3, CV_64F);		//3*3��λ����
	cameraMatrix.at<double>(0, 0) = fx;
	cameraMatrix.at<double>(0, 1) = 0;
	cameraMatrix.at<double>(0, 2) = cx;
	cameraMatrix.at<double>(1, 1) = fy;
	cameraMatrix.at<double>(1, 2) = cy;
	cameraMatrix.at<double>(2, 2) = 1;

	//�������
	cv::Mat distCoeffs = cv::Mat::zeros(5, 1, CV_64F);		//5*1ȫ0����
	distCoeffs.at<double>(0, 0) = k1;
	distCoeffs.at<double>(1, 0) = k2;
	distCoeffs.at<double>(2, 0) = p1;
	distCoeffs.at<double>(3, 0) = p2;
	distCoeffs.at<double>(4, 0) = k3;

	cv::Size imageSize = src.size();
	cv::Mat map1, map2;

	//����1������ڲξ���
	//����2���������
	//����3����ѡ���룬��һ�͵ڶ��������֮�����ת����
	//����4��У�����3X3�������
	//����5����ʧ��ͼ��ߴ�
	//����6��map1�������ͣ�CV_32FC1��CV_16SC2
	//����7��8�����X/Y������ӳ�����
	initUndistortRectifyMap(cameraMatrix, distCoeffs, cv::Mat(), cameraMatrix, imageSize, CV_32FC1, map1, map2);	//�������ӳ��
	//����1������ԭʼͼ��
	//����2�����ͼ��
	//����3��4��X\Y������ӳ��
	//����5��ͼ��Ĳ�ֵ��ʽ
	//����6���߽���䷽ʽ
	remap(src, dst, map1, map2, cv::INTER_NEAREST);

	return dst.clone();
}

//���������ͼ���˲�
//src�����˲�ͼ��CV_16UC1
//return���˲���ͼ��
cv::Mat PCLConvert::filterImg(cv::Mat src)
{
	cv::Mat rst = src.clone();
	//cv::medianBlur(src, rst, 5);		//��ֵ�˲�
	//cv::GaussianBlur(src, rst, cv::Size(3, 3), 0, 0);	//��˹�˲�
	for (int y = 0; y < src.size().height; y++)
	{
		for (int x = 0; x < src.size().width; x++)
		{
			if (y == 0 || y == src.size().height - 1 || x == 0 || x == src.size().width - 1)
			{
				rst.at<ushort>(y, x) = 0;
				continue;
			}

			//������Χ�ھ�
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

			//������Χ��Ч�������;�ֵ
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

			//������Χ�㶼����Ч��ģ������ֵ
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