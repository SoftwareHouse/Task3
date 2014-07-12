#include "Task3.h"

void ConcreateBeFile::Open()
{
	string filename;

	cout << "请输入第二个文件的文件名:";
	cin >> filename;

	in.open(filename, ios::in);

	while(!in)
	{
		cerr << "无法打开!" << endl;
		cout << "请输入第二个文件的文件名:";
		cin >> filename;

		in.open(filename, ios::in);
	}
}

void ConcreateBeFile::Close()
{
	in.close();
}