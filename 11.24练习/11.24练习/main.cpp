#include<iostream>//输入一个整数，计算该整数二进制中1的个数
using namespace std;
int main()
{
	int num;
	while (cin >> num)//当输入的这个整数不为0时才进入循环，否则直接return 0
	{
		int i = 0;
		while (num)
		{
			if ((num & 1) == 1)
				i += 1;
			num >>= 1;
		}
		cout << i << endl;
	}
	return 0;
}
