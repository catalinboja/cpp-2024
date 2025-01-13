#include <iostream>
#include <string>

using namespace std;

// inheritance vs composition
// is-a vs has-a

//inheritance
//overriding
//virtual pure methods
//abstract classes
//frameworks of classes
//up-casting

class Person {
protected:
	string name = "";
	int age = 0;
public:
	Person() {

	}

	Person(int age, string name) : age(age), name(name) {

	}

	string getName() {
		return this->name;
	}

	virtual void printInfo() {
		cout << endl << "Name: " << this->name << " age: " << this->age;
	}
};

class Teacher : public Person {
protected:
	string school;
};

class Employee: public Person {
protected:
	string company;
	float salary;
};


class Student : public Person{
protected:
	string faculty = "";
	int year = 1;
public:
	Student(): Person(0,"John Doe") {

	}

	Student(int age, string name, string faculty, int year)
	:Person(age, name), year(year){
		this->faculty = faculty;
	}

	string getFaculty() {
		return this->faculty;
	}

	//overriding methods from parent classes
	void printInfo() {
		//call the Person version
		this->Person::printInfo();
		cout << endl << "Faculty: " << this->faculty << " year: " << this->year;
	}

	//NOT overriding -> Overloading
	void printInfo(int something) {

	}

	//overriding  + overloading = plymorphism
};

class MasterStudent : public Student {
protected:
	string masterProgram;

public:
	MasterStudent() : Student()
	{

	}

	MasterStudent(int age, string name,
		string faculty, int year, string master)
		:Student(age, name, faculty, year) {
		this->masterProgram = master;
	}

	//overriding methods from parent classes
	void printInfo() {
		//call the Person version
		// 
		//this->Person::printInfo();
		//cout << endl << "Faculty: " << this->faculty << " year: " << this->year;

		this->Student::printInfo();
		cout << endl << "Master: " << this->masterProgram;

	}
};

//Multi-inheritance AVOID IT
class Intern : public Employee, public Student {
	float noOfWeeks;
public:
	void doSomething() {
		this->Student::age = 23;
		this->Employee::age = 24;
		//this->age = 25;
	}
};

int main() {
	Person person(25, "John");
	Student student;
	Student alice(21, "Alice", "CSIE", 2);
	MasterStudent john(24, "John", "CSIE", 3, "IE");

	cout << endl << person.getName();
	cout << endl << alice.getName();
	cout << endl << john.getName();

	
	Person persons[5];
	Student students[5];
	MasterStudent masterStudents[5];

	//Person allOfThem[15];
	//allOfThem[0] = person; //UP-CASTING
	//allOfThem[1] = alice;  //UP-CASTING
	//allOfThem[2] = john;   //UP-CASTING

	//cout << endl << "---------------";

	//for (int i = 0; i < 3; i++) {
	//	cout << endl << allOfThem[i].getName();
	//	if (i == 1) {
	//		Student stud = (Student)allOfThem[i]; //DOWN-CAST
	//	}
	//}

	Student* bob = new Student(22, "Bob", "CSIE", 2);

	Person* allOfThem[15];
	allOfThem[0] = &person; //UP-CASTING
	allOfThem[1] = &alice;  //UP-CASTING
	allOfThem[2] = &john;   //UP-CASTING
	allOfThem[2] = bob;   //UP-CASTING
		cout << endl << "---------------";
		
	for (int i = 0; i < 3; i++) {
		//cout << endl << allOfThem[i]->getName();

		//EARLY BINDING without virtual
		//LATE BINDING with virtual

		allOfThem[i]->printInfo(); 
		//if (i == 1 || i == 2) {
		//	Student* stud = (Student*)allOfThem[i]; //DOWN-CAST
		//	cout << endl << stud->getFaculty();
		//}
	}


}