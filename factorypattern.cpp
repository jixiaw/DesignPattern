#include<cstdio>
#include<string>
#include<iostream>
using namespace std;

class Operation {
public:
	double numA = 0, numB = 0;
	void setNumA(const double a) { numA = a; }
	void setNumB(const double b) { numB = b; }
	virtual double getResult() { return 0; }
};

class OperationAdd :public Operation {
public:
	double getResult() {
		return numA + numB;
	}
};

class OperationMinus :public Operation {
public:
	double getResult() {
		return numA - numB;
	}
};

class OperationMultiply :public Operation {
public:
	double getResult() {
		return numA * numB;
	}
};

class OperationDiv :public Operation {
public:
	double getResult() {
		if (numB != 0)
			return numA / numB;
		else return 0;
	}
};

class OperationFactory {
public:
	static Operation* createOperation(char operate) {
		Operation* opera = new Operation();
		switch (operate) {
		case '+':
			opera = new OperationAdd();
			break;

		case '-':
			opera = new OperationMinus();
			break;

		case '*':
			opera = new OperationMultiply();
			break;
		case '/':
			opera = new OperationDiv();
			break;
		}
		return opera;
	}
};

int main() {
	Operation* op = OperationFactory::createOperation('/');
	op->setNumA(1);
	op->setNumB(3);
	cout << op->getResult()<<endl;
}