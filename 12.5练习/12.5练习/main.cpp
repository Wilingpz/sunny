#include<iostream>//斐波那契数列
using namespace std;

#if 0
class Solution
{
public:    
	int Fibonacci(int n)
{
		if (n <= 0)
		{
			return 0;
		}
		if (n == 1 || n == 2)
		{
			return 1;
		}
		return Fibonacci(n-2) + Fibonacci(n-1);
}
};
#else
class Solution
{
public:
	int Fibonacci(int n)
	{
		if (n <= 0)
		{
			return 0;
		}
		if (n == 1 || n == 2)
		{
			return 1;
		}
		int* record = new int[n + 1];
		record[0] = 0;
		record[1] = 1;
		 for (int i = 2; i <= n; i++)
		 {            // F(n)=F(n-1)+F(n-2)            
			 record[i] = record[i - 1] + record[i - 2];        
		 }        
		 return record[n];        
		 delete[] record;
	}
	};
#endif



	
