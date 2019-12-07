#include<iostream>//×î´ó×Ö¶ÎºÍ
#include<vector>

using namespace std;

int main1()
{
	int n;
	cin >> n;
	vector<int>a(n);
	for (int i = 0; i < n;i++)
	{
		cin >> a[i];
	}
	int max_sum = a[0];
	int temp = 0;
	for (int i = 0; i < a.size(); i++)
	{
		temp += a[i];
		if (temp>max_sum)
		{
			max_sum = temp;
		}
		if (temp < 0)
		{
			temp = 0;
		}
	}
	cout << max_sum << endl;
	system("puase");
	return 0;
}