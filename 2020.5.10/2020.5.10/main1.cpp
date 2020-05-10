#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	int k;
	while (cin >> n)
	{
		vector<int>tmp(n);
		for (int i = 0; i < n; i++)
		{
			int m;
			cin >> m;
			tmp[i] = m;
		}
		int k;
		cin >> k;
		sort(tmp.begin(), tmp.end());//升序排列
		for (int i = 1; i < tmp.size(); i++)
		{
			if (tmp[i] == tmp[i - 1])
			{
				tmp.erase(tmp.begin() + i);
				i--;//删除当前位置值后，下一次该位置为新值，仍要从该位置开始
			}
		}
				cout << tmp[k-1] << endl;
	}
	return 0;
}






//56
//68 33 100 22 1 39 75 33 46 77 85 50 23 7 5 61 96 72 74 30 10 59 75 25 26 39 67 90 68 63 97 31 3 28 37 98 72 77 95 100 93 13 66 39 37 44 64 68 63 38 46 84 35 50 47 80
//3