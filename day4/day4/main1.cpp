#include<iostream>
#include<vector>
#include<map>
using namespace std;


class Solution {
public:
	/**
	* ԭ��ɾ���ظ����ֵ�Ԫ��,����Ψһ
	* @param nums int����һά����
	* @param numsLen int nums���鳤��
	* @return int����
	*/
	int unique(int* nums, int numsLen) 
	{
		int res = 0,count=0;
		for (int i = 0; i+1 < numsLen; i++)
		{
			if (nums[i] == nums[i + 1])
			{
				count++;
				for (int j = i; j+1 < numsLen; j++)
				{
					nums[j] = nums[j + 1];
				}
			}
		}
		res = numsLen - count;
		return res;
	}
};

int main()
{
	Solution a;
	int nums[] = { 1, 2, 3, 12,12 };
	cout<<a.unique(nums, 5);
	system("pause");
	return 0;
}