#include "Task3.h"

void ConcreateBeFile::Open()
{
	string filename;

	cout << "������ڶ����ļ����ļ���:";
	cin >> filename;

	in.open(filename, ios::in);

	while(!in)
	{
		cerr << "�޷���!" << endl;
		cout << "������ڶ����ļ����ļ���:";
		cin >> filename;

		in.open(filename, ios::in);
	}
}

void ConcreateBeFile::Close()
{
	in.close();
}