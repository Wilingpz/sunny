#include<iostream>
#include<map>
#include<vector>
using namespace std;

class Gift 
{
public:
	int getValue(vector<int> gifts, int n)
	{
		int m = n / 2;
		map<int, int>k;
		for (auto &i : gifts)
		{
			k[i]++;
		}
		for (auto&i : k)
		{
			if (i.second > m)
			{
				return i.first;
			}
		}
		return 0;
	}
};