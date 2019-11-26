#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cstring>//memset
using namespace std;

#define MAXSIZE 10000
class hightAcc{
	char m_data[MAXSIZE];//高精度存数一个char一位
	size_t m_size;//数字长度
public:
	hightAcc(string s) ://传string 类型的参数构造
		m_size(s.size())
	{
		memset(m_data, 0, MAXSIZE);//清零
		string::reverse_iterator i;//反向迭代器（需要进行运算的字符反向存储
		//比较容易进行计算）
		int j = 0;
		for (i = s.rbegin(); i != s.rend(); i++){
			m_data[j] = *i - '0';//将其变为数字，存入m_data里
			j++;
		}
	}

	hightAcc() ://无参构造
		m_size(1)
	{
		memset(m_data, 0, MAXSIZE);
	}

	hightAcc operator +(const hightAcc &s) const//重载+  第一个const表示&s不能改变
		//第二个const表示隐含的this指针指向不可以改变
	{
		hightAcc res;//存储结果的变量
		size_t maxsize = m_size > s.m_size ? m_size : s.m_size;
		int i, tmp;

		for (i = 0; i < maxsize; i++){
			tmp = m_data[i] + s.m_data[i] + res.m_data[i];//res.m_data[]
			//这里无参构造为0了，每一位相加
			res.m_data[i] = tmp % 10;//取出个位
			res.m_data[i + 1] = tmp / 10;//进位
		}
		res.m_size = maxsize + res.m_data[i];//最高位为1加1，否则加0
		return res;
	}

	hightAcc operator *(const hightAcc &s) const{
		hightAcc res;
		int i, j, tmp;

		if (m_size == 1 && m_data == 0 ||
			s.m_size == 1 && s.m_data == 0){
			return res;
		}

		for (i = 0; i < m_size; i++){
			for (j = 0; j < s.m_size; j++){
				tmp = m_data[j] * s.m_data[j] + res.m_data[i + j];
				res.m_data[i + j] = tmp % 10;
				res.m_data[i + j + 1] += tmp / 10;
			}
		}
		res.m_size = m_size + s.m_size - !res.m_data[i + j - 1];
	}

	operator string (){//强转运算符的重载，不能有返回值
		string s;
		int i;
		for (i = m_size - 1; i >= 0; i--){
			s.push_back(m_data[i] + '0');//转化为字符进行打印
		}
		return s;
	}
};
