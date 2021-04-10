#include<iostream>
using namespace std;

//水仙花数
//所谓水仙花数（NarcissisticNumber）是指一个3位数
//其各位数字的立方和等于它本身。
//100-1000之间的水仙花数
#if 0
int main()
{
	int j, k, m, res;
	int tmp = 0;
	for (int i = 100; i <1000; i++)
	{
		j = i / 100;
		k = i / 10 - j * 10;
		m = i % 10;
		res = (j*j*j) + (k*k*k) + (m*m*m);
		if (i == res)
		{
			++tmp;
		}
	}
	cout << tmp;
	system("pause");
	return 0;
}

#else
int main4()
{
	int i, j, k, n;
	cout << "narcissus numbers are:" << endl;
	for (n = 100; n<1000; n++)
	{
		i = n / 100;
		j = n / 10 - i * 10;
		k = n % 10;
		if (n == i*i*i + j*j*j + k*k*k)
			cout << n << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
#endif