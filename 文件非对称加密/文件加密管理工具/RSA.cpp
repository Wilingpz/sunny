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
			bufferout[i] = encrypt((DataType)buffer[i], _key._ekey, _key._nkey);//���ܺ��������Datatype���ͣ����ܺ�õ�����һ��������
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
	DataType *buffer = new DataType[NUMBER];//��������ļ���Datatype���ʹ�С��
	char* bufferout = new char[NUMBER];
	while (!fin.eof())
	{
		fin.read((char*)buffer, NUMBER*sizeof(DataType));
		int num = fin.gcount();//���ܺ��������datatype���ͣ����Խ���ʱ���յ�Ҳ��datatype
		num /= sizeof(DataType);
		for (int i = 0; i < num; i++)
		{
			bufferout[i] = (char)decode(buffer[i], _key._dkey, _key._nkey);
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
	std::cout << "prime1: " << prime1 << std::endl;
	DataType prime2 = GetPrime();
	while (prime1 == prime2)
	{
		prime2 = GetPrime();
	}
	std::cout << "prime2: " << prime2 << std::endl;
	_key._nkey = Getnkey(prime1, prime2);
	std::cout << "getnkey finish!" << std::endl;
	std::cout << "nkey: " <<_key._nkey<< std::endl;
	DataType euler = GetEuler(prime1,prime2);
	std::cout << "euler finish!" << std::endl;
	std::cout << "euler: " <<euler<< std::endl;
	_key._ekey = Getekey(euler);
	std::cout << "getekey finish!" << std::endl;
	std::cout << "ekey: " << _key._ekey<<std::endl;
	_key._dkey = Getdkey(_key._ekey,euler);
	std::cout << "getdkey finish!" << std::endl;
	std::cout << "dkey: " <<_key._dkey<<std::endl;
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
			msgE = (msgE * Ai) % nkey;//A0����k
		}  
			ekey >>= 1;
			Ai = (Ai * Ai) % nkey;//�µ�Ai�൱�ھɵ�Ai��ƽ��ģnkey
	}
	return msgE;
	//return (DataType)pow(k, ekey)%nkey ;//�����������������Լӽ��ܽ������
	//ȡģҪ������������������������ȷ����ǿת
}
DataType RSA::decode(DataType k, DataType dkey, DataType nkey)
{
	return encrypt(k, dkey, nkey);
}
DataType RSA::GetPrime()
{
	std::cout << "getPrime()" << std::endl;
	brdm::mt19937 gen(time(NULL));//����
	brdm::uniform_int_distribution<DataType>dist(0, DataType(1) << 256);//����Χ

	//srand(time(NULL));
	DataType prime;
	while (1)
	{
		//prime = rand() % 100 + 2;//����2��102֮���������
		prime = dist(gen);
		//std::cout << "BigInt Random" << prime << std::endl;
		if (is_Prime(prime))
		{
			break;
		}
	}
	std::cout << "get prime finish!" << std::endl;
	return prime;
}
//bool RSA::is_Prime(DataType prime)
//{
//	std::cout << "IsPrime()" << std::endl;
//	if (prime <= 0)
//	{
//		return false;
//	}
//	for (int i = 2; i < sqrt(prime); i++)
//	{
//		if (prime%i == 0)
//		{
//			return false;
//		}
//	}
//	std::cout << "isPrime finish��" << std::endl;
//	return true;
//}
bool RSA::is_Prime(DataType data)
{
	brdm::mt11213b gen(time(NULL));
	if (miller_rabin_test(data, 25, gen))//���n�Ƿ�Ϊ����
	{
		if (miller_rabin_test((data - 1) / 2, 25, gen))//���data-1�Ƿ�Ϊ����
		{
			return true;
		}
	}
	return false;
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
	//srand(time(NULL));
	brdm::mt19937 gen(time(NULL));
	brdm::uniform_int_distribution<DataType>dist(2,euler);
	DataType ekey;
	while (1)
	{
		//ekey = rand() % euler;//ekey=rand()%euler+2;������ȡ0��1
		ekey = dist(gen);
		if (ekey > 1 && Getgcd(euler, ekey)==1)
		{
			return ekey;
		}
	}
	return ekey;
}
DataType RSA:: Getdkey(DataType ekey, DataType euler)
{
	//de%f(n)=1 
	DataType x = 0, y = 0;
	exGcd(ekey, euler, x, y);
	//ֻ�ں�x�Ƕ���
	//�任���ý�����Կ��һ���Ƚ�С������
	return (x%euler + euler) % euler;


	//DataType dkey = euler / ekey;//������
	//while (1)
	//{
	//	if ((dkey*ekey) % euler == 1)
	//	{
	//		return dkey;
	//	}
	//	++dkey;
	//}
}
//շת�����(ŷ������㷨)
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
//key RSA::getallkey()
//{
//	return _key;
//}
DataType RSA::exGcd(DataType a, DataType b, DataType &x, DataType &y)//������(����Ͳ������������ֵ)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	DataType gcd=exGcd(b, a%b, x, y);
	DataType x1 = x, y1 = y;
	x = y1;
	y = x1 - a / b*y1;
	return gcd;//�������Լ����x,y���������ã����Կ���ֱ�ӵõ�x��y��ֵ
}