//���Դ��С��
#include<stdio.h>
void CheckSystem1()
{
	int a = 1;
	int num = (*(char*)&a);//&a ȡ��a�ĵ�ַ��  (char*)&a ����a������ַ�ĵ�һ���ֽڵĵ�ַ
	printf("%d\n", num);//(*(char*)&a) ������ȡ����һ���ֽڱ�������ݴ�ӡ
	if (num == 1)
		printf("С��\n");
	else
		printf("���\n");
}
int main()
{
	CheckSystem1();
	getchar();
	return 0;
}
//2.����������
int CheckSystem2()
{
	union check
	{
		int num;
		char a;//2����������һ���ڴ�ռ䣬����2���������׵�ַ���
	}b;
	b.num = 1;//1����ڱ���num�ĵ�λ
	return (b.a == 1);//������a=1���൱�ڽ����ݵĵ�λ�浽���ڴ�ĵ͵�ַ������С��ģʽ
}
int main()
{
	int c = CheckSystem2();
	printf("c : %d\n", c);
	getchar();
	return 0;
}