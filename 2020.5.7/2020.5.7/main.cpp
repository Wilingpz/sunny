//×Ö·û´®¼ÆÊý
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#define N 1000007
#include<math.h>
using namespace std;

int mian()
{
	string s1, s2;
	int len1, len2;
	while (cin >> s1 >> s2 >> len1 >> len2)
	{
		s1.append(s1.size() - len2, 'a');
		s2.append(s2.size() - len2, (char)('z' + 1));
		vector<int>arr;
		for (int i = 0; i < len2; i++)
		{
			arr.push_back(s2[i] - s1[i]);
		}
		int res = 0;
		for (int i = 0; i <= len2; i++)
		{
			for (int j = 0; j < i; j++)
			{
				res += arr[j] * pow(26, i - 1 - j);
			}
		}
		cout << res-1 << endl;
	}
	return 0;
}