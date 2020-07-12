#include<iostream>
using namespace std;
class String
{
private:
	char* _str;
public:
	String(const char* str = "jack")
	{
		_str = (char*)malloc(strlen(str) + 1);
		strcpy_s(_str, strlen(str) + 1, str);//Éî¿½±´¶østrcpyÊÇÇ³¿½±´
	}
	
	~String()
	{
		cout << "~String()" << endl;
		free(_str);
	}

	friend ostream& operator<<(ostream& out, const String& s)
	{
		out << s._str;
		return out;
	}



};
int main()
{
	String s1("hello");
	String s2("world");
	cout << s1 << endl << s2;
	
	system("pause");
	return 0;
}
