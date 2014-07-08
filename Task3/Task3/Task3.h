#ifndef _TASK3
#define _TASK3
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class AbstractIterator
{
public:
	virtual string Next();
	virtual string First();
	virtual bool IsEnd();
};

class AbstractFile
{ 
public:
	virtual void Open();
	virtual void Close();
};

class ConcreateFile:public AbstractFile
{
public:
	ifstream in;
public:
	ConcreateIterator* CreateIterator();
	void Open();
	void Close();
};

class ConcreateBeFile:public AbstractFile
{
public:
	ifstream in;
public:
	ConcreateBeIterator* CreateIterator();
	void Open();
	void Close();
};

class ConcreateIterator:public AbstractIterator
{
private:
	double prematch;
	ConcreateFile ConFile;

public:
	ConcreateIterator(ConcreateFile ConFile);
	string Next();
	string First();
	bool IsEnd();
};

class ConcreateBeIterator:public AbstractIterator
{
private:
	double prematch;
	ConcreateBeFile ConFile;

public:
	ConcreateBeIterator(ConcreateBeFile ConFile);
	string Next();
	string First();
	bool IsEnd();
};
#endif // !_TASK3
