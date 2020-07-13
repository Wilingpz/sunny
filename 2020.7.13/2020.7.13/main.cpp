#include<iostream>
#include<string>
using namespace std;
#if 0
bool IsCouple(string& s1)
{
	int res = s1.size()-1;
	int i = 0;
	while (s1[i] == s1[res]&& res>=i)
	{
		if (i == res || i + 1 == res)
		{
			return true;
		}
		++i;
		--res;
	}
	
	return false;
	
}
#else
bool IsCouple(string& s1)
{
	int res = s1.size() - 1;
	int i = 0;
	while (i<res)
	{
		if (s1[i] != s1[res])
		{
			return false;//判断不成立比判断成立简单
		}
		++i;
		--res;
	}

	return true;;

}
#endif
int main()
{
	string s1, s2;
	cin >> s1>>s2;
	int count = 0;
	for (int i = 0; i <= s1.size(); i++)
	{
		string tmp = s1;
		tmp.insert(i, s2);
		//cout << tmp << endl;
		if (IsCouple(tmp))
		{
			count++;
		}
		tmp = s1;
	}
	cout << count << endl;
	system("pause");
	return 0;
}