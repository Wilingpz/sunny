#include<iostream>
using namespace std;
int main1()
{
	int n;
	while (cin >> n)
	{
		int * tmp = new int[n];
		for (int i = 0; i < n; i++)
		{
			int k;
			cin >> k;
			tmp[i] = k;
		}
		int t = 3;
		for (int i = 0; i < n; ++i, --t)
		{
			cout << tmp[i];
			cout << t << endl;
		}
		//���룺5   1 2 3 4 5 
		//�����    13 22 31 40 5-1
	}
	return 0;
}