//你的朋友正在使用键盘输入他的名字 name。偶尔，在键入字符 c 时，
//按键可能会被长按，而字符可能被输入 1 次或多次。
//
//你将会检查键盘输入的字符 typed。如果它对应的可能是你的朋友的名字
//（其中一些字符可能被长按），那么就返回 True。
//
//
//
//示例 1：
//
//输入：name = "alex", typed = "aaleex"
//输出：true
//解释：'alex' 中的 'a' 和 'e' 被长按。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/long-pressed-name
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
#include<iostream>
#include<string>
using namespace std;


class Solution 
{
public:
	bool isLongPressedName(string name, string typed)
	{
		int tmp = 0;//存储typed中有几个name里的字母（只存储一遍）
		for (int i = 0; i < typed.length(); i++)//遍历typed
		{
			if (name[tmp] == typed[i])
			{
				tmp++;
			}
			if (tmp == name.length())
			{
				break;
			}
		}
		if (tmp == name.length())
		{
			return true;
		}
		return false;
	}
};



