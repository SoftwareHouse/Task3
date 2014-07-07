#include "Task3.h"

ConcreateBeIterator* ConcreateBeFile::CreateIterator()
{
	return new ConcreateBeIterator(*this);
}

void ConcreateBeFile::Open()
{
	string filename;

	cout << "请输入第二个文件的文件名:";
	cin >> filename;

	in.open(filename, ios::in);
}

void ConcreateBeFile::Close()
{
	in.close();
}