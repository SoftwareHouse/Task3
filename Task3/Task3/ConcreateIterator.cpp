#include "Task3.h"

ConcreateIterator::ConcreateIterator()
{
	prematch = 0;
	dis_min = -1;
	isFirst = true;
	Times = 0;
	match = 0;
}

bool ConcreateIterator::IsEnd()
{
	if(this->ConFile.in.eof())
	{
		return true;
	}
	else
	{
		return false;
	}
}

//空格行不在比较范围之内
string ConcreateIterator::Next()
{
	string line;
	char ch;
	bool flag = false;
	isFirst = true;

	ConFile.in.get(ch);

	while((ch == ' ' || ch == '\n') && !ConFile.in.eof())
	{
		ConFile.in.get(ch);
	}

	do
	{
		while(ch != '\n' && !ConFile.in.eof())
		{
			line += ch;
			if(ch != ' ')
			{
				flag = true;
			}
			ConFile.in.get(ch);
		}
	}while(!flag);

	return line;
}

string ConcreateIterator::First()
{
	string line;
	char ch;
	bool flag = false;
	isFirst = true;

	ConFile.in.get(ch);

	while(ch == '\n' && !ConFile.in.eof())
	{
		ConFile.in.get(ch);
	}

	do
	{
		while(ch != '\n' && !ConFile.in.eof())
		{
			line += ch;
			if(ch != ' ')
			{
				flag = true;
			}
			ConFile.in.get(ch);
		}
	}while(!flag);

	return line;
}

//编辑距离算法
void ConcreateIterator::Compare(string str, string Bestr)
{
	int max1 = str.length();
	int max2 = Bestr.length();

	int **ptr = new int*[max1+1];
	//创建距离表格
	for(int i = 0; i < max1+1; i++)
	{
		ptr[i] = new int[max2+1];
	}

	for(int i = 0; i < max1+1; i++)
	{
		ptr[i][0] = i;
	}

	for(int i = 0; i < max2+1; i++)
	{
		ptr[0][i] = i;
	}

	for(int i = 1; i < max1+1; i++)
	{
		for(int j = 1; j < max2+1; j++)
		{
			int temp, d;

			temp = min(ptr[i-1][j]+1, ptr[i][j-1]+1);
			if(str[i-1] == Bestr[j-1])
			{
				d = 0;
			}
			else
			{
				d = 1;
			}

			ptr[i][j] = min(temp, ptr[i-1][j-1]+d);
		}
	}

	int dis = ptr[max1][max2];

	//求出每一行与另一文件中每一行编辑距离的最小值
	if(dis_min == -1)
	{
		dis_min = dis;
		isFirst = false;
		tmp_max = max(max1, max2);
	}
	else if(isFirst)
	{
		Times++;
		cout << "第" << Times << "行和文件二的编辑距离最小值为" << dis_min << endl;
		match = 1-(double)dis_min/(double)(tmp_max);
		cout << "第" << Times << "行和文件二的相似度为" << match << endl;

		if(match <= 0.9)
		{
			cout << "结果为:部分不相似" << endl;
		}

		else if(match < 0.98)
		{
			cout << "结果为:部分基本相似" << endl;
		}

		else if(match >= 0.98)
		{
			cout << "结果为:部分非常相似" << endl;
		}

		cout << endl;

		if(Times == 1)
		{
			prematch = 1-(double)dis_min/(double)(tmp_max);
		}
		else
		{
			prematch += 1-(double)dis_min/(double)(tmp_max);
			prematch /= 2;
		}
		dis_min = dis;
		isFirst = false;
	}

	else if(dis < dis_min)
	{
		dis_min = dis;
		tmp_max = max(max1, max2);
	}


	for(int i = 0 ; i< max1+1; i++)
	{
		delete []ptr[i];
		ptr[i] = NULL;
	}

	delete [] ptr;
	ptr = NULL;
}

bool ConcreateIterator::IsEmpty()
{
	if(isFirst)
	{
		return true;
	}
	else
	{
		return false;
	}
}

double ConcreateIterator::Back_Match()
{
	return prematch;
}

void ConcreateIterator::Init()
{
	Times = 0;
}