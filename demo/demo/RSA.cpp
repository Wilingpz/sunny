#include"RSA.h"


RSA::RSA()
{
	getkey();

}
void RSA::encrypt(const char* filename, const char* fileout)
{
	std::ifstream fin(filename, std::ifstream::binary);//文件读取模式为二进制
	std::ofstream fout(fileout, std::ifstream::binary);//头文件<fstream>
	if (!fin.is_open())
	{
		perror("input file open failed!");
		return;
	}
	char *buffer = new char[NUMBER];//从文件每次读取这么多数据
	DataType * bufferout = new DataType[NUMBER];//按块输出
	while (!fin.eof())//不到文件末尾
	{
		fin.read(buffer, NUMBER);
		int count = fin.gcount();//最近一次读到的字节数（有可能比NUMBER小）
		for (int i = 0; i < count; i++)
		{
			bufferout[i] = encrypt((DataType)buffer[i], _key._ekey, _key._nkey);
		}
		fout.write((char*)bufferout, count * sizeof(DataType));//总共要写的字节数（存放次数*类型字节数）
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
	/*i=0……最后一位    k^ekey %nkey  */
	DataType Ai = k;
	DataType msgE = 1;//存储结果
	while (ekey)//当指数不为0的时候
	{
		if (ekey & 1)//该位二进制为1则进入
		{
			msgE = (msgE * Ai) % nkey;

		}
		ekey >>= 1;
		Ai = (Ai * Ai) % nkey;//新的Ai相当于旧的Ai的平方模nkey
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
		prime = rand() % 100 + 2;//产生2到102之间的任意数
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
	//p1和p2互质则f(mn)=f(m)f(n)
	//若n为质数则f(n)=n-1
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
	DataType dkey = euler / ekey;//搜索法
	while (1)
	{
		if ((dkey*ekey) % euler == 1)
		{
			return dkey;
		}
		++dkey;
	}
}
//辗转相除法
//a%b=c 当c不为0
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