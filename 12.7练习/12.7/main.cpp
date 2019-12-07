#include<iostream>//红包金额超过红包总数的一半
#include<vector>
#include<map>
using namespace std;

class Gift {
public:
	int getValue(vector<int> gifts, int n) 
	{
		int mid = n / 2;
		map<int, int>k;
		for (auto &i : gifts)
		{
			k[i]++;
		}
		for (auto &i : k)
		{
			if (i.second > mid)
			{
				cout << i.first;
			}
		}
		return 0;
	}
};