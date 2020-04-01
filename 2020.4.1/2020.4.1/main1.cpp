//客似云来（有限斐波那契数列求和）
#include<iostream>
using namespace std;

long long Fib(int &from,int &to)
{
	long long Fib[80];
	Fib[0] = 1;
	Fib[1] = 1;
	for (int i = 2; i <80; i++)
	{
		Fib[i] = Fib[i - 1] + Fib[i - 2];
	}
	long long res = 0;
	for (int i = from-1; i < to; i++)
	{
		res += Fib[i];
	}
	return res;
}


int main()
{
	int from, to;
	while (cin >> from >> to)
	{
		long long  res = Fib(from, to);
		cout << res << endl;
	}
	system("pause");
	return 0;
}