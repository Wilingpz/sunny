#include<iostream>//给定三个边，求这三个边能不能围成一个三角形
using namespace std;

int main()
{
	double n, m, k;
	while (cin >> n>> m>>k)
	{
		if ((n + m > k)&& (n + k > m) && (m + k >n))
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
	system("pause");
	return 0;
}
