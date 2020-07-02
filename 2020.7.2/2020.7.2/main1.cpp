#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int n;
	while (cin >> n) 
	{
		if (n == 0) break;
		long total = pow(5, n) - 4;
		long left = pow(4, n) + n - 4;
		cout << total << " " << left << endl;
	}
	return 0;
}
