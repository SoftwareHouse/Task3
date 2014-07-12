#include <QtWidgets\QtWidgets>
#include "ui_MatchWindow.h"

class MatchWindow :public QMainWindow, public Ui_MatchWindow
{
	Q_OBJECT;

public:
	MatchWindow();
	void Compare(QString str,QString Bestr);

private:
	QString filename1, filename2;
	int dis_min;
	bool isFirst;
	int tmp_max;
	double prematch;
	int Times;
	double match;

private slots:
	void OpenFile1();
	void OpenFile2();
	void Operator();
};