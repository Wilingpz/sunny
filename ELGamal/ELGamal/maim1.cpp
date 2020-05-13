#include <iostream>
#include"BigInt.h"

using namespace std;

int main()
{
	/*
	公开密钥y,g,p
	*/
	BigInt p("19"), g("10"), x("16"), y("4"), a("1");
	BigInt k("5"), s, r, m, k1;
	BigInt t1, t2;
	cout << "请输入m：" << endl;
	cin >> m;
	r = mod_fast(g, k, p);
	k1 = mod_inverse(k, p - a);
	s = ((m - x*r)*k1) % (p - a);
	cout << "r:" << r << endl;
	cout << "s:" << s << endl;
	cout << "接下来验证签名------->" << endl;
	t1 = fast(y, r);
	t2 = fast(r, s);
	cout << "t1:" << t1 << endl;
	cout << "t2:" << t2 << endl;
	if (((t1*t2) % p).values == mod_fast(g, m, p).values)
	{
		cout << "签名成功！" << endl;
	}
	else{
		cout << "签名失败！" << endl;
	}
	system("pause");
	return 0;
}
