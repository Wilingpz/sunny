#include<iostream>
using namespace std;

//1��ֻ�ڶ��ϴ�������
/*
ֻ���ڶ��ϴ�������----������ֹ��ջ�ϴ����ռ䡣
ʵ�����������������̣����ٿռ�  �� ��ʼ������----���ú�����ζ����ջ
�Ͽ��ٿռ䣬����ֻҪ��ֹ��ʼ����Ҳ���ǽ�ֹʹ�ù��캯������-----���캯��˽
�л��������������ⲻ�ܷ��ʹ��캯����---���Ǹ������Ǽ�ʹ��new�ڶ�������Ŀ�
��Ҳ�޷�ʹ�ù��캯�����г�ʼ����---�Ͷ���û�й�ϵ�ĵ��ú����Ǿ�̬����---��
�������п��Զ���һ����̬��������ʵ��������---���������캯������Ϊ�����ö���
����һ�����󣨴�ʱ�������͵� ָ���������������������н����ÿ��Եõ�����
�����������Ϊ�������캯���Ĳ������ͻ������ջ��Ҳ���Դ��������ˣ�---��η�
ֹ���ÿ������캯��----��ʽ����������������Ͳ�������Ĭ�ϵĿ������캯����--
-���ǵ������ʽ����Ŀ������캯�����ɹ��е�Ȩ�ޣ���������ܵ��������������
���������Կ������캯���������˽�е�---�������ǵ�Ŀ����Ϊ�˲�ʹ�ÿ������캯
����������˽��������ֻ������������
*/
class Test
{
	Test()
	{
		cout << "Test()" << endl;
	}
	~Test()
	{
		cout << "~Test()" << endl;
	}
	Test(const Test&);//��������
	/*c++11���÷���
	Test(const Test& t) = detele;   ��ʹ�ÿ������캯���޷����ɣ�Ҳ���Ǹ��߱��������ú���ɾ������
	Test(const Test& t) = default;  ���߱��������ñ���������Ĭ�ϵĺ���*/
public:
	static Test* creat()
	{
		return new Test;//����ù��캯��
	}
};
int main1()
{
	//Test a;  //�޷�ֱ�ӹ������
	Test* a = Test::creat();//�ɹ���������
	system("pause");
	return 0;
}
//2��ֻ��ջ�ϴ�������
/*��new�Ĺ������ε����ɣ������ε�operator new �� ��λnew����ʽ*/
class Tmp
{
	void* operator new(size_t size);
	void operator delete(void*p);
public:
	Tmp()
	{
		cout << "Tmp()" << endl;
	}
};