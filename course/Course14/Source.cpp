
#include <string>
#include <iostream>
using namespace std;

class PersonalData {
	string address;
public:
	PersonalData(string data): address(data){}
};


class AbstractPerson {

	//virtual pure method
	virtual void doSomething() = 0;
};

class Person : public AbstractPerson {
protected:
	string name;
	PersonalData data;

public:
	Person(string name):name(name), data(""){}

	virtual void printInfo() {
		cout << endl << "Name: " << this->name;
	}

	void doSomething() {

	}
};

class Student: public Person {
protected:
	string bachelorProgram;
public:
	Student(string name, string bachelor)
		: Person(name),bachelorProgram(bachelor){ }

	//override
	void PrintInfo() {
		cout << endl << "Name: " << this->name;
		cout << endl << "Program: " << this->bachelorProgram;
	}

	void doSomething() {

	}
};

class MasterStudent : public Student {
protected:
	string masterProgram;
public:
public:
	MasterStudent(string name, string bachelor, string master)
		: Student(name, bachelor), masterProgram(master) {
	}

};

class Teacher : public Person {
	int teacherId;
};


int main() {
	Person* persons[5];
	Person** list = nullptr;
	list = new Person*[5];

	Person temp("Temp");

	persons[0] = new Person("John");
	persons[1] = new Student("Alice", "CSIE");
	persons[2] = new MasterStudent("Bob", "CSIE","IE");
	persons[3] = &temp;
	persons[4] = new Person(temp);


	for (int i = 0; i < 5; i++) {
		persons[i]->printInfo();
	}

}

