#include<iostream>
using namespace std;//���������������ţ��������������������������
class LCA {
public:
	int getLCA(int a, int b) 
	{
		while (a != b)
		{
			if (a > b)
			{
				a = a / 2;
			}
			else
			{
				b = b / 2;
			}
		}
		return a;
	}
};
int main2()
{
	LCA A;
	cout << A.getLCA(5, 7);
	system("pause");
	return 0;
}