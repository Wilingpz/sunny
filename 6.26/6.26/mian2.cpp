//如何知道结构体中某个成员相对于结构体起始位置的偏移量offsetof(s,a) (size_t) &(((s*)0)->a)
//这个用法就是我们告诉编译器有一个指针指向结构体s，而它的值是0，然后我们取结构体中的a，a的地址就是a的偏移量了。
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
	cout << "a的内存大小为" << sizeof(a) << endl;
	cout << "b的内存大小为" << sizeof(b) << endl;
	cout << offsetof(b, p) << endl;
	system("pause");
}
