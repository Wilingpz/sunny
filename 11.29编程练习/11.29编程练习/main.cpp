//1����Ŀ����
//���������ַ������ӵ�һ�ַ�����ɾ���ڶ����ַ��������е��ַ���
//���磬���롱They are students.���͡�aeiou������ɾ��֮��ĵ�һ���ַ���
//��ɡ�Thy r stdnts.��
//2��������˼·����
//�������ʹ�ô�ͳ�ı������ҷ�ʽ�����жϵ�һ�������ַ��Ƿ��ڵڶ������У�
//����Ų���ַ�ɾ������ַ��ķ�ʽ��Ч��ΪO(N ^ 2)��Ч��̫�ͣ������������⡣
//1�����ڶ����ַ������ַ���ӳ�䵽һ��hashtable������
//�����ж�һ���ַ�������ַ����� 
//2���ж�һ���ַ��ڵڶ����ַ�������Ҫʹ��ɾ��������Ч��̫��
//��Ϊÿ��ɾ������������Ų����
//������Կ���ʹ�ý������ַ���ӵ�һ�����ַ�������󷵻������ַ�����
#include<iostream> 
#include<string> 
using namespace std;
	int main1() 
	{    // ע�����ﲻ��ʹ��cin���գ���Ϊcin�����ո�ͽ����ˡ�    
		// oj��IO�����ַ������ʹ��getline��   
		string str1,str2;    
		//cin>>str1;    
		//cin>>str2;    
		getline(cin, str1);    
		getline(cin, str2);
		// ʹ�ù�ϣӳ��˼����str2ͳ���ַ����ֵĴ���    
		int hashtable[256] = {0};    
		for(size_t i = 0; i < str2.size(); ++i)   
		{ 
			hashtable[str2[i]]++;    
		}
		// ����str1��str1[i]ӳ��hashtable��Ӧλ��Ϊ0�����ʾ����ַ��� 
		// str2��û�г��ֹ�������+=��ret��ע��������ò�Ҫstr1.erases(i)
		// ��Ϊ�߱�������erase�����׳���   
		string ret;    
		for(size_t i = 0; i < str1.size(); ++i)    
		{
		if (hashtable[str1[i]] == 0)
			ret += str1[i];
		}        
		cout << ret << endl;  
		system("pause");
		return 0;
	}


	