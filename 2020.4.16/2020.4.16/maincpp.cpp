//骆驼命名法
#include<iostream>
#include<string>
using namespace std;

int main1()
{
	string temp;
	while (cin >> temp)
	{
		int k = 0;
		for (int i = 0; i < temp.size(); i++)
		{
			if (temp[i] == '_')
			{
				temp.erase(temp.begin()+i);
				temp[i] = temp[i] - 32;
			}
		}
		cout << temp << endl;
		system("pause");
	}
	return 0;
}


//string中erase函数的用法
//1、string &erase（size_t pos=0,size_t n=npos）删除从pos位置开始的n个字符
//2、iterator erase（position）;删除position位置处的字符（position是string类型的迭代器）
//3、erase（iterator first，iterator last）;删除从first到last之间的字符
//