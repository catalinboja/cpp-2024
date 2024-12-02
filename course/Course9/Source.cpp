

//today
//try-catch
//files - text and binary

//relation between classes
// has a - composition
// is a - inheritance/derivation

//inheritance
// overriding
//virtual methods
//abstract methods and classes
//frameworks and up casting


//2025
//templates and STL (collections)

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//creatin a new exception type
class InvalidNameException {
	string msg;
public:
	InvalidNameException(string msg) : msg(msg) {

	}
	string what() {
		return this->msg;
	}
};

class InvalidValueException: public exception {

};

class Student {
public:
	const static int MIN_AGE;

private:
	string name = "";
	int age = 0;
public:
	void setAge(int value) {
		if (value < Student::MIN_AGE) {
			throw "Wrong age";
		} 
		age = value;
	}

	void setName(string value) {
		if (value.size() < 2) {
			//throw exception("Wrong value for name");
			//throw new exception("Wrong value for name");
			throw InvalidNameException("Wrong value for name");
		}
		this->name = value;
	}

	void doSomething(int value) {
		if (value < 10) {
			//throw exception("Less than 10");
			throw InvalidValueException();
		}
		//...
	}

	void doSomething2(int value) {
		if (value < 10) {
			//throw exception("Less than 10");
			throw 5;
		}
		//...
	}
};

const int Student::MIN_AGE = 8;

int main() {
	Student s;

	while (true) {
		cout << endl << "Age: ";
		int value;
		cin >> value;
		if (value < Student::MIN_AGE) {
			cout << endl << "Age is wrong";
		}
		else {
			s.setAge(value);
			break;
		}
	}

	cout << endl << "Saving data to DB";

	try {
		cout << endl << "Reading age";
		s.setAge(23);
		cout << endl << "Reading name";
		s.setName("John");

		s.doSomething(20);

		s.doSomething2(2);
		cout << endl << "Finish reading";
	}

	catch (string msg) {
		cout << endl << "Houston we have a problem: " + msg;
	}
	catch (const char* msg) {
		cout << endl << "Houston we have another problem: " << msg;
	}
	catch (exception ex) {
		cout << endl << "Houston we an exception: " << ex.what();
	}
	catch (exception* ex) {
		cout << endl << "Houston we an exception: " << ex->what();
		delete ex;
	}
	catch (InvalidNameException ex) {
		cout << endl << "Name issue" + ex.what();
	}
	catch (InvalidValueException ex) {
		cout << endl << "Value issue";
	}
	catch (...) {
		cout << endl << "An issue";
	}
	//finally - optional


	cout << endl << "The end";

	ofstream text("report.txt");
	text << "This is a report" << endl;
	text << "Hello" << endl;
	text.close();


}