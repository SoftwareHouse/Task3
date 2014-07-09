#ifndef _TASK3
#define _TASK3
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class AbstractIterator
{
public:
	virtual string Next()=0;
	virtual string First()=0;
	virtual bool IsEnd()=0;
};

class AbstractFile
{ 
public:
	virtual void Open()=0;
	virtual void Close()=0;
};

class ConcreateFile:public AbstractFile
{
public:
	ifstream in;
public:
	void Open();
	void Close();
};

class ConcreateBeFile:public AbstractFile
{
public:
	ifstream in;
public:
	void Open();
	void Close();
};

class ConcreateIterator:public AbstractIterator
{
private:
	double prematch;
	int tmp_max;
	bool isFirst;
	int Times;
	int dis_min;
	double match;
public:
	ConcreateFile ConFile;

public:
	ConcreateIterator();
	string Next();
	string First();
	bool IsEnd();
	void Compare(string str, string Bestr);
	bool IsEmpty();
	double Back_Match();
	void Init();
};

class ConcreateBeIterator:public AbstractIterator
{
private:
	double prematch;
public:
	ConcreateBeFile ConFile;

public:
	ConcreateBeIterator();
	string Next();
	string First();
	bool IsEnd();
};
#endif // !_TASK3
