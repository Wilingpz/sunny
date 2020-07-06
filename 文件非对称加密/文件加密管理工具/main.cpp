//#define  _SCL_SECURE_NO_WARNINGS
#include "RSA.h"
#include"BigInt.h"
#include<boost/multiprecision/cpp_int.hpp>
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
void TestFile()
{
 //   ifstream fin("test.txt");
	////�ı���ʽ�򿪣�һ�㰴�տո���߻��ж�ȡ����
	//char a;
	//int b;
	//double c;
	//fin >> a;
	//fin >> b;
	//fin >> c;
	////cout << "a:" << a << "b:" << b << "c:" << c << endl;

	//ifstream finn("test.txt", ifstream::binary);
	//char buffer[100] = {0};
	//finn.read(buffer, 100);
	//cout << finn.gcount() << endl;
	//cout << buffer << endl;

	//�ַ���
	struct A
	{
		int a;
		char b;
		double c;
	};
	//�ַ���
	A temp;
	temp.a = 1;
	temp.b = 'b';
	temp.c = 2.2;
	//ofstream fout("testout.txt");
	//fout << temp.a << endl;
	//fout << temp.c << " " << temp.b << endl;
	
	
	//�ֽ���(�ı���Ķ���������)
	/*ofstream fout("testout2.txt",ofstream::binary);
	fout.write((char *)&temp, sizeof(A));
	fout.close();*/
	ifstream fin("testout2.txt", ifstream::binary);
	A b;
	fin.read((char*)&b, sizeof(A));
	cout << b.a << b.b << b.c << endl;
	
	//������û�б����������ռ�Ŀռ��Сһ��
}
void testRSA()
{
	RSA rsa;
	rsa.encrypt("test.txt", "test.encrypt.txt");
	rsa.decode("test.encrypt.txt", "test.decode.txt");
}


void testAdd()
{
	cout << "-------------------------BigIntAdd---------------------------------" << endl;
	BigInt bi;
	int a = 1198765342;//int���Ա�����������2147483647
	int b = 93476581;
	cout << a + b << endl;
	//cout << bi.add("1198765342", "93476581") << endl;
	BigInt aa = "198765342";
	BigInt bb = "93476581";
	cout << "aa" << aa << endl;
	cout << "bb" << bb << endl;
	cout << aa + bb << endl;
	cout << "aa" << aa << endl;
	cout << "bb" << bb << endl;

}
void testSub()
{
	cout << "-------------------------BigIntsub---------------------------------" << endl;
	BigInt bi;
	int a = 1198765342;//int���Ա�����������2147483647
	int b = 93476581;
	cout << a - b << endl;
	//cout << bi.sub("1198765342", "93476581") << endl;
	BigInt aa = "198765342";
	BigInt bb = "93476581";
	cout << "aa" << aa << endl;
	cout << "bb" << bb << endl;
	cout << aa - bb << endl;
	cout << "aa" << aa << endl;
	cout << "bb" << bb << endl;
}
void testmul()
{
	cout << "-------------------------BigIntmul---------------------------------" << endl;
	BigInt bi;
	int a = 11;//int���Ա�����������2147483647
	int b = 2;
	cout << a * b << endl;
	//cout << bi.mul("11", "2") << endl;
	BigInt aa = "9834";
	BigInt bb = "99235";
	cout << "aa" << aa << endl;
	cout << "bb" << bb << endl;
	cout << aa * bb << endl;
	cout << "aa" << aa << endl;
	cout << "bb" << bb << endl;
}
void testdev()
{
	cout << "-------------------------BigIntdev---------------------------------" << endl;
	BigInt bb = "9834";
	BigInt aa = "99235";
	cout << "aa" << aa << endl;
	cout << "bb" << bb << endl;

	cout << aa / bb << endl;
	cout << "aa" << aa << endl;
	cout << "bb" << bb << endl;


	cout << aa%bb << endl;
	cout << "aa" << aa << endl;
	cout << "bb" << bb << endl;

	
}
void testboostBigInt()
{
	//boost::multiprecision::cpp_int ci;

	//ci = 465823920849375867187364757333328390283926483654734091;
	//������̫�󣬶���int��������ֻ�ܱ�ʾʮλ��42�ھ�ǧ
	//char num[100] = "12356438574395320340836573829035367289";
	//ci = num;
	string num = "12356438574395320340836573829035367289";
	//ci = num;
	//���ｫ���εĹ��캯���������ˣ���֧�ֵ��ι��캯������ʽ����ת��
	boost::multiprecision::cpp_int anum(num);//��������
	//��Ҫ�����캯��
    cout << anum << endl;
	cout << anum + 1 << endl;
	boost::multiprecision::int1024_t cpp1024(num);//��ʾ����λ���ǹ̶��ģ�ֻ��1024λ
	boost::multiprecision::int1024_t cpp1024_2 = boost::multiprecision::int1024_t(1) << 1023;
	//�ȹ�����һ��������������ʼ��Ϊ1����������1024λ
	for ( boost::multiprecision::int1024_t i = 0; i < cpp1024_2; ++i)
	{

	}
	//���ڴ�����˵ִ�ж��Ƿǳ���ʱ��
	//����ͨ������������鿴����Ӧ�õ�cup�������
	cout << "finish��" << endl;
}
void test()
{
	long s = 546763;
	char k = 0;
	k = s;
	cout << k << endl;

}
void testBoostRandom()
{
	boost::random::mt19937 gen(time(NULL));
	boost::random::uniform_int_distribution<DataType>dist(0, DataType(1)<<1023);
	for (int i = 0; i < 100; ++ i)        //����         ��Χ
	{
		DataType num = dist(gen);
		cout << num << endl;//�����Լ���������������
	}
}

int main()
{
	//testAdd();
	//testSub();
	//testmul();
	//testdev();
	//testboostBigInt();
	//test();
	testRSA();
	//testBoostRandom();
	system("pause");
	return 0;
}
//���ּ���ǰ��aa��bbֵ����ͬ�����������ԭ������Ϊ����������
//��������ʵ������������ֵ������������������޸����������Ĳ���