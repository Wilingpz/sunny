//给定一个字符串 S，返回 “反转后的” 字符串，其中不是字母的字符都保留在原地
//而所有字母的位置发生反转。
//
//
//
//示例 1：
//
//输入："ab-cd"
//输出："dc-ba"
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/reverse-only-letters
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include<iostream>
#include<string>
using namespace std;//双指针一个从头开始，一个从尾开始，若两个都是字母则交换
//若左边不为字母，则左指针加1，同理右指针加1
#if 0
class Solution 
{
public:
	string reverseOnlyLetters(string S) 
	{
		int left = 0;
		int right = S.size() - 1;
		while (left < right)
		{
			if (((S[left] >= 'a' && S[left] <= 'z') || (S[left] >= 'A' && S[left] <= 'Z'))
				&& ((S[right] >= 'a' && S[right] <= 'z') || (S[right] >= 'A' && S[right] <= 'Z'))
				)
			{
				swap(S[left], S[right]);
				left++;
				right--;
			}
			if (!((S[left] >= 'a' && S[left] <= 'z') || (S[left] >= 'A' && S[left] <= 'Z')))
			{
				left++;
			}
			if (!((S[right] >= 'a' && S[right] <= 'z') || (S[right] >= 'A' && S[right] <= 'Z')))
			{
				right--;
			}
		}

		return S;
	}
};

#else

class Solution {
public:
	string reverseOnlyLetters(string S) {
		if (S.size() < 2) {
			return S;
		}

		int l = 0;
		int r = S.size() - 1;

		while (l < r) {
			bool resL = isWord(S[l]);
			bool resR = isWord(S[r]);
			if (resL && resR) {
				swap(S[l], S[r]);
				l++;
				r--;
			}
			if (!resL) {
				l++;
			}

			if (!resR) {
				r--;
			}
		}
		return S;
	}

	bool isWord(char ch) {
		if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
			return true;
		}
		return false;
	}
};
#endif
