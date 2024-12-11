#include <iostream>
#include <string>
using namespace std;


class StudentAgeException {
	string msg;

public:
	StudentAgeException(string message) {
		this->msg = message;
	}

	string what() {
		return this->msg;
	}
};

class StudentNameException {

};

class NegativeValueException {

};

class BigValueException {

};

class BigValueRealException : public exception {

};


class Student {
	string name = "";
public:
	Student() {
		cout << endl << "Calling Default Ctor";

	}
	Student(string name){
		cout << endl << "Calling Params Ctor";
	}

	Student(string name, int age) {
		cout << endl << "Calling Params Ctor";
	}

	Student(int age, string name) {
		cout << endl << "Calling Params Ctor";
	}

	Student(const Student& s) {
		this->name = s.name;
		cout << endl << "Calling Copy Ctor";
		//s.name = "";
	}

	void resetStudentName(Student& s) {
		s.name = "";
	}
};

void doSomething(Student s) {

}

Student doSomethingElse() {
	Student temp("Alice");
	return temp;
}

int aduna(int a, int b) {
	return a + b;
}

int aduna(int a, int b, int c) {
	return a + b + c;
}

void throwException() {
	int vb;
	cout << endl << "Vb value: ";
	cin >> vb;

	if (vb < 0) {
		//throw "Negative value";
		throw new NegativeValueException();
	}
	if (vb > 1000) {
		//throw "Value too big";
		throw BigValueException();
	}

	if (vb == 500) {
		throw new exception("Value is 500");
	}
}

int main() {


	Student s;
	Student s3("John");
	Student s4("Bob", 23);
	Student s5(34, "Bob");






	Student s2 = s;

	//int z;
	//z = 10;

	s3 = s;

	doSomething(s2);

	s = doSomethingElse();

	StudentAgeException ex("test");

	int ex2;

	try {
		throwException();
	}
	catch (const char* msg) {
		cout << endl << msg;
	}
	catch (NegativeValueException* ex) {
		cout << "Negative value !!!";
		delete ex;
	}
	catch (BigValueException ex) {
		cout << "****** Big value !!!";
	}
	catch (exception* ex) {
		cout << "Error: " << ex->what();
	}
}