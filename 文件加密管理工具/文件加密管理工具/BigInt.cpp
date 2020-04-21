#include"BIgInt.h"


BigInt::BigInt(const std::string &num)//���ﴫconst��ʾֱ�Ӵ��ַ�������
	:_number(num)
	{}//����������������������


BigInt BigInt::operator+(BigInt &num)
{
	std::string tmp = add(_number, num._number);
	return BigInt(tmp);
}
BigInt BigInt::operator-(BigInt &num)
{
	std::string tmp = sub(_number, num._number);
	return BigInt(tmp);
}
BigInt BigInt:: operator*(BigInt &num)
{
	std::string tmp = mul(_number, num._number);
	return BigInt(tmp);

}
BigInt BigInt:: operator/(BigInt &num)
{
	std::pair<std::string,std::string> tmp = dev(_number, num._number);
	return BigInt(tmp.first);

}
BigInt BigInt:: operator%(BigInt &num)
{
	std::pair<std::string, std::string> tmp = dev(_number, num._number);
	return BigInt(tmp.second);
}

//ģ������Ĺ���
std::string BigInt::add(std::string num1, std::string num2)
{
	//�������
	int len1 = num1.size();
	int len2 = num2.size();
	int diffNum = abs(len1 - len2);
	int longsize = len1 > len2 ? len1 : len2;
	if (len1 < len2)
	{
		num1.insert(0, diffNum, '0');//��ǰ�油��
	}
	else if (len1>len2)
	{
		num2.insert(0, diffNum, '0');
	}
	std::string ret;//������
	ret.resize(longsize);//operator[]
	//��λ���
	int step = 0;//��λ
	for (int i = longsize - 1; i >= 0; i--)
	{
		ret[i] = (num1[i] - '0') + (num2[i] - '0')+step;//����Ҫ-0�����������
		ret[i] += '0';
		//����
		if (ret[i] > '9')
		{
			ret[i] -= 10;//�൱�ڰ�˹������ǰ��10��
			step = 1;
		}
		else
		{
			step = 0;
		}
	}
	if (step == 1)
	{
		ret.insert(0, 1, '1');
	}
	return ret;
}

std::string BigInt::sub(std::string num1, std::string num2)
{
	int len1 = num1.size();
	int len2 = num2.size();
	int diffNum = abs(len1 - len2);
	int longsize = len1 > len2 ? len1 : len2;
	if (len1 < len2)
	{
		num1.insert(0, diffNum, '0');//��ǰ�油��
	}
	else if (len1>len2)
	{
		num2.insert(0, diffNum, '0');
	}
	std::string ret;
	ret.resize(longsize);
	for (int i = longsize - 1; i >= 0; --i)
	{
		if (num1[i] < num2[i])
		{
			num1[i] += 10;
			//���¸�λ
			num1[i - 1]--;
		}
		ret[i] = (num1[i] - '0')-(num2[i]-'0')+'0';//������ֽ������;�����ɺ�Ҫ����ַ�
	}
	//ɾ��ǰ��0
	while (ret.size()>1&&ret[0]=='0')//������һλ������λΪ0
	{
		ret.erase(0, 1);//ɾ�����λ��1
	}
	return ret;
}
std::string BigInt::mul(std::string num1, std::string num2)
{
	 //�򻯳˷��Ĺ���  �Ƚ�С����*�Ƚϴ����
	if (num2.size() > num1.size())
	{
		swap(num2, num1);//��֤num2�ǽ�С����
	}
	std::string ret = "0";//ret:'\0'(�����д�Ļ�)���ڴ�Ž��
	for (int i = num2.size() - 1; i >= 0; --i)
	{
    //��ȡ��ǰ������Ӧ��ֵ
		int curnum2 = num2[i] - '0';
		int step = 0;//��λ
		//mum1�����Ըı�������������temp����ŵ�ǰλ�ĳ˻����
		std::string temp = num1;
		for (int j = num1.size() - 1; j >= 0; --j)
		{
			//��λ���
			temp[j] = (temp[j] - '0')*curnum2 + step;//����ֵ  ���9*9+9
			if (temp[j] > 9)
			{
				step = temp[j] / 10;
				temp[j] = temp[j] - step * 10;
			}
			else
			{
				step = 0;
			}
			temp[j] += '0';//��ԭΪ�ַ�
	    }
		//����ж��Ƿ���Ҫ��λ
		if (step > 0)
		{
			temp.insert(0, 1, step + '0');//�ڵ�0��λ�ò���һ������step+'0'
		}
		//����
		temp.append((num2.size() - 1) - i, '0');//�����ٸ�0
		//�ۼ�һ�μӷ��Ľ��
		ret = add(ret, temp);
	}
	return ret;
}
std::pair<std::string, std::string> BigInt::dev(std::string num1, std::string num2)//�����̺�����
{
	std::string ret;//��
	std::string rem = num1;//��������û�н��в���
	//�������Ŵ�
	int diffNum = num1.size() - num2.size();//Ĭ�ϱ������ȳ�����
	num2.append(diffNum, '0');
	for (int i = 0; i <= diffNum; i++)//����������ͬ�����Ĳ���Ҫִ�еĴ���
	{
		//��¼����ִ�еĴ���
		char count = '0';
		while (1)
		{
			if (less(rem, num2))//�жϼ����Ƿ���ڱ�����
			{
				break;//�������˾�break
			}
			rem = sub(rem, num2);//������-����
			++count;
		}
		ret += count;
		//������Сʮ��
		num2.pop_back();
	}
	//ɾ��ǰ��0
	while (ret.size() > 1 && ret[0] == '0')
	{
		ret.erase(0, 1);
	}
	//����<�̣�����>
	return make_pair(ret, rem);//����д���ͱ𣬾Ϳ�������һ��pair����
}
bool BigInt::less(std::string& num1, std::string& num2)
{
	if (num1.size() < num2.size())//���Ȳ���ͬ
	{
		return true;
	}
	if (num1.size() > num2.size())//���Ȳ���ͬ
	{
		return false;
	}
	//������ͬʱ,�ַ����Ƚϰ�˹����ֵ
	return num1 < num2;
}
std::ostream& operator<<(std::ostream& _cout, BigInt &num)
{
	_cout << num._number << std::endl;
	return _cout;
}