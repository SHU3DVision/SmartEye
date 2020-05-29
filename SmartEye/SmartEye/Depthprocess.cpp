#include"Depthprocess.h"

Imagedepthprocess::Imagedepthprocess()
{
	_matimg_short.create(Img_height, Img_width, CV_16UC1);
	 img_color.create(Img_height, Img_width, CV_8UC3);//构造RGB图像
	 _matimg_amp_short.create(Img_height, Img_width, CV_16UC1);
}
Imagedepthprocess::~Imagedepthprocess()
{

}
//深度数据处理
//返回：CV_U8C3 mat类型
Mat Imagedepthprocess::depthProcess()
{
	uint16_t fameDepthArray2[MAXLINE];
	uint16_t raw_dep;
	for (int j = 0; j < bytecount / 2; j++)
	{
		raw_dep = ptr_buf_unsigned[j * 2 + 1] * 256 + ptr_buf_unsigned[2 * j];
		//cout << raw_dep << " ";
		realindex = bytecount / 2 - (j / Img_width + 1) * Img_width + j % Img_width;   //镜像
		realrow = Img_height - 1 - j / Img_width;
		realcol = j % Img_width;
		fameDepthArray2[realindex] = raw_dep;

	}
	//滤波
	calibrate(fameDepthArray2);
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
			if (depth[i][j] > 30000)
			{
				_matimg_short.at<ushort>(i, j) = depth[i][j];
			}
			else
			{
				//计算偏移量
				if (depth[i][j] + offset < 0 && depth[i][j] + offset < 30000)
					_matimg_short.at<ushort>(i, j) = 0;
				else
					_matimg_short.at<ushort>(i, j) = depth[i][j] + offset;
			}
			

		}

	}

	//翻转图像
	if (isHorizontalFlip)
	{
		flip(_matimg_short, _matimg_short, 1);		//水平翻转图像
	}
	if (isVerticalFlip)
	{
		flip(_matimg_short, _matimg_short, 0);		//垂直翻转图像
	}

	setColorImage(_matimg_short, img_color,maxdepth,mindepth);
	saveImage(_matimg_short,"");

	return img_color.clone();
}

//信号强度数据处理
//返回：CV_U8C3 mat类型
cv::Mat Imagedepthprocess::ampProcess()
{
	uint16_t fameDepthArray2[MAXLINE];
	uint16_t raw_dep;
	for (int j = 0; j < bytecount / 2; j++)
	{
		raw_dep = ptr_amp_buf_unsigned[j * 2 + 1] * 256 + ptr_amp_buf_unsigned[2 * j];
		//cout << raw_dep << " ";
		realindex = bytecount / 2 - (j / Img_width + 1) * Img_width + j % Img_width;   //镜像
		realrow = Img_height - 1 - j / Img_width;
		realcol = j % Img_width;
		fameDepthArray2[realindex] = raw_dep;

	}
	//滤波
	calibrate(fameDepthArray2);
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
			if (depth[i][j] > 2895)		
				_matimg_amp_short.at<ushort>(i, j) = 2895;		//从官方工程中看出，最大是2895，具体原因不详
			else
				_matimg_amp_short.at<ushort>(i, j) = depth[i][j];
		}

	}

	//翻转图像
	if (isHorizontalFlip)
	{
		flip(_matimg_amp_short, _matimg_amp_short, 1);		//水平翻转图像
	}
	if (isVerticalFlip)
	{
		flip(_matimg_amp_short, _matimg_amp_short, 0);		//垂直翻转图像
	}

	setColorImage(_matimg_amp_short, _matimg_amp_color, 2895, 0, 1);
	saveImage(_matimg_amp_short, "amp_", 1);

	return _matimg_amp_color.clone();		//返回彩色图
}


//获取信号强度数据
//返回：Mat类型
Mat Imagedepthprocess::getAmp()
{
	return _matimg_amp_short.clone();
}

