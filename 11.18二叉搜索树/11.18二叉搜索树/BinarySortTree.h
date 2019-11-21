#pragma once

#include <vector>
#include <stack>

namespace wf{

	template <class T>
	class TreeNode//结点的类
	{
		T m_data;
		TreeNode<T> * m_left;
		TreeNode<T> * m_right;
	public:
		TreeNode(const T & val = T()) :
			m_data(val),
			m_left(nullptr),
			m_right(nullptr)
		{}

		template <class T>
		friend class BinarySortTree;//一个类作为另一个类的友元的写法
	};

	template <class T>
	class BinarySortTree//二叉搜索树的类
	{
		TreeNode<T> * m_root;//这里是一个TreeNode<T>的指针类型

		void destroy(TreeNode<T> * root)//destory函数私有，使对象不能调用，只用在析构函数中
		{
			if (root)//采用后序的递归删除
			{
				destroy(root->m_left);
				destroy(root->m_right);
				delete root;
			}
		}
	public:
		BinarySortTree() :
			m_root(nullptr)//构造函数
		{}

		~BinarySortTree()//析构函数
		{
			destroy(m_root);//因为析构函数不能传参，所以在写了destory函数在这里调用
		}

		bool insert(const T &val)//插入操作
		{
			if (m_root == nullptr)//如果根节点为空，直接将该数放在根节点上
			{
				m_root = new TreeNode<T>(val);//这里会调用构造函数
				return true;//表示插入成功
			}

			TreeNode<T> * cur = m_root;//根节点不为空就把根节点赋给cur
			TreeNode<T> * pre = nullptr;//pre记录插入位置的父节点
			//查找插入位置时，最后一定会使cur为空而跳出下面的while循环
			while (cur)//当cur不为空时
			{
				if (val < cur->m_data)//要插入的值小于根节点的值，那么该值应该在根节点的左边
				{
					pre = cur;//把cur的值赋给pre
					cur = cur->m_left;//把cur的左孩子赋给cur
					//val一直小于cur的值则一直重复该操作
				}
				else if (val > cur->m_data)//要插入的值大于cur的值，那么该值应该在根节点的右边
				{
					pre = cur;
					cur = cur->m_right;
				}
				//重复上述操作直到cur为空
				else
				{
					return false;//表示树中该值已存在返回插入失败
				}
			}

			cur = new TreeNode<T>(val);//新申请一个节点，把val的值赋给它
			if (val < pre->m_data)//val的值小于其父节点的值，插入在父节点左边
			{
				pre->m_left = cur;
			}
			else//val的值小于其父节点的值，插入在父节点左边
			{
				pre->m_right = cur;
			}

			return true;//返回插入成功
		}

		bool erase(const T &val)//删除操作
		{
			if (m_root == nullptr)
			{
				return false;//如果根节点为空，则树不存在，返回删除失败
			}

			TreeNode<T> * cur = m_root;
			TreeNode<T> * pre = m_root;//这里让pre=m_root为了预防要删除的结点是根节点

			while (cur)//常规的查找操作
			{
				if (val < cur->m_data)
				{
					pre = cur;
					cur = cur->m_left;
				}
				else if (val > cur->m_data)
				{
					pre = cur;
					cur = cur->m_right;
				}
				else
				{
					break;//如果找到这个数了就跳出循环，此时cur就是要删的那个数
				}
			}

			if (cur == nullptr)//如果没有找到这个数，返回删除失败
			{
				return false;
			}

			if (cur->m_left && cur->m_right)//当这个数的左右子树都不为空时
			{
				//把cur赋给pre2；把cur的左子树赋给cur
				TreeNode<T> * cur2 = cur->m_left;
				TreeNode<T> * pre2 = cur;
				//找到cur的左子树的最右子树继承cur的位置
				if (cur2->m_right)//如果右子树存在
				{
					for (; cur2->m_right; pre2 = cur2, cur2 = cur2->m_right);//找到最右的子树来继承cur
					pre2->m_right = cur2->m_left;//如果cur2有左子树就把他给cur2父节点的右子树，没有的话就给一个空，不影响
					cur2->m_left = cur->m_left;//继承cur的左子树
				}

				cur2->m_right = cur->m_right;//（当它的左子树没有右子树时）直接继承它的右子树

				if (cur == pre)
				{
					m_root = cur2;//如果删除的是根节点，则继承cur的左右孩子关系后直接把cur2赋给m_root
				}
				else
				{
					if (cur->m_data < pre->m_data)//继承cur的父亲关系
					{
						pre->m_left = cur2;
					}
					else
					{
						pre->m_right = cur2;
					}
				}
				delete cur;//删除cur
			}
			else if (cur->m_left)//如果只有左子树存在
			{
				if (cur == pre)
				{
					m_root = cur->m_left;////如果删除的是根节点，直接让它的左子树成为m_root
				}
				else//删除的不是根节点
				{
					if (cur->m_data < pre->m_data)//cur的左子树继承cur的父亲关系
					{
						pre->m_left = cur->m_left;
					}
					else
					{
						pre->m_right = cur->m_left;
					}
				}
				delete cur;//删除cur
			}
			else//如果只有右子树存在
			{
				if (cur == pre)
				{
					m_root = cur->m_right;//删除的为根节点时，直接让cur右子树编程m_root即可
				}
				else//删除的不是根节点时
				{
					if (cur->m_data < pre->m_data)//让它继承cur的父亲关系
					{
						pre->m_left = cur->m_right;
					}
					else
					{
						pre->m_right = cur->m_right;
					}
				}

				delete cur;//删除cur
			}
		}
		/*
		看是不是有左右子树：
		①左右子树都有：
		a、左子树没有右孩子
		直接让左孩子继承自己的右孩子和父亲
		b、左子树有右孩子
		一路向右，找到最后的一个右孩子，然后将这个孩子的
		左子树挂在它父亲的右子树上，然后让它继承要删除节
		点的人际关系（左右子树和父亲）
		当要删除的节点是根节点时，不用继承父亲关系，但要修改
		根节点指向。
		②只有左子树
		直接让左子树继承自己的父亲关系，如果要删的是根，那么
		直接换根即可。
		③其他
		直接让右子树（或者空）继承自己的父亲关系，其他同上
		*/

		std::vector<T> InOrder()//中序遍历
		{
			std::stack<TreeNode<T> *> s;
			std::vector<T> res;
			TreeNode<T> * cur = m_root;

			while (cur || !s.empty())
			{
				for (; cur; cur = cur->m_left)
				{
					s.push(cur);
				}

				if (!s.empty())
				{
					cur = s.top();
					res.push_back(cur->m_data);//按照二叉树的中序遍历放在vector容器中了
					s.pop();

					cur = cur->m_right;
				}
			}
			return res;
		}
	};
};