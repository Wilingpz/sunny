#include<iostream>
#include<vector>

using namespace std;
//¾ØÐÎ¸²¸Ç

class Solution 
{
public:
	int rectCover(int number) 
	{
		if (number==1)
		{
			return 1;
		}
		else if (number==2)
		{
			return 2;
		}
		vector<int>f(number + 1, 0);
		f[1] = 1;
		f[2] = 2;
		for (int i = 3; i <= number; i++)
		{
			f[i] = f[i - 1] + f[i - 1];
		}
		return f[number];
	}
};

int main2()
{
	Solution a;
	int b = 3;
	cout << a.rectCover(3) << endl;
	system("pause");
	return 0;
}