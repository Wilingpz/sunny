#include<iostream>
using namespace std;//计算一个数的二进制最大连续1的个数
#if 0
int Find(int a)
{
	int max = 0;
	int count = 0;
	for (int i = 0; i < 32; i++)
	{
		if (a&(1 << i))
		{
			++count;
		}
		else
		{
			if (max < count)
			{
				max = count;
				count = 0;
			}
		}
	}
   return max;
}
#else
int Find(int a)
{
	int max = 0;
	while (a)
	{
		int count = 0;
		while (a & 1 == 1)
		{
			++count;
			a = a >> 1;
		}
		if (max < count)
		{
			max = count;
			a = a >> 1;
		}
		return max;
	}
}
	
#endif
int main()
{
	int a = 54;
	cout<<Find(a)<<endl;
	system("pause");
	return 0;
}