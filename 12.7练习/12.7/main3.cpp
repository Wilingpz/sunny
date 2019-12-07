#include<iostream>
#define k 3.14
using namespace std;

int main()
{
	/*int n;
	int r;*/
	double n;
	double r;
	while (cin >> n >> r)
	{  
		
			int Lround = 0;
			Lround = 2*k*r;
			if (Lround <= n)
			{
				cout << "Yes" << endl;
			}
			else
			{
				cout << "No" << endl;
			}
	}
	system("pause");
	return 0;

}