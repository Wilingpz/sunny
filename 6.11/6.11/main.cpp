#include<iostream>
using namespace std;

int gcd(int &a, int &b)
{
	int c = 0;
	while (c=a%b)
	{
		a = b;
		b = c;
	}
	return b;
}
int main1()
{
	//最小公倍数等于，两数乘积/最大公约数
	int a, b = 0;
	while (cin >> a >> b)
	{
		cout << (a*b) / gcd(a, b) << endl;
		system("pause");
	}
	return 0;
}