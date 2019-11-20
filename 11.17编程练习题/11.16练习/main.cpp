#include<iostream>
using namespace std;
class UnusualAdd {//不用+号，完成两个数的加法
public:
#if 0
	int addAB(int A, int B) 
	{

		if (B== 0)
		{
			return A;
		}
		int sum = A^B;
		int temp = (A & B) << 1;
		addAB(sum, temp);
	}
#else
	int addAB(int A, int B)
	{
		int sum=0;
		int temp=0;
		if (B!= 0)
		{
			sum = A^B;
			temp = (A & B) << 1;
			A = sum;
			B = temp;
		}
		return A;
	}
#endif
};
int main1()
{
	UnusualAdd A;
	int s = 8;
	int n = 6;
	cout << A.addAB(s, n) << endl;;
	system("pause");
	return 0;
}