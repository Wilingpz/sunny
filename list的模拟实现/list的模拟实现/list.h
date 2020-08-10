#pragma once
#include<cassert>
namespace pz
{

	//�������
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

	//������
	//_list_iterator<T,T&,T*>
	//_list_iterator<T,const T&,const T*>
	template<class T,class Ref,class Ptr>
	struct _list_iterator
	{
		typedef _list_node<T> Node;
		typedef _list_iterator<T, Ref, Ptr> Self;

		Node* _node;

		_list_iterator(Node* node)//��װһ���ڵ����͵�ָ�������Ϊ������
			:_node(node)
		{}
		//*it
		Ref operator*()//����ֵ��T&��constT&
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
		bool operator!=(const Self& it)//����������һ��������
		{
			return _node != it._node;
		}

		//->
		Ptr operator->()//����������T*��const T*
		{
			return &_node->_data;
		}//��Ҫ�����Զ����������ݵ����

	};
	
	
	template<class T>//��ͷ˫��ѭ������
	class list
	{
		typedef _list_node<T> Node;
	public:

		typedef _list_iterator<T,T&,T*> iterator;//��ͨ������
		typedef _list_iterator<T, const T&, const T*> const_iterator;//const������
		//���ݴ�������͵Ĳ�ͬ����ȷ����const������������ͨ������

		//Ҫд����ͨ�汾��const�汾
		iterator begin()
		{
			return iterator(_head->_next);
		}
		iterator end()
		{
			return iterator(_head);
		}
		const_iterator begin()const//���ص���const������
		{
			return const_iterator(_head->_next);
		}
		const_iterator end()const
		{
			return const_iterator(_head);
		}


		//���캯��
		list()
		{
			_head = new Node;//����ͷ�ڵ�
			_head->_next = _head;
			_head->_prev = _head;
		}
		//��������͸�ֵ���������
		list(const list<T>& it)//�����ڵ�
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
		list<T>& operator=(const list<T>& it)//��ֵ������������Լ���ͷ���
		{
			if (this != &it)//�����Լ����Լ���ֵ
			{
				clear();
				for (auto &i : it)
				{
					push_back(i);
				}
			}
			return *this;
		}
		//��д��
		list<T>& operator=(list<T>& it)
		{
			swap(_head, it._head);
			return *this;
		}
		
		//��������
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

		void insert(iterator pos, const T& x)//��posλ��ǰ���в���
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
			assert(pos != end());//ͷ�ڵ㲻��ɾ
			
			Node* cur = pos._node;
			Node*prev = cur->_prev;
			Node*next = cur->_next;
			delete cur;
			
			prev->_next = next;
			next->_prev = prev;
		}
	private:
		Node* _head;//ͷ���

	};

	void Print(const list<int>& l)//����һ��Ҫ�õ�const ������
	{
		list<int>::const_iterator it = l.begin();
		while (it!=l.end())
		{
			//ֻ�ܶ�������д
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