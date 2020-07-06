#pragma once
//f12 ���������ڲ�ʵ��
//ctr+-���Է���ԭ����������

#include<iostream>
#include<time.h>
#include<math.h>
#include<fstream>
#include<boost/multiprecision/cpp_int.hpp>
#include<boost/multiprecision/random.hpp>
#include<boost/multiprecision/miller_rabin.hpp>

#define NUMBER 256

//typedef long DataType;//long����ռ8���ֽ�
typedef boost::multiprecision::int1024_t DataType;
namespace brdm = boost::random;

class key
{
public:
	DataType _ekey;//������Կ
	DataType _dkey;//������Կ
	DataType _nkey;//(e,n)(d,n)�е�n
};

/*
1��������������
2����n
3����f(n)
4������e  1<e<f(n)
5������d
*/
class RSA
{
	key _key;
	//������Խ����к���˽�У�ֻ�����ܺͽ��ܵ������ӿ�
public:	
	RSA();
	void decode(const char* filename,const char* fileout);//�ļ��洢·�������ܺ��ļ��Ĵ洢·��
	void encrypt(const char* filename, const char* fileout);
private:
	void getkey();
	DataType encrypt(DataType key, DataType ekey, DataType nkey);//����
	DataType decode(DataType key, DataType dkey, DataType nkey);//����
	DataType GetPrime();
	bool is_Prime(DataType prime);
	DataType Getnkey(DataType prime1, DataType prime2);
	DataType GetEuler(DataType prime1, DataType prime2);
	DataType Getekey(DataType euler);
	DataType Getdkey(DataType ekey, DataType euler);
	DataType Getgcd(DataType data1, DataType data2);
	DataType exGcd(DataType a, DataType b, DataType &x, DataType &y);
	//key getallkey();
};