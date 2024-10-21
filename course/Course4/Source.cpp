#include <iostream>
using namespace std;

struct Student {
	char* name;
	int age;
	int id;
	char email[100];
	char faculty[100];
};

void printStudent(Student student) {
	cout << endl << "Student info";
}

void initStudent(const char* name, int age, int id, const char* email) {
	cout << endl << "Init Student info";
}

//make the entire class private - encapsulation
class StudentEvolved {
private:			//a label - an access specifier
	char* name;
	int age;
	int id;
protected:
	char email[100];
public:

	//accessor methods
	//for reading
	int getId() {
		return this->id;
	}

	int getAge() {
		return age;
	}

	//for writing
	void setAge(int newAge) {
		//DON'T - better make the attribute public
		//this->age = newAge;
		if (newAge >= 5 && newAge <= 150) {
			this->age = newAge;
		}
		else {
			throw "Wrong age";
		}
	}

	//class methods have access on everything
	//they receive by default the address of the object that will call
	// this method. The pointer is name this
	void printInfo() {
		cout << endl << "Student age: " << this->age;
	}
};

int main() {

	int value;
	int values[100];

	//managing students data with only arrays
	char* names[100];
	int ages[100];

	//managing students data with structures
	Student students[100];

	Student student; //an article
	initStudent("John", 20, 1, "john@ase.ro");

	//no ownership and no rules
	student.age = 23;
	student.age = -23;

	value = 23;
	const int constInt = 10;

	//constInt = 23;
	const int minGradeToPass = 5;


	//you have ownership
	StudentEvolved newStudent; //an object - an instance of a class
	//newStudent.age = -23;
	//newStudent.id = 1;
	//cout << endl << newStudent.email;
	//cout << endl << newStudent.age;

	cout << endl << newStudent.getAge();

	StudentEvolved alice;
	StudentEvolved bob;

	//newStudent.printInfo(newStudent);

	alice.printInfo();
	bob.printInfo();
	//bob.printInfo(alice);

	bob.setAge(-23);

}

