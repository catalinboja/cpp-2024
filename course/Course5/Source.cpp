
//attributes types
//managing pointers in accessor methods
//shadowing 
//constructors
//constant and static attributes
//static methods

#include <iostream>
#include <string>
#include <string.h>

using namespace std;

enum StudentType {UNDERGRAD = 10, GRAD, MASTER = 30};

class Student {



private:
	char faculty[100];
	char* name;
	string address;

	bool hasScholarship;
	bool isErasmusStudent;

	int age;
	float credits;

	StudentType type;

	int* grades;
	int noGrades;
	float eachYearAverage[10];
	int noOfYears;

	string courses[100];
	int noCourses;
	string* friends;
	int noOfFriends;

	char* facultatives[50];
	int noOfFacultativeCourses;
	char** extraActivities;
	int noOfActivities;

public:

	//class ctor
	Student(int age, string address) {
		//this->age = age;
		this->setAge(age);
	}

	//for free
	Student() {

	}

	//public interface - collection of public methods
	//accessor methods
	int getAge() {
		return this->age;
	}

	void setAge(int age) {
		//shadowing 
		//age = age
		if (age < 5) {
			throw "Wrong age";
		}
		this->age = age;
	}

	int* getGrades() {
		//DON'T retutn the address
		//return this->grades;

		int* copy = new int[this->noGrades];
		for (int i = 0; i < this->noGrades; i++) {
			copy[i] = this->grades[i];
		}

		return copy;
	}

	void setGrades(int* newGrades, int noNewGrades) {
		if (newGrades == nullptr) {
			throw "No grades";
		}
		//shallow copy - don't copy pointers
		//this->grades = newGrades;

		//deep copy
		this->grades = new int[noNewGrades];
		for (int i = 0; i < noNewGrades; i++) {
			this->grades[i] = newGrades[i];
		}

		this->noGrades = noNewGrades;
	}

	void printInfo() {
		cout << endl << "Age: " << this->age;
		cout << endl << "Grades: ";
		if (this->grades == nullptr) {
			cout << endl << "No grades";
		}
		else {
			for (int i = 0; i < this->noGrades; i++) {
				cout << " " << this->grades[i];
			}
		}
	}

	string* getFriends() {
		string* copy = new string[this->noOfFriends];
		for (int i = 0; i < this->noOfFriends; i++) {
			copy[i] = this->friends[i];
		}
		return copy;
	}

	int getNoOfFriends() {
		return this->noOfFriends;
	}

	char** getExtraActivities() {
		char** copy = new char* [this->noOfActivities];
		for (int i = 0; i < this->noOfActivities;i++) {
			//shallow copy
			//copy[i] = this->extraActivities[i];
			copy[i] = 
				new char[strlen(this->extraActivities[i]) + 1];
			strcpy_s(copy[i],
				strlen(this->extraActivities[i]) + 1,
				this->extraActivities[i]);
		}
	}
};

int main() {
	std::string name = "John Doe";
	name = "John";
	name = name + " Doe";

	float vb = 1.2;
	std::cout << std::endl << "Name is " << name;

	Student student;
	std::cout << 
		std::endl << "Age is " << student.getAge();
	student.setAge(23);
	std::cout <<
		std::endl << "Age is " << student.getAge();

	//student.printInfo();

	int grades[] = { 10,9,10 };
	student.setGrades(grades, 3);

	student.printInfo();

	grades[0] = 4;
	student.printInfo();

	int* johnGrades = student.getGrades();
	johnGrades[0] = 4;
	student.printInfo();

	Student john(-23, "Bucharest");
}