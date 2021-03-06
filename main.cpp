#include "mainwindow.h"
#include <QApplication>
#include <QtGlobal>
#include <iostream>

void customLogHandler(QtMsgType type, const QMessageLogContext &context,
		      const QString &msg)
{
// now output to debugger console
#ifdef Q_OS_WIN
//OutputDebugString(msg.toStdWString().c_str());
#else
	std::cerr << msg.toStdString() << std::endl;
#endif
}

int main(int argc, char *argv[])
{
	QApplication::setAttribute(Qt::AA_DisableHighDpiScaling);

	qInstallMessageHandler(&customLogHandler);

	QApplication a(argc, argv);
	MainWindow w;
	w.show();

	return a.exec();
}
