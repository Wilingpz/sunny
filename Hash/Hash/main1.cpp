#include<iostream>
using namespace std;

//��ɢ�У�����ַ���� ��ϣͰ�Ĺ���
template<class V>
struct HashBucketNode//��ϣͰ�������
{
	HashBucketNode(const V& data)
	: _pNext(nullptr), _data(data)
	{}

	HashBucketNode<V>* _pNext;//ָ����һ����ָ��
	V _data;//ֵ
};


// �˴�ʵ�ֵĹ�ϣͰ��key��Ψһ��
template<class V, class HF = DefHashF<T> >
class HashBucket    //��ϣͰ
{
	typedef HashBucketNode<V> Node;//���
	typedef Node* PNode;//�ڵ����͵�ָ��

	size_t HashFunc(const V& data);//��ϣ����

	vector<PNode*> _ht; 
	size_t _size; // ��ϣ������ЧԪ�صĸ���

public:
	HashBucket(size_t capacity = 3) 
		: _size(0)
	{
		_ht.resize(GetNextPrime(capacity), nullptr);//��ʼ��vector _ht
	}
   // ��ϣͰ�е�Ԫ�ز����ظ�
		PNode* Insert(const V& data)
	{
			// ȷ���Ƿ���Ҫ����
			// _CheckCapacity();
			// 1. ����Ԫ�����ڵ�Ͱ��
			size_t bucketNo = HashFunc(data);
			// 2. ����Ԫ���Ƿ���Ͱ��
			PNode pCur = _ht[bucketNo];
			while (pCur)
			{
				if (pCur->_data == data)
					return pCur;
				pCur = pCur->_pNext;
			}
			// 3. ������Ԫ��
			pCur = new Node(data);
			pCur->_pNext = _ht[bucketNo];
			_ht[bucketNo] = pCur;
			_size++;
			return pCur;
		}
	// ɾ����ϣͰ��Ϊdata��Ԫ��(data�����ظ�)������ɾ��Ԫ�ص���һ���ڵ�
	PNode* Erase(const V& data)
	{
		size_t bucketNo = HashFunc(data);
		PNode pCur = _ht[bucketNo];
		PNode pPrev = nullptr, pRet = nullptr;
		while (pCur)
		{
			if (pCur->_data == data)
			{
				if (pCur == _ht[bucketNo])
					_ht[bucketNo] = pCur->_pNext;
				else
					pPrev->_pNext = pCur->_pNext;
				pRet = pCur->_pNext;
				delete pCur;
				_size--;
				return pRet;
			}
		}
		return nullptr;
	}
	PNode* Find(const V& data);
	size_t Size()const;
	bool Empty()const;
	void Clear();
	bool BucketCount()const;
	void Swap(HashBucket<V, HF>& ht;
	~HashBucket();
};

//��ϣͰ�����ݹ���
void _CheckCapacity()
{
	size_t bucketCount = BucketCount();//Ͱ��Ԫ��
	if (_size == bucketCount)//Ԫ�ظ�������Ͱ�ĸ���ʱ��������  
	{
		HashBucket<V, HF> newHt(NewbucketCount);
		for (size_t bucketIdx = 0; bucketIdx < bucketCount; ++bucketIdx)
		{
			PNode pCur = _ht[bucketIdx];
			while (pCur)
			{
				// ���ýڵ��ԭ��ϣ���в����
				_ht[bucketIdx] = pCur->_pNext;
				// ���ýڵ���뵽�¹�ϣ����
				size_t bucketNo = newHt.HashFunc(pCur->_data);
				pCur->_pNext = newHt._ht[bucketNo];
				newHt._ht[bucketNo] = pCur;
				pCur = _ht[bucketIdx];
			}
		}
		newHt._size = _size;
		this->Swap(newHt);
	}
}