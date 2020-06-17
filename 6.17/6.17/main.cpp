#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s1;
	while (getline(cin, s1))
	{
		int count = 0;
		for (int i = 0; i < s1.size();i++)
		{
			if (s1[i] == ' ')
			{
				count++;
			}
			if (s1[i] =='"')//双引号里面的空格不用算
			{
				do
				{
					i++;
				} while (s1[i] != '"');
			}
		}
		cout << count + 1 << endl;//实际count比算的count空格多一个
		int flag = 1;//通过flag标识确定空格是双引号里面的还是外面的
		for (int i = 0; i < s1.size(); i++)
		{
			//考虑打印,有双引号需要打印空格
			if (s1[i] == '"')
			{
				flag ^= 1;
			}
			if (s1[i] != ' ' && s1[i] != '"')
			{
				cout << s1[i];
			}
			if (s1[i] == ' ' && flag == 0)
			{
				cout << s1[i];
			}
			if (s1[i] == ' ' && flag != 0)
			{
				cout << endl;
			}
		}

		return 0;
	}
}