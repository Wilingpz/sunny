//��Ϸ��
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct Player
{
	int w;
	int h;
};

bool cmp(Player a, Player b)//����a��b�Ĵ�С�ȽϽ����Ϊ0��a��b��Ϊ1��a��bС
{
	if (a.w != b.w)
	{
		return a.w <= b.w;//���ش�С��������
	}
	else
	{
		return a.h > b.h;//������Ȱ������������
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
		//����������������
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