#include<iostream>
#include<WinSock2.h>
using namespace std;

class Singleton {
private:
	static Singleton* instance;
	static CRITICAL_SECTION cs;
	Singleton() {}  // 用 private 构造方法，就堵死了外界利用 new 创建该类实例的可能
public:
	static CRITICAL_SECTION* getCS() {
		return &cs;
	}
	static Singleton* CreateInstance() {  // 获取实例的唯一全局访问方法
		if (instance == NULL) {
			EnterCriticalSection(&cs);
			if (instance == NULL) {  // 实例不存在就 new 一个
				instance = new Singleton();
			}
			LeaveCriticalSection(&cs);
		}
		
		return instance;
	}
};

Singleton* Singleton::instance = NULL;
CRITICAL_SECTION Singleton::cs = CRITICAL_SECTION();

int main() {
	InitializeCriticalSection(Singleton::getCS());
	Singleton* s1 = Singleton::CreateInstance();
	Singleton* s2 = Singleton::CreateInstance();
	DeleteCriticalSection(Singleton::getCS());
	if (s1 == s2) cout << "两个对象是相同的实例" << endl;
	return 0;
}