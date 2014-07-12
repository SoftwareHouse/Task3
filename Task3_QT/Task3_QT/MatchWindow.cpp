#include "MatchWindow.h"
#include <QtGui/QtGui>
#include <QFile>

MatchWindow::MatchWindow()
{
	setupUi(this);

	connect(File1Button, SIGNAL(clicked()), this, SLOT(OpenFile1()));
	connect(File2Button, SIGNAL(clicked()), this, SLOT(OpenFile2()));
	connect(StartButton, SIGNAL(clicked()), this, SLOT(Operator()));
}

void MatchWindow::OpenFile1()
{
	filename1 = QFileDialog::getOpenFileName(this, tr("Open File1"), ".", tr("All File(*.*)"));

	File1label->setText(filename1);
	textEdit->clear();

	dis_min = -1;
	isFirst = true;
	prematch = 0;
	tmp_max = 0;
	Times = 0;
}

void MatchWindow::OpenFile2()
{
	filename2 = QFileDialog::getOpenFileName(this, tr("Open File2"), ".", tr("All File(*.*)"));

	File2label->setText(filename2);
}

void MatchWindow::Operator()
{
	bool isBlank1, isBlank2;
	textEdit->clear();
	Times = 0;

	QFile file1(filename1), file2(filename2);

	if (!file1.open(QIODevice::ReadOnly))
	{
		qDebug() << "Cannot open the file1" << endl;
	}

	if (!file2.open(QIODevice::ReadOnly))
	{
		qDebug() << "Cannot open the file2" << endl;
	}

	while (!file1.atEnd())
	{
		QString str, Bestr;

		isBlank1 = true;
		isFirst = true;

		do
		{
			str = file1.readLine();

			for (int i = 0; i < str.size(); i++)
			{
				if (str[0] == '\r' && str[1] == '\n')
				{
					isBlank1 = true;
					continue;
				}
				if (str[i] != ' ')
				{
					isBlank1 = false;
					break;
				}
			}
		} while (isBlank1);

		file2.seek(0);

		while (!file2.atEnd())
		{
			isBlank2 = true;

			do
			{
				Bestr = file2.readLine();

				for (int i = 0; i < Bestr.size(); i++)
				{
					if (Bestr[0] == '\r' && Bestr[1] == '\n')
					{
						isBlank2 = true;
						continue;
					}
					if (Bestr[i] != ' ')
					{
						isBlank2 = false;
						break;
					}
				}
			} while (isBlank2);

			Compare(str, Bestr);
		}
	}

	Result1lineEdit->setText(QString::number(prematch*100)+"%");

	if (prematch <= 0.9)
	{
		Result2lineEdit->setText(QString::fromLocal8Bit("结果为:部分不相似"));
	}

	else if (prematch < 0.98)
	{
		Result2lineEdit->setText(QString::fromLocal8Bit("结果为:部分基本相似"));
	}

	else if (prematch >= 0.98)
	{
		Result2lineEdit->setText(QString::fromLocal8Bit("结果为:部分非常相似"));
	}

	file1.close();
	file2.close();
}

void MatchWindow::Compare(QString str, QString Bestr)
{
	int max1 = str.length();
	int max2 = Bestr.length();

	int **ptr = new int*[max1 + 1];
	//创建距离表格
	for (int i = 0; i < max1 + 1; i++)
	{
		ptr[i] = new int[max2 + 1];
	}

	for (int i = 0; i < max1 + 1; i++)
	{
		ptr[i][0] = i;
	}

	for (int i = 0; i < max2 + 1; i++)
	{
		ptr[0][i] = i;
	}

	for (int i = 1; i < max1 + 1; i++)
	{
		for (int j = 1; j < max2 + 1; j++)
		{
			int temp, d;

			temp = qMin(ptr[i - 1][j] + 1, ptr[i][j - 1] + 1);
			if (str[i - 1] == Bestr[j - 1])
			{
				d = 0;
			}
			else
			{
				d = 1;
			}

			ptr[i][j] = qMin(temp, ptr[i - 1][j - 1] + d);
		}
	}

	int dis = ptr[max1][max2];

	//求出每一行与另一文件中每一行编辑距离的最小值
	if (dis_min == -1)
	{
		dis_min = dis;
		isFirst = false;
		tmp_max = qMax(max1, max2);
	}
	else if (isFirst)
	{
		Times++;

		if (Times == 1)
		{
			textEdit->setText(QString::fromLocal8Bit("第%1行和文件二的编辑距离最小值为%2").arg(Times).arg(dis_min));
		}
		else
		{
			textEdit->append(QString::fromLocal8Bit("第%1行和文件二的编辑距离最小值为%2").arg(Times).arg(dis_min));
		}
		match = 1 - (double)dis_min / (double)(tmp_max);
		textEdit->append(QString::fromLocal8Bit("第%1行和文件二的相似度为%2").arg(Times).arg(match));

		if (match <= 0.9)
		{
			textEdit->append(QString::fromLocal8Bit("结果为:部分不相似"));
		}

		else if (match < 0.98)
		{
			textEdit->append(QString::fromLocal8Bit("结果为:部分基本相似"));
		}

		else if (match >= 0.98)
		{
			textEdit->append(QString::fromLocal8Bit("结果为:部分非常相似"));
		}


		if (Times == 1)
		{
			prematch = 1 - (double)dis_min / (double)(tmp_max);
		}
		else
		{
			prematch += 1 - (double)dis_min / (double)(tmp_max);
			prematch /= 2;
		}
		dis_min = dis;
		isFirst = false;
	}

	else if (dis < dis_min)
	{
		dis_min = dis;
		tmp_max = qMax(max1, max2);
	}


	for (int i = 0; i < max1 + 1; i++)
	{
		delete[]ptr[i];
		ptr[i] = NULL;
	}

	delete[] ptr;
	ptr = NULL;
}