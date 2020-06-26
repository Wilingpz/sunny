//洗牌
#include<iostream>
#include<vector>
using namespace std;
#if 0
void RES(vector<int>tmp)
{
	int n = tmp.size()/2;
	vector<int>left(n);
	vector<int>right(n);
	for (int i = 0; i < n; i++)
	{
		 left[i]=tmp[i];
	}
	for (int i = n; i < 2 * n; i++)
	{
		right[i] = tmp[i];
	}
	int i = n-1, j = 2*n-1;
	while (i >=0  && j >= n)
	{
		int k = 0;
		tmp[k] = right[j];
		tmp[k+1] = left[i];
		i--;
		j--;
		k += 2;
	}
}

int main()
{
	int T;//T组
	cin >> T;
	int k, n;//2n张牌，洗第k次后的结果
	cin >> k >> n;
	vector<int>tmp(2*n);
	for (int i = 0; i < 2*n; i++)
	{
		cin >> tmp[i];
	}
	for (int i = 0; i < k; i++)
	{
		RES(tmp);
	}
	for (int i = 0; i < 2*n - 1;i++)
	{
		cout << tmp[i] << ' ';
	}
	cout << tmp[2 * n - 1];
	system("pause");
	return 0;
}
#else
int main1()
{
	int T, n, k;
	cin >> T;
	while (T)
	{
		cin >> n >> k;
		int num = 2 * n;
		vector<int>table(num);
		for (int i = 0; i < num; i++)
		{
			cin >> table[i];
		}
		while (k)
		{
			vector<int>n1(table.begin(), table.end());
			for (int i = 0; i < n; i++)
			{
				table[2 * i] = n1[i];
				table[2 * i + 1] = n1[i + n];
			}
			k--;
		}
		for (int i = 0; i < num -1; i++)
		{
			cout << table[i] << ' ';
		}
		cout << table[num - 1] << endl;
		T--;
	}
	return 0;
}
#endif