//makdir
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//解题思路：将输入的字符串存在vector中，再用sort函数（默认升序）对其进行排序
//比较前一个字符串是不是本字符串的子串，是则删除上一个数据
//最后在vector中每个元素前面加上mkdir -p 进行打印即可

bool IsSame(string s1, string s2)
{
	if (s1[1] == s2[1])
	{
		s2 = s2.substr(0, s1.size());
		if (s1 == s2)
		{
			return true;
		}
	}
	return false;
}
void mkdir(vector<string>&temp)
{
	int i = 0;
	while (i<temp.size()-1)//此时temp.size也是同步在更新
	{//前一个是后一个的子串且后一个的下一个字符是/
		//vector<string>所以两个中括号
		if ((IsSame(temp[i], temp[i + 1])) && temp[i + 1][temp[i].size()] == '/')
		{
			temp.erase(temp.begin()+i);//返回值是被删除元素的下一个元素的迭代器
		}
		else
		{
			i++;
		}
	}
	for (auto &i : temp)
	{
		cout << "mkdir -p " << i << endl;
	}
}
int main()
{
	int n;
	while (cin >> n)
	{
		vector<string>temp;
		for (int i = 0; i < n; i++)
		{
			string str;
			cin >> str;
			temp.push_back(str);
		}
		sort(temp.begin(), temp.end());
		mkdir(temp);
		cout << endl;
	}
	system("pause");
	return 0;
}