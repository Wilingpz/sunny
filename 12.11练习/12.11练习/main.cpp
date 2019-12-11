//题目描述:
//有一只兔子，从出生后第3个月起每个月都生一只兔子，
//小兔子长到第三个月后每个月又生一只兔子，
//假如兔子都不死，问每个月的兔子总数为多少？
//本月所有的兔子总数等于上个月的兔子数加上本月新产生的兔子数
//即等于前两个月兔子数量之和
#include<iostream>
using namespace std;
 
int main()
{
	int month;
	while (cin >> month)
	{
		if (month == 1 || month == 2)
		{
			cout << 1 << endl;
		}
		int first = 1;
		int second = 1;
		int sum = 0;
		if (month >= 3)
		{
			for (int i = 3; i <= month; i++)
			{
				sum = first + second;
				first = second;
				second = sum;
			}
			cout << second << endl;
		}	
	}
	system("pause");
	return 0;
}