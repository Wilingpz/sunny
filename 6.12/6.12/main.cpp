#include<iostream>
using namespace std;

class UnusualAdd
{
public:
	int addAB(int A, int B)
	{
		while (B != 0)
		{
			int tmp = A, res = B;
			A = tmp ^ res;//相当于没有进位的加法
			B = (tmp & res) << 1;//相当于进位
		}
		return A;
	}
};