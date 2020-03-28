#include<iostream>
#include<string>
using namespace std;

// 代理接口
class GiveGift {
	virtual void GiveDolls() = 0;
	virtual void GiveFlowers() = 0;
	virtual void GiveChocolate() = 0;
};

// 被追求者
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

// 追求者
class Pursuit : public GiveGift {
private:
	SchoolGirl* mm;
public:
	Pursuit(){}
	Pursuit(SchoolGirl* m) { mm = m; }
	void GiveDolls() {
		cout << mm->getName() << " 送你洋娃娃" << endl;
	}
	void GiveFlowers() {
		cout << mm->getName() << " 送你花" << endl;
	}
	void GiveChocolate() {
		cout << mm->getName() << " 送你巧克力" << endl;
	}

};

// 代理，让代理去送礼物
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
	SchoolGirl* jiaojiao = new SchoolGirl("娇娇");
	Proxy* daili = new Proxy(jiaojiao);
	daili->GiveDolls();
	daili->GiveFlowers();
	daili->GiveChocolate();
	return 0;
}
