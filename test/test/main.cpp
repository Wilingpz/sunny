#include<iostream>
#include<string>
#include<unordered_set>

using namespace std;

int main1()
{
	string tmp;
	getline(cin, tmp);

	unordered_set<char>s;
	
	for (auto &i : tmp)
	{
		if ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z'))
		{
			s.insert(i);
		}
	}//这里没有办法用unordered_set，因为他输出的顺序会根据哈希函数来决定，只能去重而已

	for (auto &i : s)
	{
		cout << i;
	}
	cout << endl;
	
	system("pause");
	return 0;
}