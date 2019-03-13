#include"TinySocket.h"
#include<opencv2\opencv.hpp>

#define   Img_width   (320)
#define   Img_height  (240)
using namespace cv;
class Camdepthprocess
{
 public:
	 void depthprocess();
	 void showImage();
	 Mat src_1;
	 Mat imshowsrc;
private:
	uint16_t raw_dep;
	int realindex, realrow, realcol;
	

};
