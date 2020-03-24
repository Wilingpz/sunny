#include "RSA.h"
using namespace std;

//void test()
//{
//	RSA rsa;
//	rsa.getkey();
//	key key = rsa.getallkey();
//	DataType original = 2;
//	DataType encrypt = rsa.encrypt(original, key._ekey, key._nkey);
//	cout << "key:" << key._ekey << ' ' << key._dkey << ' ' << key._nkey << endl;
//	cout << "original:" << original << endl;
//	cout << "encrpt:" << encrypt << endl;
//	cout << "decode:" << rsa.decode(encrypt, key._dkey, key._nkey) << endl;
//	 
//}
void testRSA()
{
	RSA rsa;
	rsa.encrypt("test.txt", "test.encrypt.txt");
	rsa.decode("test.encrypt.txt", "test.decode.txt");
}
int main()
{
	testRSA();
	system("pause");
	return 0;
}