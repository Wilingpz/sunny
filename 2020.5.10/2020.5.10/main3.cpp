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
		//ÊäÈë£º5   1 2 3 4 5 
		//Êä³ö£º    13 22 31 40 5-1
	}
	return 0;
}