#include "MatchWindow.h"
#include <QApplication>
#include <QTextCodec>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	MatchWindow w;

	w.show();

	a.exec();
}