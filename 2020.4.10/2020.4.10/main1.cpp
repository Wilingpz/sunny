#include<iostream>//LIS最长上升子序列
#include<vector>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		vector<int>temp(n);
		vector<int>dp(n);
		int maxlenth = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> temp[i];
		}
		for (int i = 0; i < n; i++)
		{
			dp[i] = 1;
		}
		for (int i = 1; i < n;i++)
		{
			for (int j = 0; j < i; j++)
			{
				if ((temp[j] < temp[i])&&(dp[j]+1>dp[i]))
				{
					dp[i] = dp[j] + 1;
				}
			}
		}
		for (auto &i : dp)
		{
			if (i>maxlenth)
			{
				maxlenth = i;
			}
		}
		cout << maxlenth << endl;
	}
	system("pause");
	return 0;
}