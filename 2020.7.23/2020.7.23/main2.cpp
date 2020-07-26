#include <iostream>
#include <cstdlib>
using namespace std;

template <class numtype>
class Compare
{
	numtype x, y;
public:
	Compare(numtype a, numtype b)
	{
		x = a;
		y = b;
	}
	numtype max()
	{
		return(x > y) ? x : y;
	}
	numtype min()
	{
		return (x > y) ? y : x;
	}

};
int main()
{
	Compare<int>cmpl(3, 7);//定义对象cmpl，用于两个整数的比较
	cout << cmpl.max() << endl;
	system("pause");
	return 0;
}
