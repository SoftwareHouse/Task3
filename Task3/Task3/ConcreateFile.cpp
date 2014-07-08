#include "Task3.h"

ConcreateIterator* ConcreateFile::CreateIterator()
{
	return new ConcreateIterator(*this);
}

void ConcreateFile::Open()
{
	string filename;

	cout << "请输入第一个文件的文件名:";
	cin >> filename;

	in.open(filename, ios::in);
}

void ConcreateFile::Close()
{
	in.close();
}

