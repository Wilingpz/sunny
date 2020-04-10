//发邮件(错排问题)
#include<iostream>
#include<vector>
using namespace std;

int main1()
{
	int n;
	while (cin >> n)
	{
		vector<long long>temp(n+2);
		temp[0] = 0;
		temp[1] = 0;
		temp[2] = 1;
		for (int i = 3; i <= n; i++)
		{
			temp[i] = (i - 1)*(temp[i - 2] + temp[i - 1]);
		}
		cout << temp[n] << endl;
	}
	system("pause");
	return 0;
}