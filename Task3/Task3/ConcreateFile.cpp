#include "Task3.h"

void ConcreateFile::Open()
{
	string filename;

	cout << "请输入第一个文件的文件名:";
	cin >> filename;

	in.open(filename, ios::in);

	while(!in)
	{
		cerr << "无法打开!" << endl;
		cout << "请输入第一个文件的文件名:";
		cin >> filename;

		in.open(filename, ios::in);
	}
}

void ConcreateFile::Close()
{
	in.close();
}

