//���    1������������λ֮��   2������������λ֮�ͼ�һ
//���    1������������λ�ϳ���һ��  2������������λ�ϳ���һ����һ

#include "HighAcc.h"


int main(){
	vector<int> v(10, 6);
	vector<int>v2 = v;
	vector<int>v3(v.begin() + 3, v.end() - 2);//end()���Ԫ�غ���һ����λ��
	for (auto &i : v2){//rend()��һ��ǰ��һ����λ��
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
