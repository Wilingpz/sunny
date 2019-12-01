#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int T;
	int n, k;//组数、半堆牌的张数、洗牌的次数
	cin >> T;
	while (T)
	{
		cin >> n >> k;//输入半牌的张数以及洗牌次数 
		int sum = 2 * n;
		vector<int>A(sum);
		for (int i = 0; i < sum; i++)//将2n个张牌放进vector容器中   
		{
			cin >> A[i];
		}
		while (k)//当洗牌次数大于0时进行洗牌
		{
			vector<int>res(A.begin(),A.end());
			for (int i = 0; i < n; i++)
			{
				A[2 * i ] = res[i];
				A[2 * i+1] = res[i + n];
				//如果当前数小于等于n（即在左手），则他下次出现的位置是 2*当前位置
				//与之对应的当前位置 + n（即在右手）的牌,则他下次出现的位置是 2*当前位置 + 1
			}
			--k;
		}
		for (int i = 0; i <sum-1; i++)
		{
			cout << A[i]<<' ';
		}
		cout << A[sum - 1] << endl;//为了使最后一个数字输出之后没有空格
		--T;
	}
	system("pause");
	return 0;
}