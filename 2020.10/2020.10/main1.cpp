//给定两个二进制字符串，返回他们的和（用二进制表示）。
//
//输入为非空字符串且只包含数字 1 和 0。
//
//示例 1 :
//
//输入 : a = "11", b = "1"
//输出 : "100"
//
//	 来源：力扣（LeetCode）
// 链接：https ://leetcode-cn.com/problems/add-binary
//	 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
#include<iostream>
#include<string>
using namespace std;

class Solution 
{
public:
	string addBinary(string a, string b) 
	{
		if (a.size() < b.size())
		{
			swap(a, b); //保证a最长
		}
		reverse(a.begin(), a.end());  //倒序是为了保证两个字符串能够按照正确顺序将对应位相加
		reverse(b.begin(), b.end());
		int res = 0;//进位
		string result;//存放结果
		for (int i = 0; i<b.size(); i++)//因为b比较短
		{
			if (a[i] - '0' + b[i] - '0' + res >= 2)
			{
				result += to_string((a[i] - '0' + b[i] - '0' + res) % 2);
				res = 1;//to_string将整型数字变为字符型，将进位置1
			}
			else
			{
				result += to_string((a[i] - '0' + b[i] - '0' + res) % 2);
				res= 0;//否则进位为0
			}
		}
		for (int i = b.size(); i<a.size(); i++)//处理长度大于b小于a的那部分
		{
			if (a[i] - '0' + res>= 2)
			{
				result += to_string((a[i] - '0' + res) % 2);
				res = 1;
			}
			else{
				result += to_string((a[i] - '0' + res) % 2);
				res = 0;
			}
		}
		if (res == 1)//如果最后的进位为1
		{
			result += to_string(1);//给结果要加1
		}
		reverse(result.begin(), result.end());//将字符串反转回来并返回
		return result;
	}
};




//(2) C语言中 有 单个字符   相减 运算。
//例如, 把字符串"1234"里的各个数字字符转成整型，存入整型数组：
//int i, x[4];
//char str[] = "1234";
//for (i = 0; i<4; i++)  x[i] = str[i] - '0';
//例如, 把字符串中字母，小写变大写：
//char str[] = "aBcxYz";
//int i;
//for (i = 0; i<strlen(str); i++)
//if (str[i] >= 'a' && str[i] <= 'z') str[i] = str[i] - 'a' + 'A';
//
//(3) 字符串大小比较 用 strcmp() 或 strncmp() 函数
//例如：
//if (strcmp(a, b) == 0) printf(" string a and b are the same\n");
//if (strcmp(a, b) > 0) printf(" string a is bigger than  b\n");
