#include"RSA.h"


RSA::RSA()
{
	getkey();

}
void RSA::encrypt(const char* filename, const char* fileout)
{
	std::ifstream fin(filename, std::ifstream::binary);//�ļ���ȡģʽΪ������
	std::ofstream fout(fileout, std::ifstream::binary);//ͷ�ļ�<fstream>
	if (!fin.is_open())
	{
		perror("input file open failed!");
		return;
	}
	char *buffer = new char[NUMBER];//���ļ�ÿ�ζ�ȡ��ô������
	DataType * bufferout = new DataType[NUMBER];//�������
	while (!fin.eof())//�����ļ�ĩβ
	{
		fin.read(buffer, NUMBER);
		int count = fin.gcount();//���һ�ζ������ֽ������п��ܱ�NUMBERС��
		for (int i = 0; i < count; i++)
		{
			bufferout[i] = encrypt((DataType)buffer[i], _key._ekey, _key._nkey);
		}
		fout.write((char*)bufferout, count * sizeof(DataType));//�ܹ�Ҫд���ֽ�������Ŵ���*�����ֽ�����
	}
	delete[]bufferout;
	delete[]buffer;
	fin.close();
	fout.close();
}
void RSA::decode(const char* filename, const char* fileout)
{
	std::ifstream fin(filename, std::ifstream::binary);
	std::ofstream fout(fileout, std::ofstream::binary);
	if (!fin.is_open())
	{
		perror("file open failed!");
		return;
	}
	DataType *buffer = new DataType[NUMBER];
	char* bufferout = new char[NUMBER];
	while (!fin.eof())
	{
		fin.read((char*)buffer, NUMBER*sizeof(DataType));
		int num = fin.gcount();
		num /= sizeof(DataType);
		for (int i = 0; i < num; i++)
		{
			bufferout[i] = decode(buffer[i], _key._dkey, _key._nkey);
		}
		fout.write(bufferout, num);
	}
	delete[]bufferout;
	delete[]buffer;
	fout.close();
	fin.close();
}
void RSA::getkey()
{
	DataType prime1 = GetPrime();
	DataType prime2 = GetPrime();
	while (prime1 == prime2)
	{
		prime2 = GetPrime();
	}
	_key._nkey = Getnkey(prime1, prime2);
	DataType euler = GetEuler(prime1, prime2);
	_key._ekey = Getekey(euler);
	_key._dkey = Getdkey(_key._ekey, euler);
}
DataType RSA::encrypt(DataType k, DataType ekey, DataType nkey)
{
	/*i=0�������һλ    k^ekey %nkey  */
	DataType Ai = k;
	DataType msgE = 1;//�洢���
	while (ekey)//��ָ����Ϊ0��ʱ��
	{
		if (ekey & 1)//��λ������Ϊ1�����
		{
			msgE = (msgE * Ai) % nkey;

		}
		ekey >>= 1;
		Ai = (Ai * Ai) % nkey;//�µ�Ai�൱�ھɵ�Ai��ƽ��ģnkey
	}
	return msgE;
}
DataType RSA::decode(DataType k, DataType dkey, DataType nkey)
{
	return encrypt(k, dkey, nkey);
}
DataType RSA::GetPrime()
{
	srand(time(NULL));
	DataType prime;
	while (1)
	{
		prime = rand() % 100 + 2;//����2��102֮���������
		if (is_Prime(prime))
		{
			break;
		}
	}
	return prime;
}
bool RSA::is_Prime(DataType prime)
{
	if (prime <= 0)
	{
		return false;
	}
	for (int i = 2; i < sqrt(prime); i++)
	{
		if (prime%i == 0)
		{
			return false;
		}
	}
	return true;
}
DataType RSA::Getnkey(DataType prime1, DataType prime2)
{
	return  prime1*prime2;
}
DataType RSA::GetEuler(DataType prime1, DataType prime2)
{
	//p1��p2������f(mn)=f(m)f(n)
	//��nΪ������f(n)=n-1
	return (prime1 - 1)*(prime2 - 1);
}
DataType RSA::Getekey(DataType euler)
{
	//1<e<f(n)
	srand(time(NULL));
	DataType ekey;
	while (1)
	{
		ekey = rand() % euler;//ekey=rand()%euler+2;
		if (ekey > 1 && Getgcd(euler, ekey) == 1)
		{
			return ekey;
		}
	}
	return ekey;
}
DataType RSA::Getdkey(DataType ekey, DataType euler)
{
	//de%f(n)=1 
	DataType dkey = euler / ekey;//������
	while (1)
	{
		if ((dkey*ekey) % euler == 1)
		{
			return dkey;
		}
		++dkey;
	}
}
//շת�����
//a%b=c ��c��Ϊ0
//a=b   b=c
DataType RSA::Getgcd(DataType data1, DataType data2)
{
	DataType remainder;
	while (remainder = data1%data2)
	{
		data1 = data2;
		data2 = remainder;
	}
	return data2;
}
key RSA::getallkey()
{
	return _key;
}