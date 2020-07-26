#include <iostream>
//锁和线程
#include <mutex>
#include <thread>

using namespace std;
//单例模式


//1、饿汉模式（先初始化再用）
class Single
{
public:
	static Single* GetInstance()  //只有静态成员函数可以访问静态成员变量
	{
		return &m_instance;
	}
private:
	Single();         //默认构造
	Single(Single const&) = delete;   //删除拷贝构造
	Single& operator=(Single const&) = delete;  //删除赋值运算符重载

	static Single m_instance;  //static类型的成员变量
};

Single Single::m_instance; // 在程序入口之前就完成单例对象实例化



//2、懒汉模式（先用再初始化）
//因为使线程不安全的（在没有创建对象情况下，多个线程调用GeInstance()函数，并进入创建对象）
//所以要加锁

class Singleton
{
public:
	static Singleton* GetInstance() 
	{
		// 注意这里一定要使用Double-Check的方式加锁，才能保证效率和线程安全
		if (nullptr == m_pInstance) 
		{
			m_mtx.lock();
			if (nullptr == m_pInstance) 
			{
				m_pInstance = new Singleton();
			}
			m_mtx.unlock();
		}
		return m_pInstance;
	}
	// 实现一个内嵌垃圾回收类
	class CGarbo 
	{
	public:
		~CGarbo()
		{
			if (Singleton::m_pInstance)//指针为空，就释放
				delete Singleton::m_pInstance;
		}
	};
	// 定义一个静态成员变量，程序结束时，系统会自动调用它的析构函数从而释放单例对象
	static CGarbo Garbo;
private:
	// 构造函数私有
	Singleton(){};
	// 防拷贝
	Singleton(Singleton const&);
	Singleton& operator=(Singleton const&);
	static Singleton* m_pInstance; // 单例对象指针
	static mutex m_mtx; //互斥锁
};
Singleton* Singleton::m_pInstance = nullptr;
Singleton::CGarbo Garbo;
mutex Singleton::m_mtx;

 void func(int n)
{
	cout << Singleton::GetInstance() << endl;
}
// 多线程环境下演示上面GetInstance()加锁和不加锁的区别。
int main2()
{
	thread t1(func, 10);
	thread t2(func, 10);
	t1.join();
	t2.join();
	cout << Singleton::GetInstance() << endl;
	cout << Singleton::GetInstance() << endl;
	system("pause");
	return 0;
}