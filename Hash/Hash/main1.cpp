#include<iostream>
using namespace std;

//开散列（链地址法） 哈希桶的构造
template<class V>
struct HashBucketNode//哈希桶结点类型
{
	HashBucketNode(const V& data)
	: _pNext(nullptr), _data(data)
	{}

	HashBucketNode<V>* _pNext;//指向下一个的指针
	V _data;//值
};


// 此次实现的哈希桶中key是唯一的
template<class V, class HF = DefHashF<T> >
class HashBucket    //哈希桶
{
	typedef HashBucketNode<V> Node;//结点
	typedef Node* PNode;//节点类型的指针

	size_t HashFunc(const V& data);//哈希函数

	vector<PNode*> _ht; 
	size_t _size; // 哈希表中有效元素的个数

public:
	HashBucket(size_t capacity = 3) 
		: _size(0)
	{
		_ht.resize(GetNextPrime(capacity), nullptr);//初始化vector _ht
	}
   // 哈希桶中的元素不能重复
		PNode* Insert(const V& data)
	{
			// 确认是否需要扩容
			// _CheckCapacity();
			// 1. 计算元素所在的桶号
			size_t bucketNo = HashFunc(data);
			// 2. 检测该元素是否在桶中
			PNode pCur = _ht[bucketNo];
			while (pCur)
			{
				if (pCur->_data == data)
					return pCur;
				pCur = pCur->_pNext;
			}
			// 3. 插入新元素
			pCur = new Node(data);
			pCur->_pNext = _ht[bucketNo];
			_ht[bucketNo] = pCur;
			_size++;
			return pCur;
		}
	// 删除哈希桶中为data的元素(data不会重复)，返回删除元素的下一个节点
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

//哈希桶的增容过程
void _CheckCapacity()
{
	size_t bucketCount = BucketCount();//桶中元素
	if (_size == bucketCount)//元素个数等于桶的个数时进行增容  
	{
		HashBucket<V, HF> newHt(NewbucketCount);
		for (size_t bucketIdx = 0; bucketIdx < bucketCount; ++bucketIdx)
		{
			PNode pCur = _ht[bucketIdx];
			while (pCur)
			{
				// 将该节点从原哈希表中拆出来
				_ht[bucketIdx] = pCur->_pNext;
				// 将该节点插入到新哈希表中
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