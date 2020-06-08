#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
	int StrToInt(string str)//���������������ŵ������û�������ŵ����
	{
		if (str.empty())
		{
			return 0;
		}
		int sig = 1;//Ĭ��Ϊ1
		if (str[0] == '+')
		{
			sig = 1;
			str[0] = '0';
		}
		if (str[0] == '-')
		{
			sig = -1;
			str[0] = '0';
		}
		double res = 0;
		for (int i = 1; i < str.size();i++)
		{
			if (!isdigit(str[i]))
			{
				return 0;
			}
			else
			{
				res = res * 10 + (str[i] - '0');
			}
		}
		return res*sig;
	}
};
int main1()
{
	Solution a;
	string b = "a12kn";
	cout<<a.StrToInt(b)<<endl;
	system("pause");
	return 0;
}