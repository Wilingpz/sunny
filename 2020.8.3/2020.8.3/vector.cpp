#include<iostream>
#include"vector.h"
using namespace std;


int main()
{

	pz::test();	
	system("pause");
	return 0;
}

/*
memxxx ���ֽڴ���
int a[10];
memset(a,0,sizeof(int)*10); 
memset(a,1,sizeof(int)*10); 
memset(a,1,sizeof(int)*10);


memset()����ԭ����
extern void *memset(void *buffer, int c, int count)        
buffer��Ϊָ���������,

c���Ǹ���buffer��ֵ,

count����buffer�ĳ���.


���������socket�ж������������.��:ԭ����memset(buffer, 0, sizeof(buffer))



c++���ں������const�����壺
�� ���Ƕ������ĳ�Ա�����У�������һЩ��Ա�������ı�������ݳ�Ա��Ҳ����˵����Щ������"ֻ��"������
   ����һЩ����Ҫ�޸������ݳ�Ա��ֵ������Ѳ��ı����ݳ�Ա�ĺ���������const�ؼ��ֽ��б�ʶ����Ȼ������߳���Ŀɶ���
*/