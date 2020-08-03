#include<assert.h>


namespace pz
{
	class string
	{
	public:
		string(const char*str = "")
		{
			_size = strlen(str);   //strlen计算长度遇到\0结束
			_capacity = _size;
			_str = new char[_capacity+1];//在堆上开辟一片空间
			strcpy(_str, str);//把str拷贝过去
		}
		//拷贝构造和赋值
		string(const string& s)
		{
			_size = s._size;
			_capacity = s._capacity;
			_str = new char[_capacity + 1];
			strcpy(_str, s._str);
		}
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				char*tmp = new char[s._capacity + 1];
				strcpy(tmp, s._str);
				delete[] _str;
				_str = tmp;
				_size = s._size;
				_capacity = s._capacity;
			}
			return *this;
		}
	
		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}


		//size()
		size_t size()const
		{
			return _size;
		}
		//capacity
		size_t capacity()const
		{
			return _capacity;
		}
		//[]重载
		char& operator[](size_t i)
		{
			assert(i < _size);
			return _str[i];
		}
		const char& operator[](size_t i)const//const放在函数后面表示成员函数只读不可改
		{
			assert(i < _size);
			return _str[i];
		}
		//c_str()
		const char* c_str()
		{
			return _str;
		}
		//迭代器
		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		//reserve
		void reserve(size_t n)
		{
			if (n > _capacity) 
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);	
				delete[]_str;
				_str = tmp;
				_capacity = n;
			}
		}
		//push_back
		void push_back(char ch)
		{
			if (_size == _capacity)//考虑增容问题
			{
				size_t newcapacity = _capacity == 0 ? 2 : 2 * _capacity;//以二倍进行增容
				reserve(newcapacity);
				//char*tmp = new char[newcapacity + 1];//newcapacity是开的有效空间，得多开一个空间留给\0
				//strcpy(tmp, _str);//将_str里面的内容拷贝到新空间tmp里面
				//delete[] _str;//释放原空间
				//_str = tmp;//指向新空间
				//_capacity = newcapacity;
			}
			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';//没有\0会出错
		}
		//append
		void append(const char* str)
		{
			size_t len = strlen(str);
			if (_size + len > _capacity)
		//这里没有以2倍增容，因为增容二倍不一定够
			{
				/*size_t newcapacity = _size + len;
				char*tmp = new char[newcapacity + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capacity = newcapacity;*/
				reserve(_size + len);
			}
			strcpy(_str + _size, str);//将str拷贝到从str+size（\0的位置）开始的位置
			_size += len;
		}
		//+=
		string& operator+=(const char* str)
		{
			this->append(str);
			return *this;
		}
		string& operator+=(char c)
		{
			this->push_back(c);
			return *this;
		}
		//resize
		void resize(size_t n, char ch='\0')
		{
			if (n<_size)
			{
				_str[n] = '\0';
				_size = n;
			}
			else
			{
				if (n>_capacity)
				{
					reserve(n);
				}
				for (size_t i = _size; i < n; i++)
				{
					_str[i] = ch;
				}
				_size = n;
				_str[_size] = '\0';
			}
		}
		//insert
		string& insert(size_t pos, char c)
		{
			assert(pos < _size);
			if (_size == _capacity)//考虑增容
			{
				size_t newcapacity = _capacity == 0 ? 2 : 2 * _capacity;//以二倍进行增容
				reserve(newcapacity);
			}
			int end = _size;
			while (end >= pos)
			{
				_str[end+1] = _str[end];
				--end;
				if (end == -1)
				{
					break;
				}
			}
			_str[pos] = c;
			++_size;
			return *this;
		}
		string& insert(size_t pos, const char* str)
		{
			assert(pos<_size);
			//考虑增容
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}
			int end = _size;//数组最后是\0
			while (end >= pos)
			{
				_str[end + len] = _str[end];
				--end;
				if (end == -1)
				{
					break;
				}
			}
			/*for (size_t i = 0; i < len; i++)
			{
				_str[pos] = str[i];
				pos++;
				++_size;
			}*/
			strncpy(_str + pos, str, len);
			_size += len;
			return *this;
		}
		//erase
		void erase(size_t pos, size_t len = npos)
		{
			if (len >= _size - pos)//string::npos在这里会是一个
			{
				_str[pos] = '\0';
			}
			else
			{
				size_t i = pos + len;
				while (i<=_size)
				{
					_str[i - len] = _str[i];
					++i;
				}
			}
			_size -= len;
		}
		//find
		size_t find(char ch, size_t pos = 0)
		{
			for (size_t i = pos; i < _size; i++)
			{
				if (_str[i] == ch)
				{
					return i;
				}
			}
			return npos;
		}
		size_t find(const char* str, size_t pos = 0)
		{
			char*p = strstr(_str+pos, str);//在_str里查找str第一次出现的位置
			if (p == nullptr)
			{
				return npos;
			}
			else
			{
				return p - _str;
			}
		}
		//rfind
		size_t rfind(char ch, size_t pos = npos)
		{
			if (pos != npos)
			{
				for (int i = pos; i >= 0; i--)
				{
					if (_str[i] == ch)
					{
						return i;
					}
				}
			}
			else if (pos==npos)
			{
				for (int i = _size; i >= 0; i--)
				{
					if (_str[i] == ch)
					{
						return i;
					}
				}
			}
			return npos;
		}
	

		//大小比较
		bool operator>(const string& s)
		{
			int ret = strcmp(_str, s._str);
			return ret > 0;
		}
		bool operator<(const string& s)
		{
			int ret = strcmp(_str, s._str);
			return ret < 0;
		}
		bool operator==(const string& s)
		{
			int ret = strcmp(_str, s._str);
			return ret == 0;
		}
		bool operator>=(const string& s)
		{
			return *this > s || *this == s;
		}
		bool operator<=(const string& s)
		{
			return !(*this>s);
		}
		bool operator!=(const string& s)
		{
			return !(*this == s);
		}
		
		
		static size_t npos;

		friend std::istream& operator>>(std::istream& in, string& s1);
	private:
		char* _str;
		//牵涉到扩容问题,所以要有size和capacity
		size_t _size;
		size_t _capacity;

	};
	size_t string::npos = -1;
	std::istream& operator>>(std::istream& in, string& s)
	{
		while (1)
		{
			char ch;
			ch=in.get();//ch=in.getline()
			if (ch == ' ' || ch == '\n')
			{
				break;
			}
			else
			{
				s += ch;//包含扩容问题
			}
		}
		return in;
	}
	std::ostream& operator<<(std::ostream& out, const string& s)
	{
		for (int i = 0; i < s.size(); ++i)
		{
			std::cout << s[i];
		}
		return out;
	}



	void test_str()
	{
		/*string s1("hello");
		s1.push_back('e');
		s1.append("lalalala");*/

		/*string s1, s2;
		std::cin >> s1 >> s2;
		std::cout << s1 << s2<<std::endl;*/


		/*for (auto&i : s1)//由迭代器实现 要支持itrator begin() end()
		{
		std::cout << i << std::endl;
		}*/

		/*string s2;
		s2 += "hello";
		s2 += 'a';
		std::cout << s2 << std::endl;*/

		/*string s2("hello");
		std::cout << s1 << std::endl;
		std::cout << s1.c_str() <<std::endl;
		*/

		/*string s3("wonderful");
		s3.insert(0,'x');
		std::cout << s3 << std::endl;

		s3.insert(0, "ABC");
		std::cout << s3 << std::endl;*/

		/*string s4("hello");
		s4.reserve(10);
		std::cout << s4 << std::endl;
		std::cout << s4.size() << std::endl;
		std::cout << s4.capacity() << std::endl << std::endl;

		s4.resize(8, 'x');
		std::cout << s4 << std::endl;
		std::cout << s4.size() << std::endl;
		std::cout << s4.capacity() << std::endl << std::endl;

		s4.resize(18, 'x');
		std::cout << s4 << std::endl;
		std::cout << s4.size() << std::endl;
		std::cout << s4.capacity() << std::endl << std::endl;*/

		/*string s5("hello");
		std::cout<<s5.find('c')<<std::endl; //返回无符号最大数4294967295
		std::cout<<s5.find("llo",1)<<std::endl;
		std::cout<<s5.find('l',5)<<std::endl;
		std::cout << s5.find('l') << std::endl;
		std::cout << s5.rfind('l') << std::endl;*/

		/*string s1("hello");
		std::cout << s1 << std::endl;
		string s2(s1);
		std::cout << s2 << std::endl;
		string s3("ab");
		std::cout << s3 << std::endl;
		s3 = s1;
		std::cout << s3 << std::endl;*/
       

	}
}