#pragma once
#include<cassert>
namespace pz
{

	//结点类型
	template<class T>
	struct _list_node
	{
		_list_node<T>* _next;
		_list_node<T>* _prev;
		T _data;

		_list_node(const T& x=T())
			:_data(x)
			, _next(nullptr)
			, _prev(nullptr)
		{}
	};

	//迭代器
	//_list_iterator<T,T&,T*>
	//_list_iterator<T,const T&,const T*>
	template<class T,class Ref,class Ptr>
	struct _list_iterator
	{
		typedef _list_node<T> Node;
		typedef _list_iterator<T, Ref, Ptr> Self;

		Node* _node;

		_list_iterator(Node* node)//封装一个节点类型的指针让其成为迭代器
			:_node(node)
		{}
		//*it
		Ref operator*()//返回值是T&或constT&
		{
			return _node->_data;
		}
		//++it
		Self& operator++()
		{
			_node = _node->_next;
			return *this;
		}
		//it++
		Self operator++(int)
		{
			Self tmp(*this);
			++(*this);
			return tmp;
		}
		//--
		Self operator--()
		{
			_node = _node->_prev;
			return *this;
		}
		Self operator--(int)
		{
			Self tmp(*this);
			-- (*this);
			return tmp;
		}
	    //!=
		bool operator!=(const Self& it)//传进来的是一个迭代器
		{
			return _node != it._node;
		}

		//->
		Ptr operator->()//返回类型是T*或const T*
		{
			return &_node->_data;
		}//主要用于自定义类型内容的输出

	};
	
	
	template<class T>//带头双向循环链表
	class list
	{
		typedef _list_node<T> Node;
	public:

		typedef _list_iterator<T,T&,T*> iterator;//普通迭代器
		typedef _list_iterator<T, const T&, const T*> const_iterator;//const迭代器
		//根据传入的类型的不同，来确定是const迭代器还是普通迭代器

		//要写成普通版本和const版本
		iterator begin()
		{
			return iterator(_head->_next);
		}
		iterator end()
		{
			return iterator(_head);
		}
		const_iterator begin()const//返回的是const迭代器
		{
			return const_iterator(_head->_next);
		}
		const_iterator end()const
		{
			return const_iterator(_head);
		}


		//构造函数
		list()
		{
			_head = new Node;//申请头节点
			_head->_next = _head;
			_head->_prev = _head;
		}
		//拷贝构造和赋值运算符重载
		list(const list<T>& it)//不存在的
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;

			const_iterator l = it.begin();
			while (l!=it.end())
			{
				push_back(*l);
				++l;
			}

		}
		list<T>& operator=(const list<T>& it)//赋值运算符重载有自己的头结点
		{
			if (this != &it)//不用自己给自己赋值
			{
				clear();
				for (auto &i : it)
				{
					push_back(i);
				}
			}
			return *this;
		}
		//新写法
		list<T>& operator=(list<T>& it)
		{
			swap(_head, it._head);
			return *this;
		}
		
		//析构函数
		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}
		//clear
		void clear()
		{
			iterator it = begin();
			while (it!=end())
			{
				erase(it++);
			}
		}
		//push_back
		void push_back(const T& x)
		{
			/*Node* tail = _head->_prev;
			Node* newnode = new Node(x);

			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;*/
			insert(end(), x);
		}
		void pop_back()
		{
			//erase(iterator(_head->_prev));
			erase(--end());
		}
		void push_front(const T& x)
		{
			insert(begin(), x);
		}
		void pop_front()
		{
			erase(begin());
		}

		void insert(iterator pos, const T& x)//在pos位置前进行插入
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* newnode = new Node(x);

			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;
		}
		void erase(iterator pos)
		{
			assert(pos != end());//头节点不能删
			
			Node* cur = pos._node;
			Node*prev = cur->_prev;
			Node*next = cur->_next;
			delete cur;
			
			prev->_next = next;
			next->_prev = prev;
		}
	private:
		Node* _head;//头结点

	};

	void Print(const list<int>& l)//传参一般要用到const 迭代器
	{
		list<int>::const_iterator it = l.begin();
		while (it!=l.end())
		{
			//只能读，不能写
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;
	}
	void test_list()
	{
		list<int>l;
		l.push_back(1);
		l.push_back(2);
		l.push_back(3);
		l.push_back(4);

		Print(l);
		l.push_front(0);
		Print(l);
		l.insert(l.begin(),2);
		Print(l);

		l.pop_back();
		Print(l);
		l.pop_front();
		Print(l);
		l.erase(l.begin());
		Print(l);

		list<int>i(l);
		i.push_back(10);
		i.push_back(20);
		i.push_back(30);
		Print(i);

		l = i;
		Print(l);



		/*list<int>::iterator it = l.begin();
		while (it!=l.end())
		{
			std::cout << *it << " ";
			++it;
		}
	   std::cout << std::endl;*/

		
	}
}