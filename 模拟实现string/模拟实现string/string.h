namespace pzz
{
	class string
	{
	public:
		//构造函数，无参和带参的 
		string()
			:_str(nullptr)
		{}
		string(char* str)
			:_str(new char[strlen(str) + 1])//在堆上多申请一个空间存\0
		{
			strcpy(_str, str);//再将数据拷贝到代码段
		}
		string(const string&s)//深拷贝
			:_str(new char[strlen(s._str)+1])
		{
			strcpy(_str, s._str);
		}
		//全缺省
		/*
		string(char*str = "")//注意这里不可以给nullptr否则会出错，""只有一个\0
		:_str(new char[strlen(str)+1])
		{
			strcpy(_str,str);
		}
		*/
		
		//析构函数
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
		//[]重载
		char& operator[](size_t i)
		{
			return _str[i];
		}
		//赋值运算符重载
		//考虑连等所以要有返回值
		string operator=(const string& s)
		{
			if (this != &s)//防止自己给自己赋值
			{
				//新开空间,拷贝数据
				char* tmp = new char[strlen(s._str) + 1];
				strcpy(tmp, s._str);
				//删除_str的原有空间
				delete[]_str;
				//让_str指向tmp
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
		//拷贝构造(默认拷贝构造是浅拷贝)
		string s1("hello");
		string s2(s1);
		//s1先析构s2再析构会把指针置空，所以会出错
		string s3("world");
		s1 = s3; //会出错，因为 = 是浅拷贝
	}
}




