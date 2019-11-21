#pragma once

#include <vector>
#include <stack>

namespace wf{

	template <class T>
	class TreeNode//������
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
		friend class BinarySortTree;//һ������Ϊ��һ�������Ԫ��д��
	};

	template <class T>
	class BinarySortTree//��������������
	{
		TreeNode<T> * m_root;//������һ��TreeNode<T>��ָ������

		void destroy(TreeNode<T> * root)//destory����˽�У�ʹ�����ܵ��ã�ֻ��������������
		{
			if (root)//���ú���ĵݹ�ɾ��
			{
				destroy(root->m_left);
				destroy(root->m_right);
				delete root;
			}
		}
	public:
		BinarySortTree() :
			m_root(nullptr)//���캯��
		{}

		~BinarySortTree()//��������
		{
			destroy(m_root);//��Ϊ�����������ܴ��Σ�������д��destory�������������
		}

		bool insert(const T &val)//�������
		{
			if (m_root == nullptr)//������ڵ�Ϊ�գ�ֱ�ӽ��������ڸ��ڵ���
			{
				m_root = new TreeNode<T>(val);//�������ù��캯��
				return true;//��ʾ����ɹ�
			}

			TreeNode<T> * cur = m_root;//���ڵ㲻Ϊ�վͰѸ��ڵ㸳��cur
			TreeNode<T> * pre = nullptr;//pre��¼����λ�õĸ��ڵ�
			//���Ҳ���λ��ʱ�����һ����ʹcurΪ�ն����������whileѭ��
			while (cur)//��cur��Ϊ��ʱ
			{
				if (val < cur->m_data)//Ҫ�����ֵС�ڸ��ڵ��ֵ����ô��ֵӦ���ڸ��ڵ�����
				{
					pre = cur;//��cur��ֵ����pre
					cur = cur->m_left;//��cur�����Ӹ���cur
					//valһֱС��cur��ֵ��һֱ�ظ��ò���
				}
				else if (val > cur->m_data)//Ҫ�����ֵ����cur��ֵ����ô��ֵӦ���ڸ��ڵ���ұ�
				{
					pre = cur;
					cur = cur->m_right;
				}
				//�ظ���������ֱ��curΪ��
				else
				{
					return false;//��ʾ���и�ֵ�Ѵ��ڷ��ز���ʧ��
				}
			}

			cur = new TreeNode<T>(val);//������һ���ڵ㣬��val��ֵ������
			if (val < pre->m_data)//val��ֵС���丸�ڵ��ֵ�������ڸ��ڵ����
			{
				pre->m_left = cur;
			}
			else//val��ֵС���丸�ڵ��ֵ�������ڸ��ڵ����
			{
				pre->m_right = cur;
			}

			return true;//���ز���ɹ�
		}

		bool erase(const T &val)//ɾ������
		{
			if (m_root == nullptr)
			{
				return false;//������ڵ�Ϊ�գ����������ڣ�����ɾ��ʧ��
			}

			TreeNode<T> * cur = m_root;
			TreeNode<T> * pre = m_root;//������pre=m_rootΪ��Ԥ��Ҫɾ���Ľ���Ǹ��ڵ�

			while (cur)//����Ĳ��Ҳ���
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
					break;//����ҵ�������˾�����ѭ������ʱcur����Ҫɾ���Ǹ���
				}
			}

			if (cur == nullptr)//���û���ҵ������������ɾ��ʧ��
			{
				return false;
			}

			if (cur->m_left && cur->m_right)//���������������������Ϊ��ʱ
			{
				//��cur����pre2����cur������������cur
				TreeNode<T> * cur2 = cur->m_left;
				TreeNode<T> * pre2 = cur;
				//�ҵ�cur�������������������̳�cur��λ��
				if (cur2->m_right)//�������������
				{
					for (; cur2->m_right; pre2 = cur2, cur2 = cur2->m_right);//�ҵ����ҵ��������̳�cur
					pre2->m_right = cur2->m_left;//���cur2���������Ͱ�����cur2���ڵ����������û�еĻ��͸�һ���գ���Ӱ��
					cur2->m_left = cur->m_left;//�̳�cur��������
				}

				cur2->m_right = cur->m_right;//��������������û��������ʱ��ֱ�Ӽ̳�����������

				if (cur == pre)
				{
					m_root = cur2;//���ɾ�����Ǹ��ڵ㣬��̳�cur�����Һ��ӹ�ϵ��ֱ�Ӱ�cur2����m_root
				}
				else
				{
					if (cur->m_data < pre->m_data)//�̳�cur�ĸ��׹�ϵ
					{
						pre->m_left = cur2;
					}
					else
					{
						pre->m_right = cur2;
					}
				}
				delete cur;//ɾ��cur
			}
			else if (cur->m_left)//���ֻ������������
			{
				if (cur == pre)
				{
					m_root = cur->m_left;////���ɾ�����Ǹ��ڵ㣬ֱ����������������Ϊm_root
				}
				else//ɾ���Ĳ��Ǹ��ڵ�
				{
					if (cur->m_data < pre->m_data)//cur���������̳�cur�ĸ��׹�ϵ
					{
						pre->m_left = cur->m_left;
					}
					else
					{
						pre->m_right = cur->m_left;
					}
				}
				delete cur;//ɾ��cur
			}
			else//���ֻ������������
			{
				if (cur == pre)
				{
					m_root = cur->m_right;//ɾ����Ϊ���ڵ�ʱ��ֱ����cur���������m_root����
				}
				else//ɾ���Ĳ��Ǹ��ڵ�ʱ
				{
					if (cur->m_data < pre->m_data)//�����̳�cur�ĸ��׹�ϵ
					{
						pre->m_left = cur->m_right;
					}
					else
					{
						pre->m_right = cur->m_right;
					}
				}

				delete cur;//ɾ��cur
			}
		}
		/*
		���ǲ���������������
		�������������У�
		a��������û���Һ���
		ֱ�������Ӽ̳��Լ����Һ��Ӻ͸���
		b�����������Һ���
		һ·���ң��ҵ�����һ���Һ��ӣ�Ȼ��������ӵ�
		���������������׵��������ϣ�Ȼ�������̳�Ҫɾ����
		����˼ʹ�ϵ�����������͸��ף�
		��Ҫɾ���Ľڵ��Ǹ��ڵ�ʱ�����ü̳и��׹�ϵ����Ҫ�޸�
		���ڵ�ָ��
		��ֻ��������
		ֱ�����������̳��Լ��ĸ��׹�ϵ�����Ҫɾ���Ǹ�����ô
		ֱ�ӻ������ɡ�
		������
		ֱ���������������߿գ��̳��Լ��ĸ��׹�ϵ������ͬ��
		*/

		std::vector<T> InOrder()//�������
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
					res.push_back(cur->m_data);//���ն������������������vector��������
					s.pop();

					cur = cur->m_right;
				}
			}
			return res;
		}
	};
};