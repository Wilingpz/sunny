#pragma once

#include <vector>
#include <stack>

namespace wf{

	template <class T>
	class TreeNode//结点类
	{
		int m_bf;//平衡因子
		T m_data;//结点值
		TreeNode<T> * m_left;//结点的左右孩子指针以及双亲结点指针
		TreeNode<T> * m_right;
		TreeNode<T> * m_parent;
	public:
		TreeNode(const T & val = T()) ://构造函数
			m_bf(0),
			m_data(val),
			m_left(nullptr),
			m_right(nullptr),
			m_parent(nullptr)
		{}

		template <class T>
		friend class AVLTree;//AVL树
	};

	template <class T>
	class AVLTree
	{
		TreeNode<T> * m_root;//根节点

		void destroy(TreeNode<T> * root)//为了调用析构函数的时候用
		{
			if (root)
			{
				destroy(root->m_left);
				destroy(root->m_right);//后序递归删除
				delete root;
			}
		}

		void lRound(TreeNode<T> * pre)//左单旋
		{
			TreeNode<T> * parent = pre->m_parent; //将pre的双亲结点给parent
			TreeNode<T> * cur = pre->m_right;//将pre的右孩子赋给cur

			cur->m_parent = parent;//将pre的爸爸换给cur，即cur取代pre的位置
			if (parent)//当pre的爸爸存在时，让爸爸认儿子cur
			{
				if (parent->m_left == pre)
				{
					parent->m_left = cur;
				}
				else
				{
					parent->m_right = cur;
				}
			}
			else//pre的爸爸不存在则pre为根节点，直接换根
			{
				m_root = cur;
			}

			pre->m_right = cur->m_left;//pre认孩子
			if (cur->m_left)
			{
				cur->m_left->m_parent = pre;//cur的右孩子认爸爸
			}

			cur->m_left = pre;//pre变成cur的左孩子
			pre->m_parent = cur;//cur变成pre的爸爸

			cur->m_bf = pre->m_bf = 0;//调整平衡因子
		}

		void rRound(TreeNode<T> * pre)//右单旋
		{
			TreeNode<T> * parent = pre->m_parent; //同左单旋
			TreeNode<T> * cur = pre->m_left;

			cur->m_parent = parent;
			if (parent)
			{
				if (parent->m_left == pre)
				{
					parent->m_left = cur;
				}
				else
				{
					parent->m_right = cur;
				}
			}
			else
			{
				m_root = cur;
			}

			pre->m_left = cur->m_right;
			if (cur->m_right)
			{
				cur->m_right->m_parent = pre;
			}

			cur->m_right = pre;
			pre->m_parent = cur;

			cur->m_bf = pre->m_bf = 0;
		}

		void rlRound(TreeNode<T> * pre)//右左双旋
		{
			TreeNode<T> * right = pre->m_right;//把pre的右孩子赋给right
			TreeNode<T> * newroot = right->m_left;//把pre右孩子的左孩子赋给newroot

			int flag = newroot->m_bf;//记录newroot的平衡因子

			rRound(pre->m_right);//先给pre的右孩子右单旋
			lRound(pre);//再让pre左单旋

			if (flag == -1)//修改平衡因子
			{
				right->m_bf = 1;
			}
			else if (flag == 1)
			{
				pre->m_bf = -1;
			}
		}

		void lrRound(TreeNode<T> * pre)//左右双旋
		{
			TreeNode<T> * left = pre->m_left;
			TreeNode<T> * newroot = left->m_right;

			int flag = newroot->m_bf;//记录平衡因子

			lRound(pre->m_left);//left先左单旋
			rRound(pre);//pre再右单旋

			if (flag == -1)//修改平衡因子
			{
				pre->m_bf = 1;
			}
			else if (flag == 1)
			{
				left->m_bf = -1;
			}
		}
	public:
		AVLTree() ://构造函数
			m_root(nullptr)
		{}

		~AVLTree()//析构函数
		{
			destroy(m_root);
		}

		bool insert(const T &val)//插入
		{
			if (m_root == nullptr)//没有根结点直接插入为根节点
			{
				m_root = new TreeNode<T>(val);
				return true;
			}

			TreeNode<T> * cur = m_root;//把root赋给cur
			TreeNode<T> * pre = nullptr;//pre赋空

			while (cur)//根据value的值查找要插入的位置
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
					return false;
				}
			}
			//找到要插入的地方后，找一个结点把val存起来
			cur = new TreeNode<T>(val);
			//儿子认爸爸
			if (val < pre->m_data)//确定插入的是左子树还是右子树
			{
				pre->m_left = cur;
			}
			else
			{
				pre->m_right = cur;
			}

			cur->m_parent = pre;//爸爸认儿子

			while (pre)//调整pre的平衡因子，左孩子pre-1，右孩子pre加一
			{
				if (pre->m_left == cur)
				{
					pre->m_bf--;
				}
				else
				{
					pre->m_bf++;
				}

				if (pre->m_bf == 0)//不调整
				{
					break;
				}
				else if (pre->m_bf == 1 || pre->m_bf == -1)//向上调整它双亲的平衡因子
				{
					cur = pre;
					pre = pre->m_parent;
				}
				else//四种情况画图理解
				{
					if (pre->m_bf == 2)//平衡因子为2
					{
						if (cur->m_bf == 1)
						{
							lRound(pre);//左旋
						}
						else
						{
							rlRound(pre);//先左旋再右旋
						}
					}
					else
					{
						if (cur->m_bf == 1)
						{
							lrRound(pre);
						}
						else
						{
							rRound(pre);
						}
					}
					break;
				}
			}
			return true;
		}

		bool erase(const T &val)//删除
		{
			if (m_root == nullptr)
			{
				return false;
			}

			TreeNode<T> * cur = m_root;
			TreeNode<T> * pre = m_root;

			while (cur)
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
					break;
				}
			}

			if (cur == nullptr)
			{
				return false;
			}

			if (cur->m_left && cur->m_right)
			{
				TreeNode<T> * cur2 = cur->m_left;
				TreeNode<T> * pre2 = cur;

				if (cur2->m_right)
				{
					for (; cur2->m_right; pre2 = cur2, cur2 = cur2->m_right);
					pre2->m_right = cur2->m_left;
					cur2->m_left = cur->m_left;
				}

				cur2->m_right = cur->m_right;

				if (cur == pre)
				{
					m_root = cur2;
				}
				else
				{
					if (cur->m_data < pre->m_data)
					{
						pre->m_left = cur2;
					}
					else
					{
						pre->m_right = cur2;
					}
				}

				delete cur;
			}
			else if (cur->m_left)
			{
				if (cur == pre)
				{
					m_root = cur->m_left;
				}
				else
				{
					if (cur->m_data < pre->m_data)
					{
						pre->m_left = cur->m_left;
					}
					else
					{
						pre->m_right = cur->m_left;
					}
				}
				delete cur;
			}
			else
			{
				if (cur == pre)
				{
					m_root = cur->m_right;
				}
				else
				{
					if (cur->m_data < pre->m_data)
					{
						pre->m_left = cur->m_right;
					}
					else
					{
						pre->m_right = cur->m_right;
					}
				}

				delete cur;
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

		std::vector<T> InOrder()
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
					res.push_back(cur->m_data);
					s.pop();

					cur = cur->m_right;
				}
			}

			return res;
		}
	};



};