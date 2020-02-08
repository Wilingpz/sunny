//给定一个赎金信(ransom) 字符串和一个杂志(magazine)字符串，
//判断第一个字符串ransom能不能由第二个字符串magazines里面的字符构成。
//如果可以构成，返回 true ；否则返回 false。
//
//(题目说明：为了不暴露赎金信字迹，要从杂志上搜索各个需要的字母，
//组成单词来表达意思。)
//
//注意：
//
//你可以假设两个字符串均只含有小写字母。
//
//canConstruct("a", "b") -> false
//canConstruct("aa", "ab") -> false
//canConstruct("aa", "aab") -> true
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/ransom-note
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include<iostream>
#include<string>
#include<map>
using namespace std;

class Solution 
{
public:
	bool canConstruct(string ransomNote, string magazine)
	{
		map<int, int>a;
		for (auto &i : magazine)
		{
			a[i]++;
		}
		for (auto &i : ransomNote)//当map中不存在该元素时，会自动创建，但其键值为0
		{
			if (--a[i] < 0)//表示赎金信中的该字母在杂志中不存在或者存在的次数小于赎金信中的次数
			{
				return false;
			}
			
		}
		return true;
	}		
};
