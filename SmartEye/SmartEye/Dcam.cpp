#pragma once
#include"Dcam.h"



uint16_t fameDepthArray2[MAXLINE];

void Camdepthprocess::depthprocess()
{
	for (int j = 0; j < bytecount / 2; j++)
	{
		raw_dep = ptr_buf_unsigned[j * 2 + 1] * 256 + ptr_buf_unsigned[2 * j];
		//cout << raw_dep << " ";
		realindex = bytecount / 2 - (j / Img_width + 1) * Img_width + j % Img_width;   //¾µÏñ
		realrow = Img_height - 1 - j / Img_width;
		realcol = j % Img_width;
		fameDepthArray2[realindex] = raw_dep;

		//cout << fameDepthArray2[j] << " ";
	}
	uint16_t depth[240][320];
	for (int i = 0; i < 240; i++)
	{
		for (int j = 0; j < 320; j++)
		{
			depth[i][j] = fameDepthArray2[i * 320 + j];
		}
	}
	src_1.create(Img_height, Img_width, CV_16UC1);
	imshowsrc.create(Img_height, Img_width, CV_8UC1);

	for (int i = 0; i < 240; i++)
	{
		for (int j = 0; j < 320; j++)
		{
		  src_1.at<ushort>(i, j) = depth[i][j];

		}

	}
	for (int i = 0; i < 240; i++)
	{
		for (int j = 0; j < 320; j++)
		{
			imshowsrc.at<uchar>(i, j) = 255 - src_1.at<ushort>(i, j) * 25 / 3000;
			//cout << src2.at<uchar>(i, j) << endl;
		}

	}
}
