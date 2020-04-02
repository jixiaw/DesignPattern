#include <iostream>
#include <string>

using namespace std;

class TestPaper {
protected:
	virtual string answer1() = 0;  // ��������д 
	virtual string answer2() = 0;
	virtual string answer3() = 0;
public:
	void testQuestion1() {
		cout << "��Ŀ 1: A.aaa B.bbb C.ccc D.ddd" << endl;
		cout << "��: " << answer1() << endl;
	}
	void testQuestion2() {
		cout << "��Ŀ 2: A.aaa B.bbb C.ccc D.ddd" << endl;
		cout << "��: " << answer2() << endl;
	}
	void testQuestion3() {
		cout << "��Ŀ 3: A.aaa B.bbb C.ccc D.ddd" << endl;
		cout << "��: " << answer3() << endl;
	}
};

class TestPaperA :public TestPaper {
protected:
	string answer1() override {
		return "A";
	}
	string answer2() override {
		return "B";
	}
	string answer3() override {
		return "C";
	}
};

class TestPaperB :public TestPaper {
protected:
	string answer1() override {
		return "B";
	}
	string answer2() override {
		return "D";
	}
	string answer3() override {
		return "C";
	}
};

int main() {
	TestPaper *student = new TestPaperA();
	student->testQuestion1();
	student->testQuestion2();
	student->testQuestion3();
	student = new TestPaperB();
	student->testQuestion1();
	student->testQuestion2();
	student->testQuestion3();
	return 0;
}