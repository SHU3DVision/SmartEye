#include "smarteye.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	SmartEye w;
	w.show();
	return a.exec();
}
