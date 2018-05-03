#include "motioncontrol2.h"
#include <QtWidgets/QApplication>
#include <qDebug>

int main(int argc, char *argv[])
{
	qDebug() << "TEST";


	QApplication a(argc, argv);
	motionControl2 w;
	w.show();
	return a.exec();
}
