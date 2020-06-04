#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main1()
{
	string s1;
	while (getline(cin, s1))
	{
		reverse(s1.begin(), s1.end());//将整个句子逆置
		auto start = s1.begin();
		for (int i = 0; i <= s1.size(); i++)
		{
			if (s1[i] == ' ')
			{
				auto end = s1.begin() + i;
				reverse(start, end);//将每个单词逆置回来
				start = end + 1;
			}
			if(s1.begin() + i == s1.end())
			{
				reverse(start, s1.end());
			}
		}
		cout << s1 << endl;
	}
	system("pause");
	return 0;
}

//int main()
//{
//	string s;
//	// 注意这里要使用getline，cin>>s遇到空格就接收结束了
//	getline(cin, s);
//
//	// 翻转整个句子
//	reverse(s.begin(), s.end());
//	// 翻转单词
//	auto start = s.begin();
//	while (start != s.end())
//	{
//		auto end = start;
//		while (end != s.end() && *end != ' ')
//			end++;
//		reverse(start, end);
//		if (end != s.end())
//			start = end + 1;
//		else
//			start = end;
//	}
//	cout << s << endl;
//	return 0;
//}