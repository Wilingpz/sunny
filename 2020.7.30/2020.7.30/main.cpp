#include<iostream>
#include<string>
using namespace std;

int main1()
{
	string s1;
	while (getline(cin, s1))
{

	string s2;
	for (int i = 0; i<s1.size(); i++)
	{
		if (s1.find(s1[i], 0) == s1.rfind(s1[i], s1.size()))
		{
			s2.push_back(s1[i]);
		}
	}
	if (!(s2.empty()))
	{
		cout << s2[0]<< endl;
	}
	else
	{
		cout << -1 << endl;
	}
}
	system("pause");
	return 0;

}