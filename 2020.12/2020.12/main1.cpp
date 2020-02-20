//给定一组字符，使用原地算法将其压缩。
//
//压缩后的长度必须始终小于或等于原数组长度。
//
//数组的每个元素应该是长度为1 的字符（不是 int 整数类型）。
//
//在完成原地修改输入数组后，返回数组的新长度。
//
//
//
//进阶：
//你能否仅使用O(1) 空间解决问题？
//
//
//
//示例 1：
//
//输入：
//["a", "a", "b", "b", "c", "c", "c"]
//
//输出：
//返回6，输入数组的前6个字符应该是：["a", "2", "b", "2", "c", "3"]
//
//说明：
//"aa"被"a2"替代。"bb"被"b2"替代。"ccc"被"c3"替代
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/string-compression
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。



#include<iostream>
#include<vector>
using namespace std;
#if 0
class Solution //不知道为什么错了
{
public:
	int compress(vector<char>& chars) 
	{
		int i = 1;
		int j = 1;
		vector<char>tmp;
		if (chars.size()<2)
		{
			return 1;
		}
		tmp.push_back(chars[0]);
		while (i < chars.size())
		{
			while(chars[i] == tmp.back())
			{
			j++;
			i++;
			}
			if (j>1)
			{
				tmp.push_back(j + '0');
			}
			tmp.push_back(chars[i]);
			i++;
			j = 1;
		}
		return tmp.size();
	}
};
#else


#endif 


