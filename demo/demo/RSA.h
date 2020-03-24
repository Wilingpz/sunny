#pragma once

#include<iostream>
#include<time.h>
#include<math.h>
#include<fstream>

#define NUMBER 256

typedef long DataType;//long����ռ8���ֽ�

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
public:
	RSA();
	void decode(const char* filename, const char* fileout);//�ļ��洢·�������ܺ��ļ��Ĵ洢·��
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
	key getallkey();
};