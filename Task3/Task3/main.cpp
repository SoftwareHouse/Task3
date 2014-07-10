#include "Task3.h"

int main()
{
	ConcreateIterator ConIter;
	ConcreateBeIterator ConBeIter;
	string first, other;
	char ch;

	cout << "------------------------------作业相似度分析软件--------------------------------" << endl;
	ConIter.ConFile.Open();
	ConBeIter.ConFile.Open();

	cout << "-------------------------------相似度分析---------------------------------------" << endl;
	while(!ConIter.IsEnd())
	{
		first = ConIter.Next();

		ConBeIter.ConFile.in.clear();
		ConBeIter.ConFile.in.seekg(0, ios_base::beg);
		while(!ConBeIter.IsEnd())
		{
			other = ConBeIter.Next();
			ConIter.Compare(first, other);
		}
	}

	cout << "相似度为:" << ConIter.Back_Match()*100 << "%"<< endl;

	if(ConIter.Back_Match() <= 0.9)
	{
		cout << "结果为:整体不相似" << endl;
	}

	else if(ConIter.Back_Match() < 0.98)
	{
		cout << "结果为:整体基本相似" << endl;
	}

	else if(ConIter.Back_Match() >= 0.98)
	{
		cout << "结果为:整体非常相似" << endl;
	}

	ConIter.ConFile.Close();
	ConBeIter.ConFile.Close();
	ConIter.Init();

	cout << "是否继续？(y/n) ";
	cin >> ch;

	while(ch == 'y')
	{
		ConIter.ConFile.Open();
		ConBeIter.ConFile.Open();

	
		cout << "-------------------------------相似度分析---------------------------------------" << endl;
		while(!ConIter.IsEnd())
		{
			first = ConIter.Next();
			ConBeIter.ConFile.in.clear();
			ConBeIter.ConFile.in.seekg(0, ios_base::beg);
			while(!ConBeIter.IsEnd())
			{
				other = ConBeIter.Next();
				ConIter.Compare(first, other);
			}
		}

		cout << "相似度为:" << ConIter.Back_Match()*100 << "%"<< endl;

		if(ConIter.Back_Match() <= 0.9)
		{
			cout << "结果为:整体不相似" << endl;
		}

		else if(ConIter.Back_Match() < 0.98)
		{
			cout << "结果为:整体基本相似" << endl;
		}

		else if(ConIter.Back_Match() >= 0.98)
		{
			cout << "结果为:整体非常相似" << endl;
		}


		ConIter.ConFile.Close();
		ConBeIter.ConFile.Close();
		ConIter.Init();

		cout << "是否继续？(y/n) ";
		cin >> ch;
	}

	return 0;
}