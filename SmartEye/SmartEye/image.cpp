#include "image.h"

Image::Image(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//设置图像放大缩小
	ui.imagelabel->setScaledContents(true);
}

Image::~Image()
{

}
//显示伪彩色图像
void Image::showColorImage()
{
	QImage img = QImage((uchar*)(showimage.data), showimage.cols, showimage.rows, QImage::Format_RGB888);
	QImage image2 = img.scaled(320, 240, Qt::KeepAspectRatio);
	ui.imagelabel->setAlignment(Qt::AlignCenter);		//居中显示
	ui.imagelabel->setPixmap(QPixmap::fromImage(image2));
}