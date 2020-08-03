namespace pzz
{
	class string
	{
	public:
		//���캯�����޲κʹ��ε� 
		string()
			:_str(nullptr)
		{}
		string(char* str)
			:_str(new char[strlen(str) + 1])//�ڶ��϶�����һ���ռ��\0
		{
			strcpy(_str, str);//�ٽ����ݿ����������
		}
		string(const string&s)//���
			:_str(new char[strlen(s._str)+1])
		{
			strcpy(_str, s._str);
		}
		//ȫȱʡ
		/*
		string(char*str = "")//ע�����ﲻ���Ը�nullptr��������""ֻ��һ��\0
		:_str(new char[strlen(str)+1])
		{
			strcpy(_str,str);
		}
		*/
		
		//��������
		~string()
		{
			delete[] _str;
			_str = nullptr;
		}
		//size()
		size_t size()
		{
			return strlen(_str);
		}
		//[]����
		char& operator[](size_t i)
		{
			return _str[i];
		}
		//��ֵ���������
		//������������Ҫ�з���ֵ
		string operator=(const string& s)
		{
			if (this != &s)//��ֹ�Լ����Լ���ֵ
			{
				//�¿��ռ�,��������
				char* tmp = new char[strlen(s._str) + 1];
				strcpy(tmp, s._str);
				//ɾ��_str��ԭ�пռ�
				delete[]_str;
				//��_strָ��tmp
				_str = tmp;
			}
			return *this;
		}
		//c_str()
		const char* c_str()
		{
			return _str;
		}
	private:
		char* _str;
	};



	void test_string1()
	{
		//��������(Ĭ�Ͽ���������ǳ����)
		string s1("hello");
		string s2(s1);
		//s1������s2���������ָ���ÿգ����Ի����
		string s3("world");
		s1 = s3; //�������Ϊ = ��ǳ����
	}
}




