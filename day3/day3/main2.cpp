#include<iostream>

//二进制中的1的个数
using namespace std;
#if 0
class Solution 
{
public:
	int  NumberOf1(int n) 
	{
		//正数自己向右移，最高位自动补0
		int res = 0;
		while (n!=0)
		{
			if (n & 1 == 1)
			{
				res += 1;
			}
			n >>= 1;
		}
		return res;
	}
};
#else
//想要照顾到负数则可以移1，不用动原来的数
class Solution {
public:
	int NumberOf1(int n) {
		int num = 0, flag = 1;
		while (flag != 0) {
			if ((n & flag) != 0) {
				num++;
			}
			flag <<= 1;
		}
		return num;
	}
};
#endif

int main3()
{
	Solution a;
	cout << a.NumberOf1(10) << endl;
	system("pause");
	return 0;
}