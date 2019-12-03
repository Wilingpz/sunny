#include<iostream>
#include<vector>//数据过大会溢出
using namespace std;

class Gift {
public:
	int getValue(vector<int> gifts, int n) 
	{
		int k = n / 2;
		int hashtable[256] = { 0 };
		for (auto &i : gifts)
		{
			hashtable[i]++;
		}
		for (auto &i : gifts)
		{
			if (hashtable[i] > k)
			{
				cout << hashtable[i] << endl;
			}
		}
		return 0;
	}
};