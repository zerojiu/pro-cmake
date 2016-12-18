#include "gui.h"
#include <QtWidgets//QApplication>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	pro::Gui gui;
	gui.show();

	return app.exec();
}