#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#if 0
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers)
	{
		if(numbers.empty()) return 0;

		// 遍历每个元素，并记录次数；若与前一个元素相同，则次数加1，否则次数减1
		int result = numbers[0];
		int times = 1; // 次数

		for(int i=1;i<numbers.size();++i)
		{
			if(times == 0)
			{
				// 更新result的值为当前元素，并置次数为1
				result = numbers[i];
					times = 1;
			}
			else if(numbers[i] == result)
			{
				++times; // 相同则加1
			}
			else
			{
				--times; // 不同则减1
			}
		}

		// 判断result是否符合条件，即出现次数大于数组长度的一半
		times = 0;
		for (int i = 0; i<numbers.size(); ++i)
		{
			if (numbers[i] == result) ++times;
		}

		return (times > numbers.size() / 2) ? result : 0;
	}
};

int main()
{
	Solution s1;
	vector<int>numbers = { 1, 2, 3, 2, 2, 2, 5, 4, 2 };
	s1.MoreThanHalfNum_Solution(numbers);
	system("pause");
	return 0;
}
#else
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) 
	{
		sort(numbers.begin(), numbers.end());//时间复杂度为（oNlogn）
		int temp = numbers[numbers.size() / 2];
		int count = 0;
		for (auto &i : numbers)
		{
			if (i == temp)
			{
				count++;
			}
		}
		if (count > numbers.size() / 2)//是大于不是大于等于，看好题
		{
			return temp;
		}
		return 0;
	}
};
int main1()
{
	Solution s1;
	vector<int>numbers = { 1, 2, 3, 2, 2, 2, 5, 4, 2 };
	s1.MoreThanHalfNum_Solution(numbers);
	system("pause");
	return 0;
}
#endif