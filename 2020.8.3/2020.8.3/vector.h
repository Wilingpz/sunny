#pragma once
#include<cassert>
namespace pz           //vector的成员变量和对象都在栈上
	                   //存储的数据在堆上，堆上空间大
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		vector()
			:_start(nullptr),
			_finish(nullptr),
			_endofstorage(nullptr)
		{}
		//拷贝构造1
		vector(const vector<T>&v)
		{
			_start = new T[v.capacity()];
			_finish = _start + v.size();
			_endofstorage = _start + v.capacity();
			memcpy(_start, v._start, sizeof(T)*v.size());
		}
		//拷贝构造2
		/*vector(const vector<T>&v)
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			reserve(v.capacity());
			for (const auto &i : v)
			{
				push_back(i);
			}
		}*/
		~vector()
		{
			delete[] _start;
			_start = _finish = _endofstorage = nullptr;
		}
		//=的重载1
		/*vector<T>& operator=(const vector<T>& v)
		{
			if (this != &v)
			{
				delete[]_start;
				_start = new T[v.capacity()];
				memcpy(_start, v._start, sizeof(T)*v.size());
				_finish = _start + v.size();
				_endofstorage = _start + v.capacity();
			}
			return *this;
		}*/
		//=的重载2
		vector<T>& operator=(vector<T>& v)
		{
			swap(v);
			return *this;
		}
		void swap(vector<T>&v)
		{
			//表示全局的swap
			::swap(_start, v._start);
			::swap(_finish, v._finish);
			::swap(_endofstorage, v._endofstorage);
		}

		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		const_iterator begin()const//只能读不能写
		{
			return _start;
		}
		const_iterator end()const
		{
			return _finish;
		}
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t sz = size();
				T*tmp = new T[n];
				if (_start)
				{
					memcpy(tmp, _start, sizeof(T)*sz);
					delete[]_start;
				}
				_start = tmp;
				_finish = tmp + sz;//_finish指的是最后一个数据的下一个位置
				_endofstorage = tmp + n;
			}
		}
		void push_back(const T& x)
		{
			/*if (_finish == _endofstorage)
			{
				size_t newcapacity = capacity() == 0 ? 2 : capacity() * 2;
				reserve(newcapacity);
			}
			*_finish = x;
			++_finish;*/
			insert(_finish, x);
		}
		void pop_back()
		{
			assert(_start < _finish);
			--_finish;
		}
		T& operator[](size_t n)
		{
			assert(n < size());
			return _start[n];
		}
		const T& operator[](size_t n)const //只读
		{
			assert(n < size());
			return _start[n];
		}
		void insert(iterator pos, const T&x)
		{
			assert(pos <= _finish);//注意原函数在_finish位置也可以插入数据
			if (_finish == _endofstorage)
			{
				size_t n = pos - _start;//保存pos到_start的距离
				size_t newcapacity = capacity() == 0 ? 2 : capacity() * 2;
				reserve(newcapacity);
				pos = _start + n;
			}
			//一旦增容就要考虑迭代器失效问题,扩容后pos失效
			iterator end = _finish - 1;
			while (end>=pos)//如果pos=_finish那么不进while循环
			{
				*(end + 1) = *end;
				--end;
			}
			*pos = x;
			++_finish;
		}
		iterator erase(iterator pos)//返回删除位置的下一个位置
		{
			assert(pos < _finish);
			iterator it = pos;
			while (it<_finish)
			{
				*it = *(it + 1);
				++it;
			}
			--_finish;
			return pos;//还是返回pos位置
		}
		void resize(size_t n, const T& val = T())//给的是T类型的缺省值
		{
			if (n < size())
			{
				_finish = _start + n;
			}
			else 
			{
				if (n > capacity())
				{
					reserve(n);
				}
				while (_finish < _start + n)
				{
					*(_finish) = val;
					_finish++;
				}
			}
		}
		size_t size()const
		{
			return _finish - _start;
		}
		size_t capacity()const//加const，为了拷贝构造传参的const类型可以用
		{
			return _endofstorage - _start;
		}

		
	private:
		iterator _start;
		iterator _finish;
		iterator  _endofstorage;
	};

	void Print(const vector<int>& v)
	{
		vector<int>::const_iterator it = v.begin();
		while (it != v.end())
		{
			std::cout << *it << ' ';
			++it;
		}
		std::cout << std::endl;
	}
	void test()
	{
		vector<int>v;
		
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		//std::cout << v.size() <<' '<< v.capacity() << std::endl;
		//v.insert(v.begin(), 0);
		//v.insert(v.end(), 6);
		/*vector<int>::iterator it = v.begin();
		while (it!=v.end())
		{
			std::cout << *it << " ";
			it++;
		}
		std::cout << std::endl;
		std::cout << v[3] << std::endl;*/
		/*v.resize(10);
		std::cout << v.size() << ' ' << v.capacity() << std::endl;
		Print(v);*/
		vector<int>v2(v);
		vector<int>v3 = v2;
		Print(v);
		Print(v2);
		Print(v3);

	}
}