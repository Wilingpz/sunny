#include<iostream>

//�������е�1�ĸ���
using namespace std;
#if 0
class Solution 
{
public:
	int  NumberOf1(int n) 
	{
		//�����Լ������ƣ����λ�Զ���0
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
//��Ҫ�չ˵������������1�����ö�ԭ������
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