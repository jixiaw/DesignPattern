#include<iostream>
#include<WinSock2.h>
using namespace std;

class Singleton {
private:
	static Singleton* instance;
	static CRITICAL_SECTION cs;
	Singleton() {}  // �� private ���췽�����Ͷ������������ new ��������ʵ���Ŀ���
public:
	static CRITICAL_SECTION* getCS() {
		return &cs;
	}
	static Singleton* CreateInstance() {  // ��ȡʵ����Ψһȫ�ַ��ʷ���
		if (instance == NULL) {
			EnterCriticalSection(&cs);
			if (instance == NULL) {  // ʵ�������ھ� new һ��
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
	if (s1 == s2) cout << "������������ͬ��ʵ��" << endl;
	return 0;
}