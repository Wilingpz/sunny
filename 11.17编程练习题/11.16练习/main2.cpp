#include<iostream>
using namespace std;//满二叉树，层序标号，求所给两个数的最近公共祖先
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