//获取深度数据
//返回：Mat类型
Mat Imagedepthprocess::getDepth()
{
	return _matimg_short.clone();
}
//滤波
//输入：图像信息的指针
void Imagedepthprocess::calibrate(ushort *img)
{
	//均值滤波
	imageAverageEightConnectivity(img);
	//温度矫正
	//calculationCorrectDRNU(img);
	//深度补偿
	calculationAddOffset(img);
}
//八均值滤波
//输入： 深度图像指针
void  Imagedepthprocess::imageAverageEightConnectivity(ushort *depthdata)
{
	int pixelCounter;
	int nCols = 320;
	int nRowsPerHalf = 120;
	int size = 320 * 240;
	ushort actualFrame[MAX_NUM_PIX];
	int i, j, index;
	int pixdata;
	memcpy(actualFrame, depthdata, size * sizeof(ushort));
	// up side
	// dowm side
	// left side and right side
	// normal part
	for (i = 1; i < 239; i++) {
		for (j = 1; j < 319; j++){
			index = i * 320 + j;
			pixelCounter = 0;
			pixdata = 0;

			ushort temp = 0;				//记录无效点类型

			if (actualFrame[index] < 30000) {
				pixelCounter++;
				pixdata += actualFrame[index];
			}
			else
				temp = actualFrame[index];
			if (actualFrame[index - 1]  < 30000) {   // left
				pixdata += actualFrame[index - 1];
				pixelCounter++;
			}
			else 
				temp = actualFrame[index - 1];
			if (actualFrame[index + 1]  < 30000) {   // right
				pixdata += actualFrame[index + 1];
				pixelCounter++;
			}
			else 
				temp = actualFrame[index + 1];
			if (actualFrame[index - 321]  < 30000) {   // left up
				pixdata += actualFrame[index - 321];
				pixelCounter++;
			}
			else 
				temp = actualFrame[index - 321];
			if (actualFrame[index - 320]  < 30000) {   // up
				pixdata += actualFrame[index - 320];
				pixelCounter++;
			}
			else 
				temp = actualFrame[index - 320];
			if (actualFrame[index - 319]  < 30000) {   // right up
				pixdata += actualFrame[index - 319];
				pixelCounter++;
			}
			else 
				temp = actualFrame[index -319];
			if (actualFrame[index + 319]  < 30000) {   // left down
				pixdata += actualFrame[index - 321];
				pixelCounter++;
			}
			else 
				temp = actualFrame[index + 319];
			if (actualFrame[index + 320]  < 30000) {   // down
				pixdata += actualFrame[index - 320];
				pixelCounter++;
			}
			else 
				temp = actualFrame[index + 320];
			if (actualFrame[index + 321]  < 30000) {   // right down
				pixdata += actualFrame[index - 319];
				pixelCounter++;
			}
			else 
				temp = actualFrame[index + 321];
			//如果周围有效数据小于6记为无效点
			if (pixelCounter < 6) {
				//无效点
				*(depthdata + index) = temp;
			}
			else {
				*(depthdata + index) = pixdata / pixelCounter;
			}
		}
	}

}
//深度补偿
//输入：图像信息指针
void  Imagedepthprocess::calculationAddOffset(ushort *img)
{
	int offset = 0;
	uint16_t maxDistanceCM = 0;
	int l = 0;
	offset = OFFSET_PHASE_DEFAULT;
	uint16_t val;
	uint16_t *pMem = img;
	int numPix = 320 * 240;

	for (l = 0; l<numPix; l++){
		val = pMem[l];
		if (val < 30000) { //if not low amplitude, not saturated and not  adc overflow
			pMem[l] = (val + offset) % MAX_DIST_VALUE;
		}
	}
}
//温度校正
//输入：图像信息指针
//返回：0
int Imagedepthprocess::calculationCorrectDRNU(ushort *img)
{
	//int		gTempCal_Temp = 0;
	//double	gStepCalMM = 0;

	//int i, x, y, l;
	//double dist, tempDiff = 0;
	//int offset = 0;
	////printf("gOffsetDRNU = %d\n", offset);  //w
	//uint16_t maxDistanceMM = 150000000 / 12000;
	//double stepLSB = gStepCalMM * MAX_PHASE / maxDistanceMM;
	////printf("stepLSB = %2.4f\n", stepLSB);  //w

	//uint16_t *pMem = img;
	//int width = 320;
	//int height = 240;
	//tempDiff = realTempChip - gTempCal_Temp;
	//for (l = 0, y = 0; y< height; y++){
	//	for (x = 0; x < width; x++, l++){
	//		dist = pMem[l];

	//		if (dist < LOW_AMPLITUDE){	//correct if not saturated
	//			dist -= offset;

	//			if (dist<0)	//if phase jump
	//				dist += MAX_DIST_VALUE;

	//			i = (int)(round(dist / stepLSB));

	//			if (i<0) i = 0;
	//			else if (i >= 50) i = 49;

	//			dist = (double)pMem[l] - drnuLut[i][y][x];

	//			dist -= tempDiff * 3.12262;	// 0.312262 = 15.6131 / 50

	//			pMem[l] = (uint16_t)round(dist);

	//		}	//end if LOW_AMPLITUDE
	//	}	//end width
	//}	//end height
	////printf(" pMem = %d, %d, %d\n", pMem[1300], pMem[1301], pMem[1302]);
	return 0;
}
//设置伪彩色参数
//输入： src_img CV_16U图像
//输入： rst_img CV_8UC3转换后的彩色图像
//输入： max 输入图像最大值，供压缩参考
//输入： min 输入图像最小值，供压缩参考
//输入： flag	0 由蓝向红渐变
//				1 由红向蓝渐变
void Imagedepthprocess::setColorImage(Mat &src_img, Mat &rst_img, int max, int min, int flag)
{
	rst_img.create(Img_height, Img_width, CV_8UC3);//构造RGB图像
	Mat _matimg_show;
	_matimg_show.create(Img_height, Img_width, CV_16UC1);
	Mat depthzip = src_img.clone();
	double interdepth = 894.0 / (max - min);
	//距离压缩成0到255空间
	for (int i = 0; i < 240; i++)
	{
		for (int j = 0; j < 320; j++)
		{
			ushort LOW_AMPLITUDE = LOW_AMPLITUDE_V26;
			ushort OVER_EXPOSED = OVER_EXPOSED_V26;
			switch (version/100)	//只判断前两位版本号
			{
			case 206: LOW_AMPLITUDE = LOW_AMPLITUDE_V26; OVER_EXPOSED = OVER_EXPOSED_V26; break;
			case 212: LOW_AMPLITUDE = LOW_AMPLITUDE_V212; OVER_EXPOSED = OVER_EXPOSED_V212; break;
			default:
				break;
			}
			if (depthzip.at<ushort>(i, j) == LOW_AMPLITUDE)
			{
				//无效点
				IMG_B(rst_img, i, j) = 0;
				IMG_G(rst_img, i, j) = 0;
				IMG_R(rst_img, i, j) = 0;
				continue;
			}
			else if (depthzip.at<ushort>(i, j) == OVER_EXPOSED)
			{
				//过曝点
				IMG_B(rst_img, i, j) = 255;
				IMG_G(rst_img, i, j) = 14;
				IMG_R(rst_img, i, j) = 169;
				continue;
			}
			else if (depthzip.at<ushort>(i, j) < min)
			{
				//过小点
				IMG_B(rst_img, i, j) = 0;
				IMG_R(rst_img, i, j) = 0;
				IMG_G(rst_img, i, j) = 0;
				continue;
			}

			//正常点缩放
			if (depthzip.at<ushort>(i, j) > max)
			{
				depthzip.at<ushort>(i, j) = max;
			}
			else if (depthzip.at<ushort>(i, j) < min)
			{
				depthzip.at<ushort>(i, j) = min;
			}
			_matimg_show.at<ushort>(i, j) = (ushort)((depthzip.at<ushort>(i, j) - min)*interdepth);
			unsigned short img_tmp = _matimg_show.at<ushort>(i, j);
			if (flag)
				img_tmp = 894 - img_tmp;

			if (img_tmp < 64)
			{
				IMG_R(rst_img, i, j) = 191 + img_tmp;
				IMG_G(rst_img, i, j) = img_tmp;
				IMG_B(rst_img, i, j) = 0;
			}
			else if (img_tmp < 255)
			{
				IMG_R(rst_img, i, j) = 255;
				IMG_G(rst_img, i, j) = img_tmp;
				IMG_B(rst_img, i, j) = 0;
			}
			else if (img_tmp < 510)
			{
				img_tmp -= 255;
				IMG_B(rst_img, i, j) = img_tmp;
				IMG_G(rst_img, i, j) = 255;
				IMG_R(rst_img, i, j) = 255 - img_tmp;
			}
			else if (img_tmp < 765)
			{
				img_tmp -= 510;
				IMG_B(rst_img, i, j) = 255;
				IMG_G(rst_img, i, j) = 255 - img_tmp;
				IMG_R(rst_img, i, j) = 0;
			}
			else
			{
				img_tmp -= 765;
				IMG_B(rst_img, i, j) = 255 - img_tmp;
				IMG_G(rst_img, i, j) = 0;
				IMG_R(rst_img, i, j) = 0;
			}
		}
	}
	
}
//保存深度图
//输入： img 需要保存的图像
//输入： str 文将前缀，命名方式为str+number+.png命名
//输入： flag 是否增加编号
void Imagedepthprocess::saveImage(Mat img, string str,int flag)
{
	string fileassave = string(savestr.toLocal8Bit());
	if (saveimagestate == 1)
	{
		imwrite(fileassave + "/" + str + to_string(imagecount) + ".png", img);
		if (flag)
			imagecount++;
	}
	else
	{
		imagecount = 0;
	}
}