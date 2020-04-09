//得到一个字符串的所有子串
//最长公共（子串）序列（适合较短长度）
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

# if 0
int main()
{
	string str;
	while (cin >> str)
	{
		for (int i = 0; i < str.size(); i++)
		{
			for (int j = i; j < str.size(); j++)
			{
				cout << str.substr(i, j) << endl;
			}
		}
	}
	system("pause");
	return 0;
}
#else


int main()
{
	string m, n;
	while (cin >> m >> n)
	{
		if (m.length() > n.length())
		{
			string temp;
			temp = m;
			m = n;
			n = temp;
		}
		vector<string>temp;
		int maxlenth = 0;
		//1、得到字符串n的所有字串，用vector<string>存起来
		for (int i = 0; i < n.size(); i++)
		{
			for (int j = i; j < n.size(); j++)
			{
				temp.push_back(n.substr(i, j));
			}
		}
		//2、用find函数找它是否存在m中，存在则记录它的串和长度
		for (auto &i : temp)
		{
			if ((m.find(i) != string::npos) && (i.length()>maxlenth))
			{
					maxlenth = i.length();	
			}
		}
		//3、输出
		cout <<maxlenth<< endl;
	}
	system("pause");
	return 0;
}
#endif

