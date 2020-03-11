#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;//找前k小的数
class Solution
{
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
	{
		vector<int>temp;
		if (k <= 0 || input.size() <= 0 || k>input.size())
		{
			return temp;
		}
		sort(input.begin(), input.end());
		int i = 0;
		while (i<k)
		{
			temp.push_back(input[i]);
			i++;
		}
		return temp;
	}
};