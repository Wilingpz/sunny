#include<iostream>
using namespace std;
int main()
{
	int year;
	cout << "please enter year" << endl;
	while (cin >> year)
	{
		if (year > 0)
			break;
		else
		{
			cout << "error" << endl;
			continue;
		}
	}
	{
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
			cout << "a leap year" << endl;
		else
			cout << "not leap year" << endl;
	}
	system("pause");
	return 0;
}
