#include<iostream>
#include<string>
using namespace std;
//¿Õ¸ñÌæ»»%20
class Solution 
{
public:
	
	string replaceSpace(string s) 
	{
		string res;
		for (auto &i : s)
		{
			if ((i >= 'a'&& i <= 'z') || (i >= 'A' && i <= 'Z'))
			{
				res += i;
			}
			else if (i == ' ')
			{
				res += "%20";
			}
		}
		return res;
	}
};

int main2()
{
	Solution a;
	string s = "We Are Happy";
	cout << a.replaceSpace(s) << endl;
	system("pause");
	return 0;

}