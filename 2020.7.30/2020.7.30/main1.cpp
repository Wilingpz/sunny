#include<iostream>
#include<string>
using namespace std;

int main2()
{
	string s1;
	while (getline(cin, s1))
	{
		int pos = s1.rfind(' ', s1.size())+1;
		int count = 0;
		for (int i = pos; i < s1.size(); i++)
		{
			count++;
		}
		cout << count << endl;
	}
	system("pause");
	return 0;
}