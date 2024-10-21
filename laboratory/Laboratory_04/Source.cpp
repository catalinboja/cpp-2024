#include <iostream>
#include <string>
#include <string.h>
using namespace std;

enum StudentType {
	UNDERGRADUATE,GRADUATE, MASTER};
class Student {
private:
	char name[100];
	char* faculty;
	string email;
	//char* birthDate;
	//char birthDate[11];

	StudentType type;
	
	int id;
	int age;

	int* grades;
	int noGrades;

	float eachYearAverageGrade[5];
	int noYears;

	string* courses;
	int noCourses;
	char** facultativeCourses;
	int noFacultativeCourses;

	bool hasScholarship;
	bool isErasmusStudent;
public:
	//accessor methods
	char* getName() {
		//DON'T RETURN POINTERS
		//return this->name;

		//create a copy of the name and we return it
		//char* copy = new char[sizeof(name)];
		//char* copy = new char[100];
		char* copy = new char[strlen(this->name)+1];
		strcpy_s(copy, strlen(this->name) + 1, this->name);
		return copy;
	}

	void setName(const char* newName) {
		if (newName == nullptr || strlen(newName) < 3) {
			throw "Wrong new name";
		}
		strcpy_s(this->name, 99, newName);
	}

	int* getGrades() {
		//DON'T 
		//return this->grades;

		int* copy = new int[this->noGrades];
		for (int i = 0; i < this->noGrades; i++) {
			copy[i] = this->grades[i];
		}
		return copy;
	}

	int getAge() {
		return this->age;
	}
};

int main() {

	string name;
	name = "John";
	name = name + " Doe";
	name = "";

	Student alice;
	//cout << endl << alice.name;
	cout << endl << "Age: " << alice.getAge();
	cout << endl << "Name: " << alice.getName();
	Student bob;

	char* aPointer = alice.getName();
	strcpy_s(aPointer, 99, "Vader");

	cout << endl << "Name: " << alice.getName();

	char* university = new char[100];
	char faculty[100];

	cout << endl << "University size: " << sizeof(university);
	cout << endl << "Faculty size: " << sizeof(faculty);

	alice.getAge();

	Student* pAlice = &alice;
	pAlice->getAge();

	return 0;
}