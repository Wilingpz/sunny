#include<iostream>
#include<cmath>
#include<string>

using namespace std;


int main()
{
	string s1;
	cin >> s1;
	
	string a = "0123456789abcdefghijklmnopqrstuvwxyz";
	int size = s1.size();
	int num = 0;
	for (int i = 0; i < size; i++)
	{
		num = a.find(s1[i]) * pow(36, size - 1 - i) + num;
	}
	
	cout << num << endl;
	system("pause");
	return 0;
}
