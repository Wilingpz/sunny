#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main9()
{
	//string s("abcdefg");
	//reverse(s.begin(), s.begin()+2);//����firstָ�򣬲�����last��ָ��
	//reverse(s.begin() + 2, s.begin() + 4);
	//cout << s << endl;
	string s(5,'0');
	int tmp = 12;
	s[3] = (12 % 10)+'0';
	s[2] = (12 / 10)+'0';

	string s1("hello");
	s1.erase(0, 3);//��ǰ�������reverseһ��
	
	cout << s1 << endl;
	system("pause");
	return 0;
}