#include "Task3.h"

ConcreateIterator::ConcreateIterator()
{
	prematch = 0;
	isFirst = true;
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

	ConFile.in.get(ch);

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

	ConFile.in.get(ch);

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

			temp = min(ptr[i-1][j], ptr[i][j-1]);
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

	if(isFirst)
	{
		prematch = 1-(double)dis/((double)max(max1, max2));
		isFirst = false;
	}
	else
	{
		prematch += 1-(double)dis/((double)max(max1, max2));
		prematch /= 2;
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