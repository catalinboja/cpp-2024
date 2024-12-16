#include <iostream>
#include <string>
using namespace std;

// composition - has a
// inheritance - is a

//class Student {
//	int age;
//	string adress;
//	string pnn; //CNP
//
//	string faculty;
//	string facultyAddress;
//	string secretaryName;
//	int groupNo;
//	int year;
//};

//class ErasmusStudent {
//	int age;
//	string adress;
//	string pnn; //CNP
//
//	string faculty;
//	string facultyAddress;
//	string secretaryName;
//	int groupNo;
//	int year;
// 
//  string country;
//  string universityOfOrigin
//};


//easier to manage - simpler classes
// is reusable

class PersonalData {
public:
	int age;
	string adress;
	string pnn; //CNP

	PersonalData() {

	}

	PersonalData(string addr, int age, string pnn) {
		this->age = age;
		this->adress = addr;
		this->pnn = pnn;

	}

};

class UniversityData {
public:
	string faculty;
	string facultyAddress;
	string secretaryName;
	int groupNo;
	int year;

	//DON'T This is no OOP
	//add new attributes in the class after you already did the app
	//string bachelorPaperTitle;
	//float bachelorExamGrade;

};

////DON'T This is no OOP
//// Don't create new classes by copy & paste existing ones
//class UniversityDataWithBachelor {
//public:
//	string faculty;
//	string facultyAddress;
//	string secretaryName;
//	int groupNo;
//	int year;
//
//	string bachelorPaperTitle;
//	float bachelorExamGrade;
//
//};



class ErasmusData {
public:
  string country;
  string universityOfOrigin;

  ErasmusData(string c, string u) {
	  this->country = c;
	  this->universityOfOrigin = u;
  }
};

class Grade {
public:
	int grade;
	string course;
};

//parent/super class
//base class
class Student {
protected: //private for anyone else but accesible from subclasses
	int somethingPrivate;
public:
	int id;
	PersonalData personalData; // 1:1
	UniversityData universityData;
	Grade* grades; //1:M
	int noGrades;

	//Student() {

	//}

	//Student(int id, string addr, int age, string pnn)
	// :personalData(){
	//	this->id = id;
	//	this->personalData.age = age;
	//	this->personalData.adress = addr;
	//	this->personalData.pnn = pnn;

	//}

	Student(int id, string addr, int age, string pnn)
		: personalData(addr,age, pnn) {
		this->id = id;
	}

	void processSomethingPrivate() {
		this->somethingPrivate = 1;
	}

	PersonalData getPersonalData() {
		return this->personalData;
	}
};


class BachelorExam {
	string bachelorPaperTitle;
	float bachelorExamGrade;
};
//IS-A
//subclass of Student
//child class of Student
//derived class of Student
class MasterStudent: public Student { //is-a
public:
	string masterProgram;
	BachelorExam bachelorExam; //has-a

	MasterStudent():Student(1,"ad",20,"1234") {

	}

	void changePrivateAttribute() {
		this->processSomethingPrivate();
	}

	void changeProtected() {
		this->somethingPrivate = 2;
	}

};


class ErasmusStudent {
public:
	int id;
	PersonalData personalData;
	UniversityData universityData;
	ErasmusData erasmusData;

	//because you don't have the default ctor in ErasmusData
	ErasmusStudent(): erasmusData("Germany","UTH") {

	}
};

int main() {
	Student s;
	s.id = 1;
	s.personalData.age = 22;
	s.universityData.faculty = "CSIE";

	//s.somethingPrivate = 1;

	cout << endl << s.getPersonalData().adress;

	Student* ps = new Student();
	ps->id = 2;
	ps->personalData.age = 23;

	MasterStudent master;
	master.universityData.groupNo = 1001;
	//master.somethingPrivate = 1;

	ErasmusStudent eStudent;

}

