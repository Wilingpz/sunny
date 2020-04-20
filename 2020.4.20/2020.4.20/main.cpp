//左右最值最大差
#include<iostream>
#include<vector>
using namespace std;
#if 0

class MaxGap 
{
public:
	int findMaxGap(vector<int> A, int n) //从0—(n-1)
	{
		int max2 = 0;
		int max1 = 0;
		int temp = 0;
		int diff = 0;
		int max = 0;
		while (temp <= n - 2)
		{
			for (int i = 0; i <= temp; i++)
			{
				if (A[i] > max1)
				{
					max1 = A[i];
				}
			}
			for (int j = n - 1; j > temp; j--)
			{
				if (A[j] > max2)
				{
					max2 = A[j];
				}
			}
			if (max1 > max2)
			{
				diff = max1 - max2;
			}
			else
			{
				diff = max2 - max1;
			}
			if (diff > max)
			{
				max = diff;
			}
			temp++;
		}
		return max;
	}
};

int main()
{
	vector<int>A = {2,7,3,1,1,73};
	int n = 6;
	MaxGap t1;
	int temp=t1.findMaxGap(A, n);
	cout << temp << endl;
	system("pause");

	return 0;
}
#else
class MaxGap
{
public:
	int findMaxGap(vector<int> A, int n)
	{
		int maxnum = A[0];
		for (auto &i : A)
		{
			if (i > maxnum)
			{
				maxnum = i;
			}
		}
		if (maxnum == A[0])
		{
			return (A[0] - A[n - 1]);
		}
		else if (maxnum == A[n - 1])
		{
			return (A[n - 1] - A[0]);
		}
		return A[0] > A[n - 1] ? (maxnum - A[n - 1]) : (maxnum - A[0]);
	}
};


#endif

