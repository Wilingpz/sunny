//剪花布条（找第二个字符串在第一个字符串中出现了几次）
#include<iostream>
#include<string>
using namespace std;
int main1()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		int pos = 0;
		int count = 0;
		while ((pos = str1.find(str2, pos))!=string::npos)//find(要找的字符串，从哪个位置开始)
		{
			pos += str2.size();//找到这个位置后，从它的下一个位置开始
			count++;
		}
		cout << count << endl;
	}
	system("pause");
	return 0;
}