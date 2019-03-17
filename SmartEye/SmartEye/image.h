#ifndef IMAGE_H
#define IMAGE_H

#include <QWidget>
#include "ui_image.h"
#include<opencv2\opencv.hpp>

class Image : public QWidget
{
	Q_OBJECT

public:
	Image(QWidget *parent = 0);
	~Image();
	void showColorImage(); //»ñÈ¡²ÊÉ«Í¼Ïñ
	cv::Mat showimage;

private:
	Ui::Image ui;
};

#endif // IMAGE_H
