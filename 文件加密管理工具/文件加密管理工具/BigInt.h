#pragma once//�бȽϳ���Ĵ�����boost
#include<string>
#include<utility>
#include<iostream>

class BigInt
{
public:
	//���캯��
	BigInt(){}
	BigInt(const std::string &num);
	BigInt(const int num);
	BigInt operator+(BigInt &num);
	BigInt operator-(BigInt &num);
	BigInt operator*(BigInt &num);
	BigInt operator/(BigInt &num);
	BigInt operator%(BigInt &num);
	//����ֵ��������ֵ�ķ�������Ϊ����
	BigInt& operator+=(BigInt &num);
	BigInt& operator-=(BigInt &num);
	BigInt& operator*=(BigInt &num);
	BigInt& operator/=(BigInt &num);
	BigInt& operator%=(BigInt &num);

	BigInt& operator++();//ǰ��++

	BigInt& operator++(int);//����++
	BigInt& operator--();//ǰ��--

	BigInt& operator--(int);//����--
	friend std::ostream& operator<<(std::ostream& _cout, BigInt &num);
		//Ϊʲô���롢��������������Ҫд����Ԫ����������
private:
	//��ǳ������
	std::string add(std::string num1, std::string num2);//ѡ�к�������F12����ʵ����ת����������Ĳ���
	std::string sub(std::string num1, std::string num2);
	std::string mul(std::string num1, std::string num2);
	std::pair<std::string,std::string> dev(std::string num1, std::string num2);//�����̺�����
	bool less(std::string& num1, std::string& num2);
	//�����þͲ���less("123","456")��Ϊ�������ַ���������string����Ȼ����ʽ����ת��������ת��������һ���������󣬹ʲ������ã�����ʹ��const
	//����һ��ͨ���ַ������б�ʾ
	std::string _number;
};