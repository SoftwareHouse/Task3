#include "Task3.h"

ConcreateBeIterator::ConcreateBeIterator()
{
	prematch = 0;
}

bool ConcreateBeIterator::IsEnd()
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
string ConcreateBeIterator::Next()
{
	string line;
	char ch;
	bool flag = false;

	ConFile.in.get(ch);

	while((ch == ' ' || ch == '\n') && !ConFile.in.eof())
	{
		ConFile.in.get(ch);
	}

	if(ConFile.in.eof())
	{
		flag = true;
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

string ConcreateBeIterator::First()
{
	string line;
	char ch;
	bool flag = false;

	ConFile.in.get(ch);

	while(ch == '\n' && !ConFile.in.eof())
	{
		ConFile.in.get(ch);
	}

	if(ConFile.in.eof())
	{
		flag = true;
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

