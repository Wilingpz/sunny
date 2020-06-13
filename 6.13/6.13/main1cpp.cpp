#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s1;
	getline(cin, s1);
	int sum = 0;
	//³¤¶È
	int len = 0;
	if (s1.size()>=0 && s1.size()<= 4)
	{
		len += 5;
	}
	else if (5 <= s1.size() && s1.size()<= 7)
	{
		len += 10;
	}
	else if (s1.size()>=8)
	{
		len += 25;
	}
	//×ÖÄ¸
	int sym = 0;
	int big = 0;
	int small = 0;
	for (auto &i : s1)
	{
		if (i >= 'a'&&i <= 'z')
		{
			small++;
		}
		else if (i >= 'A'&&i <= 'Z')
		{
			big++;
		}
	}
	if ((big + small) == 0)
	{
		sym += 0;
	}
	else if (big == s1.size() || small == s1.size())
	{
		sym += 10;
	}
	else if (big!=0 && small!=0)
	{
		sym += 20;
	}
	//Êý×Ö
	int num = 0;
	int tmp = 0;
	for (auto &i : s1)
	{
		if (isdigit(i))
		{
			tmp++;
		}
	}
	 if (tmp == 1)
	{
		num += 10;
	}
	else if (tmp==0)
	{
		num += 0;
	}
	else
	{
		num += 20;
	}
	//·ûºÅ£¨È¥³ý×ÖÄ¸¡¢Êý×Ö£©
	int f = 0;
	int k = 0;
	for (auto &i : s1)
	{
		if (!('a' <= i && i <= 'z') && !('A' <= i && i<= 'Z') && !(isdigit(i)))
		{
			k++;
		}
	}
	if (k == 0)
	{
		f += 0;
	}
	else if (k == 1)
	{
		f += 10;
	}
	else 
	{
		f += 25;
	}
	//½±Àø
	int award = 0;
	//ÓÐ×ÖÄ¸¡¢Êý×Ö
	if (sym != 0 && num != 0 && f==0)
	{
		award += 2;
	}//×ÖÄ¸Êý×ÖºÍ·ûºÅ
	else if (sym != 0 && num != 0 && f != 0)
	{
		award += 3;
	}//´óÐ¡Ð´×ÖÄ¸¡¢Êý×Ö¡¢·ûºÅ
	else if (big != 0 && small != 0 && num != 0 && f != 0)
	{
		award += 5;
	}
	sum = len + sym + num + f + award;
	if (sum >= 90)
	{
		cout << "VERY_SECURE" << endl;
	}
	else if ( 80<=sum && sum<90)
	{
		cout << "SECURE" << endl;
	}
	else if (70 <= sum && sum<80)
	{
		cout << "VERY_STRONG" << endl;
	}
	else if (60 <= sum && sum<70)
	{
		cout << "STRONG" << endl;
	}
	else if (50 <= sum && sum<60)
	{
		cout << "AVERAGE" << endl;
	}
	else if (25 <= sum && sum<50)
	{
		cout << "WEAK" << endl;
	}
	else if (0 <= sum && sum<25)
	{
		cout << "VERY_WEAK" << endl;
	}
	system("pause");
	return 0;
}