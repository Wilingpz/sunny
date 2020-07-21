//求1+2+3+...+n，要求不能使用乘除法、
//for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
#include<iostream>
using namespace std;

class Solution 
{
public:
	int Sum_Solution(int n) 
	{
		int a = 1, b = a + 1;
		while (b <= n)
		{
			int c = b;
			while (b!=0)//执行加法
			{
					int c = a^b;//不加进位的
					b = (a&b) << 1;//进位
					a = c;
			}
			b=c;
			++b;
		}
		return a;
     }
};

int main2()
{
	Solution a;
	int n = 3;
	cout<<a.Sum_Solution(n)<<endl;
	system("pause");
	return 0;
}


