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
			A = tmp ^ res;//�൱��û�н�λ�ļӷ�
			B = (tmp & res) << 1;//�൱�ڽ�λ
		}
		return A;
	}
};