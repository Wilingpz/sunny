#include<iostream>//��������������λ�����֮�ͣ�����Ϊһλ���������ӣ�
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
			sum += num % 10;//��λ������
			num = num / 10;//��λ���ϵ�����
		}
		while (sum > 9)//������λ��
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
		/*ÿ��ֻ��ȡ��λ����---��λ��+ʮλ��*/        
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
		//�Ƚ�ÿһλ������ӵõ��ܺͣ���ֹ���ֹ���        
		for (int i = 0; i < origin.length(); i++) //Ҫ���ַ�������
		{            
			sum += origin[i] - '0';       
		}           //���ܺ�������       
		std::cout << numRoot(sum) << std::endl; 
	}    
	return 0; 
} 
#endif