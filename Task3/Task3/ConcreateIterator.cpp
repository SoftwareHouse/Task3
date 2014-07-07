#include "Task3.h"

ConcreateIterator::ConcreateIterator(ConcreateFile ConFile)
{
	this->ConFile = ConFile;
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

