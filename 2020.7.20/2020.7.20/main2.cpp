//��1+2+3+...+n��Ҫ����ʹ�ó˳�����
//for��while��if��else��switch��case�ȹؼ��ּ������ж���䣨A?B:C����
#include<iostream>
using namespace std;

class Solution 
{
public:
	int Sum_Solution(int n) 
	{
		int a = 1, b = a + 1;
		while (b <= n)
		{
			int c = b;
			while (b!=0)//ִ�мӷ�
			{
					int c = a^b;//���ӽ�λ��
					b = (a&b) << 1;//��λ
					a = c;
			}
			b=c;
			++b;
		}
		return a;
     }
};

int main2()
{
	Solution a;
	int n = 3;
	cout<<a.Sum_Solution(n)<<endl;
	system("pause");
	return 0;
}


