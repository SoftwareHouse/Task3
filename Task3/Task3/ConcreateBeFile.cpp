#include "Task3.h"

ConcreateBeIterator* ConcreateBeFile::CreateIterator()
{
	return new ConcreateBeIterator(*this);
}

void ConcreateBeFile::Open()
{
	string filename;

	cout << "������ڶ����ļ����ļ���:";
	cin >> filename;

	in.open(filename, ios::in);
}

void ConcreateBeFile::Close()
{
	in.close();
}