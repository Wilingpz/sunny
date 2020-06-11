#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	int n;
	 (cin >> n)
	
		bool flag=true,flag1=true;
		vector<string>tmp(n);
		for (int i = 0; i < n; i++)
		{
			cin >> tmp[n];
		}
		for (int i = 1; i < n; i++)
		{
			if (tmp[i - 1].size() >= tmp[i].size())
			{
				flag = false;
			}
		}
		for (int i = 1; i < n; i++)
		{
			if (tmp[i - 1] >= tmp[i])
			{
				flag1 = false;
			}
		}
		if (flag1 && flag == true)
		{
			cout << "both" << endl;
		}
		else if (flag1 && flag == false)
		{
			cout << "none" << endl;
		}
		else if (!flag1 && flag == true)
		{
			cout << "lexicographically" << endl;
		}
		else if (flag1 && !flag == false)
		{
			cout << "lengths" << endl;
		}
	return 0;
}


#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<string> tmp(n);
	for (auto& str : tmp)
	{
		cin >> str;
	}
	bool flag = true, flag1 = true;
	// 这里要注意从i=1开始遍历，前后比较，比较长度
	for (int i = 1; i < tmp.size(); ++i)
	{
		if (tmp[i - 1].size() >= tmp[i].size())
		{
			flag = false;
			break;
		}
	}
	//比较ASCII码
	for (int i = 1; i < tmp.size(); ++i)
	{
		if (tmp[i - 1] >= tmp[i])
		{
			flag1 = false;
			break;
		}
	}
	if (flag&& flag1)
		cout << "both" << endl;
	else if (!flag&& flag1)
		cout << "lexicographically" << endl;
	else if (flag&& !flag1)
		cout << "lengths" << endl;
	else if (!flag&& !flag1)
		cout << "none" << endl;
	return 0;
}