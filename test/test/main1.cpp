#include<iostream>
#include<string>
#include<vector>
using namespace std;

void screen(vector<char>&old, vector<char>&newo)
{
	int flag;
	for (int i = 0; i < old.size();i++)
	{
		flag = 1;
		for (int j = 0; (j<newo.size() && j < i); j++)
		{
			if (old[i] == newo[j])
			{
				flag = 0;
			}
		}
		if (flag)
		{
			newo.push_back(old[i]);
		}
	}

	for (auto &i : newo)
	{
		cout << i;
	}
	cout << endl;
}



int main()
{
	string tmp;
	getline(cin, tmp);

	vector<char>old;
	vector<char>newo;

	for (auto &i : tmp)
	{
		old.push_back(i);
	}

	screen(old, newo);

	system("pause");
	return 0;

}