#include<iostream>//���������ߣ������������ܲ���Χ��һ��������
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
