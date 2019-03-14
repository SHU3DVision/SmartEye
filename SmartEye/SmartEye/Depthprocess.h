#include <stdio.h>
#include<stdint.h>
#include<opencv2\opencv.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <string>
using namespace std;
using namespace cv;
#define bytecount 153600
#define   Img_width   (320)
#define   Img_height  (240)
#define MAXLINE 253600
class Imagedepthprocess
{
public:
	Imagedepthprocess();
	~Imagedepthprocess();
	cv::Mat depthprocess();
	unsigned char* ptr_buf_unsigned;
	cv::Mat src_1;
	cv::Mat imshowsrc;
	//void calibrate();
private:
	uint16_t raw_dep;
	int realindex, realrow, realcol;
};