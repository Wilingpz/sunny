#include<iostream>//求数根（即所有位数相加之和，若不为一位数则继续相加）
#include<string>

using namespace std;
#if 1
int main()
{
	int num;
	while (cin >> num)
	{
		int sum = 0;
		int res = 0;
		while (num > 0)
		{
			sum += num % 10;//个位的数字
			num = num / 10;//个位以上的数字
		}
		while (sum > 9)//所有数位和
		{
			res = sum % 10;
			sum = sum / 10;
			sum += res;
		}
		cout << sum << endl;
	}
	system("pause");
	return 0;
}
#else

#include <iostream> 
#include <string> 
int numRoot(int num) 
{    
	int nroot = 0;    
	while(num > 0) 
	{        
		/*每次只获取个位数字---个位数+十位数*/        
		nroot += num % 10;        
		num /= 10;    
	}      
	while (nroot > 9) 
	{       
		nroot = numRoot(nroot);    
	}       
	return nroot;
} int main() 
{    
	std::string origin;   
	while(std::cin >> origin) 
{        
		int sum = 0;        
		//先将每一位进行相加得到总和，防止数字过大        
		for (int i = 0; i < origin.length(); i++) //要用字符串来做
		{            
			sum += origin[i] - '0';       
		}           //对总和求树根       
		std::cout << numRoot(sum) << std::endl; 
	}    
	return 0; 
} 
#endif