//最长公共子序列
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	string A, B;
	while (cin >> A >> B)
	{
		int alen = A.length();
		int blen = B.length();
		vector<vector<int>>dp(alen, vector<int>(blen, 0));
		/*if (A[0] == B[0])
		{
			dp[0][0] = 1;
		}
		else
		{
			dp[0][0] = 0;
		}*/
		dp[0][0] = (A[0] == B[0]) ? 1 : 0;
		for (int i = 1; i < alen; i++)
		{
			dp[i][0] = (A[i] == B[0]) ? 1 : 0;
			dp[i][0] = max(dp[i - 1][0], dp[i][0]);
		}
		for (int j = 1; j < blen; j++)
		{
			dp[0][j] = (A[0] == B[j]) ? 1 : 0;
			dp[0][j] = max(dp[0][j-1], dp[0][j]);
		}
		for (int i = 1; i < alen; i++)
		{
			for (int j = 1; j < blen; j++)
			{
				if (A[i] == B[j])
				{
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				else
				{
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}
		cout << dp[alen - 1][blen - 1]<<endl;
	}
	return 0;
}

