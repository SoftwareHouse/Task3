#include "Task3.h"

ConcreateIterator* ConcreateFile::CreateIterator()
{
	return new ConcreateIterator(*this);
}

void ConcreateFile::Open()
{
	string filename;

	cout << "�������һ���ļ����ļ���:";
	cin >> filename;

	in.open(filename, ios::in);
}

void ConcreateFile::Close()
{
	in.close();
}

