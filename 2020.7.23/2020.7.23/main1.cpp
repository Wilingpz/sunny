#include <iostream>
//�����߳�
#include <mutex>
#include <thread>

using namespace std;
//����ģʽ


//1������ģʽ���ȳ�ʼ�����ã�
class Single
{
public:
	static Single* GetInstance()  //ֻ�о�̬��Ա�������Է��ʾ�̬��Ա����
	{
		return &m_instance;
	}
private:
	Single();         //Ĭ�Ϲ���
	Single(Single const&) = delete;   //ɾ����������
	Single& operator=(Single const&) = delete;  //ɾ����ֵ���������

	static Single m_instance;  //static���͵ĳ�Ա����
};

Single Single::m_instance; // �ڳ������֮ǰ����ɵ�������ʵ����



//2������ģʽ�������ٳ�ʼ����
//��Ϊʹ�̲߳���ȫ�ģ���û�д�����������£�����̵߳���GeInstance()�����������봴������
//����Ҫ����

class Singleton
{
public:
	static Singleton* GetInstance() 
	{
		// ע������һ��Ҫʹ��Double-Check�ķ�ʽ���������ܱ�֤Ч�ʺ��̰߳�ȫ
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
	// ʵ��һ����Ƕ����������
	class CGarbo 
	{
	public:
		~CGarbo()
		{
			if (Singleton::m_pInstance)//ָ��Ϊ�գ����ͷ�
				delete Singleton::m_pInstance;
		}
	};
	// ����һ����̬��Ա�������������ʱ��ϵͳ���Զ������������������Ӷ��ͷŵ�������
	static CGarbo Garbo;
private:
	// ���캯��˽��
	Singleton(){};
	// ������
	Singleton(Singleton const&);
	Singleton& operator=(Singleton const&);
	static Singleton* m_pInstance; // ��������ָ��
	static mutex m_mtx; //������
};
Singleton* Singleton::m_pInstance = nullptr;
Singleton::CGarbo Garbo;
mutex Singleton::m_mtx;

 void func(int n)
{
	cout << Singleton::GetInstance() << endl;
}
// ���̻߳�������ʾ����GetInstance()�����Ͳ�����������
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