#include "Task3.h"

void ConcreateFile::Open()
{
	string filename;

	cout << "�������һ���ļ����ļ���:";
	cin >> filename;

	in.open(filename, ios::in);

	while(!in)
	{
		cerr << "�޷���!" << endl;
		cout << "�������һ���ļ����ļ���:";
		cin >> filename;

		in.open(filename, ios::in);
	}
}

void ConcreateFile::Close()
{
	in.close();
}

