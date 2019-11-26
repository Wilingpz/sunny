//相乘    1、两个数的数位之和   2、两个数的数位之和减一
//相加    1、两个数中数位较长的一个  2、两个数中数位较长的一个加一

#include "HighAcc.h"


int main(){
	vector<int> v(10, 6);
	vector<int>v2 = v;
	vector<int>v3(v.begin() + 3, v.end() - 2);//end()最后元素后面一个的位置
	for (auto &i : v2){//rend()第一个前面一个的位置
		cout << i;
	}
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	vector <int>::iterator fi;
	vector <int>::reverse_iterator ri;
}
/*
int main(){
string s1("12345");
string s2("56789");

hightAcc num1(s1);
hightAcc num2(s1);

cout << (string)(num1 + num2);
system("pause");
return 0;
}*/
