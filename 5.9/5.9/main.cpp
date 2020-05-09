//马戏团
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct Player
{
	int w;
	int h;
};

bool cmp(Player a, Player b)//返回a和b的大小比较结果，为0则a比b大，为1则a比b小
{
	if (a.w != b.w)
	{
		return a.w <= b.w;//体重从小到大排序
	}
	else
	{
		return a.h > b.h;//体重相等按身高升序排列
	}
}
int main()
{
	int N;
	int index;
	int w;
	int h;
	while (cin >> N)
	{
		vector<Player>P;
		for (int i = 0; i < N; i++)
		{
			Player tmp;
			cin >> index >> w >> h;
			tmp.h = h;
			tmp.w = w;
			P.push_back(tmp);
		}
		sort(P.begin(), P.end(), cmp);
		//求身高最长上升子序列
		vector<int>dp(N+1);
		int max = 0;
		dp[0] = 1;
		for (int i = 1; i < N; i++)
		{
			dp[i] = 1;
			for (int j = 0; j < i; j++)
			{
				if (P[j].h <= P[i].h &&dp[j] + 1>dp[i])
				{
					dp[i] = dp[j] + 1;
				}
			}
		}
		for (auto &i : dp)
		{
			if (i > max)
			{
				max = i;
			}
		}
		cout << max << endl;
	}
	return 0;
}