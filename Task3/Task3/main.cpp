#include "Task3.h"

int main()
{
	ConcreateIterator ConIter;
	ConcreateBeIterator ConBeIter;
	string first, other;
	char ch;

	ConIter.ConFile.Open();
	ConBeIter.ConFile.Open();

	
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

	cout << "���ƶ�Ϊ:" << ConIter.Back_Match()*100 << "%"<< endl;

	ConIter.ConFile.Close();
	ConBeIter.ConFile.Close();

	cout << "�Ƿ������(y/n) ";
	cin >> ch;

	while(ch == 'y')
	{
		ConIter.ConFile.Open();
		ConBeIter.ConFile.Open();

	
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

		cout << "���ƶ�Ϊ:" << ConIter.Back_Match()*100 << "%"<< endl;

		ConIter.ConFile.Close();
		ConBeIter.ConFile.Close();

		cout << "�Ƿ������(y\n) ";
		cin >> ch;
	}

	return 0;
}