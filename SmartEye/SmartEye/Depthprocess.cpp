#include"Depthprocess.h"
uint16_t fameDepthArray2[MAXLINE];
Imagedepthprocess::Imagedepthprocess()
{
	 _matimg_short.create(240, 320, CV_16UC1);
	 _matimg_show.create(240, 320, CV_8UC1);
}
Imagedepthprocess::~Imagedepthprocess()
{

}
//深度数据处理
//返回：mat类型
Mat Imagedepthprocess::depthProcess()
{
	for (int j = 0; j < bytecount / 2; j++)
	{
		raw_dep = ptr_buf_unsigned[j * 2 + 1] * 256 + ptr_buf_unsigned[2 * j];
		//cout << raw_dep << " ";
		realindex = bytecount / 2 - (j / Img_width + 1) * Img_width + j % Img_width;   //镜像
		realrow = Img_height - 1 - j / Img_width;
		realcol = j % Img_width;
		fameDepthArray2[realindex] = raw_dep;

	}
	uint16_t depth[240][320];
	for (int i = 0; i < 240; i++)
	{
		for (int j = 0; j < 320; j++)
		{
			depth[i][j] = fameDepthArray2[i * 320 + j];
		}
	}
	//16bit原始数据
	for (int i = 0; i < 240; i++)
	{
		for (int j = 0; j < 320; j++)
		{
			_matimg_short.at<ushort>(i, j) = depth[i][j];

		}

	}
	//8bit显示数据
	for (int i = 0; i < 240; i++)
	{
		for (int j = 0; j < 320; j++)
		{
			_matimg_show.at<uchar>(i, j) = 255 - _matimg_short.at<ushort>(i, j) * 25 / 3000;
			//cout << src2.at<uchar>(i, j) << endl;
		}

	}
	return _matimg_show.clone();
}
//获取深度数据
//返回：Mat类型
Mat Imagedepthprocess::getDepth()
{
	return _matimg_show.clone();
}