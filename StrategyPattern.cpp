#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

class CashSuper {
public:
	virtual double acceptCash(const double money) = 0;
};

class CashNormal : public CashSuper {
public:
	double acceptCash(const double money) override {
		return money;
	}
};

class CashRebate :public CashSuper {
private:
	double moneyRebate = 1.0;
public:
	CashRebate(const double rebate) { this->moneyRebate = rebate; }
	double acceptCash(const double money) override {
		return money * this->moneyRebate;
	}
};

class CashReturn :public CashSuper {
private:
	double moneyCondition = 0.0;
	double moneyReturn = 0.0;
public:
	CashReturn(const double moneyCondition, const double moneyReturn) {
		this->moneyCondition = moneyCondition;
		this->moneyReturn = moneyReturn;
	}
	double acceptCash(const double money) override {
		if (money >= moneyCondition) {
			return money - floor(money / moneyCondition) * moneyReturn;
		}
		return money;
	}
};

class CashContext {
private:
	CashSuper *cs = NULL;
public:
	CashContext(CashSuper *casdSuper) {
		this->cs = casdSuper;
	}
	CashContext(string s) {
		if (s == "正常收费") this->cs = new CashNormal();
		else if (s == "打8折") this->cs = new CashRebate(0.8);
		else if (s == "满300返100") this->cs = new CashReturn(300, 100);
	}
	void changeStrategy(string s) {
		if (s == "正常收费") this->cs = new CashNormal();
		else if (s == "打8折") this->cs = new CashRebate(0.8);
		else if (s == "满300返100") this->cs = new CashReturn(300, 100);
	}
	double getResult(const double money) {
		return cs->acceptCash(money);
	}
};

int main() {
	double money = 1222.4;
	CashContext *cc = new CashContext("打8折");
	cout << cc->getResult(money) << endl;
	cc->changeStrategy("满300返100");
	cout << cc->getResult(money) << endl;
	return 0;
}