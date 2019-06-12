#include "PLinBootloader.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	PLinBootloader w;
	w.show();
	return a.exec();
}
 