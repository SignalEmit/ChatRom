#include "denglu.h"
#include <QtWidgets/QApplication>
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	denglu w;
	w.show();
	return a.exec();
}
