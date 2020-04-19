//单词倒排
#if 0
#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main()
{
	string str;
	while (getline(cin, str))
	{
		stack<char> res;
		int pos1 = 0;
		int pos2 = 0;
		{
			for (int i = 0; i < str.length(); i++)
			{
				if (!((str[i] >= 'A'&&str[i] <= 'Z')
					||(str[i] >= 'a'&&str[i] <= 'z')))
				{
					pos2 = i;
					for (int j = pos1; j <= pos2; j++)
					{
						res.push(str[j]);
					}
					pos1 = pos2;
				}
			}
			while (!res.empty())
			{
				res.pop();//看不到结果，不可以
			}
		}
	}
	return 0;
}
#else
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	string str;
	while (getline(cin, str))
	{
		vector<string>res;
		string temp;
		for (int i = 0; i < str.length(); i++)
		{
			if (!((str[i] >= 'A'&&str[i] <= 'Z')
				|| (str[i] >= 'a'&&str[i] <= 'z')))
			{
				temp += str[i];
			}
			else
			{
				if (temp.size()>0)
				{
					res.push_back(temp);
					temp.clear();
				}
			}
		}
		reverse(temp.begin(),temp.end());
		for (int i = 0; i < temp.size();i++)
		{
			cout << temp[i];
			if (i + 1 != temp.size())
			{
				cout << " ";
			}
		}
	}
	return 0;
}




#endif