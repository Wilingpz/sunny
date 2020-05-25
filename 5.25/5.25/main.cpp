//×é¶Ó¾ºÈü
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		long long sum = 0;
		vector<int>a(3*n);
		for (int i = 0; i < (3 * n); i++)
		{
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		for (int i = n; i <= 3 * n - 2; i += 2)
		{
			sum += a[i];
		}
		cout << sum << endl;
	}
	return 0;
}