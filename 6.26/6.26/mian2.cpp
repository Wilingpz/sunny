//���֪���ṹ����ĳ����Ա����ڽṹ����ʼλ�õ�ƫ����offsetof(s,a) (size_t) &(((s*)0)->a)
//����÷��������Ǹ��߱�������һ��ָ��ָ��ṹ��s��������ֵ��0��Ȼ������ȡ�ṹ���е�a��a�ĵ�ַ����a��ƫ�����ˡ�
#include<iostream>
#include<cstdlib>
using namespace std;
#define offsetof(s,a) (size_t) &(((s*)0)->a)

struct a{
	int m;
	char n;
	double c;

};
#pragma pack(4)
struct b{
	char o;
	double p;
	int j;
};
#pragma pack;
int main()
{
	cout << "a���ڴ��СΪ" << sizeof(a) << endl;
	cout << "b���ڴ��СΪ" << sizeof(b) << endl;
	cout << offsetof(b, p) << endl;
	system("pause");
}
