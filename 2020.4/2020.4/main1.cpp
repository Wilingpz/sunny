//判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）
//读都是一样的整数。
//
//示例 1:
//
//输入 : 121
//输出 : true
#include<iostream>
using namespace std;

class Solution 
{
public:
	bool isPalindrome(int x) //如果是负数则一定不是回文数
	{
		if (x < 0 || (x%10==0 && x!=0))//如果最后一位为0则第一位必须为0，故只有0
		{
			return false;
		}
		int temp = 0;//反转后半段数字
		while (x>temp)
		{
			temp = (temp * 10) + (x % 10);//后半段数字的大小
			x /= 10;
		}
		if (x == temp || x == temp / 10)//如果x是偶数看后半段反转数temp是否等于
			//x前半段，若x是奇数，则看后半段反转数temp/10是否等于x前半段
		{
			return true;
		}
		return false;
	}
};



