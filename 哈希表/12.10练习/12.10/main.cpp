#include <iostream>//密码，只有英文大写，将该字母转换成其后第五个字母
#include<string>
using namespace std;//其余符号不变
//int main()//转换为阿斯卡码表其后的第五个字母
//{
//	string A;
//	while (getline(cin, A))
//	{
//		for (int i = 0; i < A.size(); i++)
//		{
//			if (A[i] >= 'A'&&A[i] <= 'U')
//			{
//				A[i] += 5;//A-U之间可以直接+5进行转换
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
int main1()//密码字母：A,B,C,D,E,F,G,H,I,G,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z
			//转换表：V,W,X,Y,Z,G,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z
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