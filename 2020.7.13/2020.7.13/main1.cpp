#include<iostream>
#include<string>
using namespace std;

int main1()
{
	string s1 = "abcd", s2 = "efghk";
	s1.insert(4, s2);
	cout << s1 << endl;
	system("pause");
	return 0;
}