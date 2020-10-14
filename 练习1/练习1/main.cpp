#include<iostream>
#include<string>
using namespace std;


int main()
{
	int m;
	string s1, s2;
	cin >> m;
	cin >> s1 >> s2;

	int sum = 0, max = 0;

	for (int i = 0; i < s1.size(); i++)
	{
		int tmp = s2.find(s1[i]);
		int j = i;
		int pos = 0;
		while (tmp < s2.size())
		{
			for (; j < s1.size(); j++)
			{
				if (s1[j] == s2[tmp])
				{
					sum += 1;
					tmp++;
				    pos = j;
				}
			}
			tmp++;
			j = pos + 1;
		}
		if (sum>max)
		{
			max = sum;
		}
		sum = 0;
	}

	cout << max << endl;

	system("pause");
	return 0;
}