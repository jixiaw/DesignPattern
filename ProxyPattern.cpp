#include<iostream>
#include<string>
using namespace std;

// ����ӿ�
class GiveGift {
	virtual void GiveDolls() = 0;
	virtual void GiveFlowers() = 0;
	virtual void GiveChocolate() = 0;
};

// ��׷����
class SchoolGirl {
private:
	string name;
public:
	SchoolGirl(){}
	SchoolGirl(string s) { name = s; }
	string getName() const{
		return name;
	}
	void setName(string s) {
		name = s;
	}
};

// ׷����
class Pursuit : public GiveGift {
private:
	SchoolGirl* mm;
public:
	Pursuit(){}
	Pursuit(SchoolGirl* m) { mm = m; }
	void GiveDolls() {
		cout << mm->getName() << " ����������" << endl;
	}
	void GiveFlowers() {
		cout << mm->getName() << " ���㻨" << endl;
	}
	void GiveChocolate() {
		cout << mm->getName() << " �����ɿ���" << endl;
	}

};

// �����ô���ȥ������
class Proxy : GiveGift {
private:
	Pursuit* gg;
public:
	Proxy(){}
	Proxy(SchoolGirl* mm) {
		gg = new Pursuit(mm);
	}
	void GiveDolls() {
		gg->GiveDolls();
	}
	void GiveFlowers() {
		gg->GiveFlowers();
	}
	void GiveChocolate() {
		gg->GiveChocolate();
	}

};

int main() {
	SchoolGirl* jiaojiao = new SchoolGirl("����");
	Proxy* daili = new Proxy(jiaojiao);
	daili->GiveDolls();
	daili->GiveFlowers();
	daili->GiveChocolate();
	return 0;
}
