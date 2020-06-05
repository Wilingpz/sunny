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

		// ����ÿ��Ԫ�أ�����¼����������ǰһ��Ԫ����ͬ���������1�����������1
		int result = numbers[0];
		int times = 1; // ����

		for(int i=1;i<numbers.size();++i)
		{
			if(times == 0)
			{
				// ����result��ֵΪ��ǰԪ�أ����ô���Ϊ1
				result = numbers[i];
					times = 1;
			}
			else if(numbers[i] == result)
			{
				++times; // ��ͬ���1
			}
			else
			{
				--times; // ��ͬ���1
			}
		}

		// �ж�result�Ƿ���������������ִ����������鳤�ȵ�һ��
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
		sort(numbers.begin(), numbers.end());//ʱ�临�Ӷ�Ϊ��oNlogn��
		int temp = numbers[numbers.size() / 2];
		int count = 0;
		for (auto &i : numbers)
		{
			if (i == temp)
			{
				count++;
			}
		}
		if (count > numbers.size() / 2)//�Ǵ��ڲ��Ǵ��ڵ��ڣ�������
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