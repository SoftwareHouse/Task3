#include "Task3.h"

int main()
{
	ConcreateIterator ConIter;
	ConcreateBeIterator ConBeIter;
	string first, other;
	char ch;

	cout << "------------------------------��ҵ���ƶȷ������--------------------------------" << endl;
	ConIter.ConFile.Open();
	ConBeIter.ConFile.Open();

	cout << "-------------------------------���ƶȷ���---------------------------------------" << endl;
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

	if(ConIter.Back_Match() <= 0.9)
	{
		cout << "���Ϊ:���岻����" << endl;
	}

	else if(ConIter.Back_Match() < 0.98)
	{
		cout << "���Ϊ:�����������" << endl;
	}

	else if(ConIter.Back_Match() >= 0.98)
	{
		cout << "���Ϊ:����ǳ�����" << endl;
	}

	ConIter.ConFile.Close();
	ConBeIter.ConFile.Close();
	ConIter.Init();

	cout << "�Ƿ������(y/n) ";
	cin >> ch;

	while(ch == 'y')
	{
		ConIter.ConFile.Open();
		ConBeIter.ConFile.Open();

	
		cout << "-------------------------------���ƶȷ���---------------------------------------" << endl;
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

		if(ConIter.Back_Match() <= 0.9)
		{
			cout << "���Ϊ:���岻����" << endl;
		}

		else if(ConIter.Back_Match() < 0.98)
		{
			cout << "���Ϊ:�����������" << endl;
		}

		else if(ConIter.Back_Match() >= 0.98)
		{
			cout << "���Ϊ:����ǳ�����" << endl;
		}


		ConIter.ConFile.Close();
		ConBeIter.ConFile.Close();
		ConIter.Init();

		cout << "�Ƿ������(y/n) ";
		cin >> ch;
	}

	return 0;
}