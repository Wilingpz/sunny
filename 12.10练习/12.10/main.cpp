#include <iostream>//���룬ֻ��Ӣ�Ĵ�д��������ĸת�������������ĸ
#include<string>
using namespace std;//������Ų���
//int main()//ת��Ϊ��˹��������ĵ������ĸ
//{
//	string A;
//	while (getline(cin, A))
//	{
//		for (int i = 0; i < A.size(); i++)
//		{
//			if (A[i] >= 'A'&&A[i] <= 'U')
//			{
//				A[i] += 5;//A-U֮�����ֱ��+5����ת��
//			}
//			else if (A[i] >= 'V'&&A[i] <= 'Z')
//			{
//				A[i] = 'A' + A[i] - 'V';//V-Z
//			}
//			else
//			{
//				continue;
//			}
//		}
//		cout << A << endl;
//	}
//	system("pause");
//	return 0;
//}
int main1()//������ĸ��A,B,C,D,E,F,G,H,I,G,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z
			//ת����V,W,X,Y,Z,G,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z
{
	string s;
	while (getline(cin, s))
	{
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] <= 'E'&&s[i] >= 'A')
			{
				s[i] += 21;
			}
			else if (s[i] >= 'F'&&s[i] <= 'Z')
			{
				s[i] -= 5;
			}
			else
			{
				continue;
			}
		}
		cout << s << endl;
	}
	system("pause");
	return 0;
}