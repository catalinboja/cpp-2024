
#include <iostream>
#include <string>

using namespace std;

// do's and don't
// defining a class
// - define attributes (different types, const and static)
// - define special methods: constructor (default and with params),
//	copy constructor, destructor, operator =
// - define a public interface for reading and writing private/protected attributes
//  getters and setters
// - other methods (static and class member methods)

enum FacultyDomain {ECONOMICS, COMPUTER_SCIENCE = 20, MATHEMATICS, OTHER};

class Faculty {
	char code = 0;
	int id = 0;
	int noStudents = 0;
	bool isPrivate = true;
	float avgTax = 0;

	char* name = nullptr;
	string* bachelorPrograms = nullptr;
	int noPrograms = 0;
	int* noStudentsPerYear = nullptr;
	int noYears = 0;

	FacultyDomain domain = FacultyDomain::OTHER;

	const string address;
	const int countryId;

	static int MAX_STUDENTS;
	static float MAX_TAX;
	static string DEFAULT_COUNTRY;
	static int NO_FACULTIES;

public:
	Faculty(const char* name, const string* programs, const int noPrograms,
		const int* noStudentsPerYear, const int noYears, const string addr, int countryId,
		float averageTax, FacultyDomain domain)
		:address(addr), countryId(countryId), avgTax(averageTax) {

		this->domain = domain;
		
		//copy the name
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
		//copy the programs
		this->bachelorPrograms = new string[noPrograms];
		for (int i = 0; i < noPrograms; i++) {
			this->bachelorPrograms[i] = programs[i];
		}
		this->noPrograms = noPrograms;

		//programs = new string[noPrograms];
		//name = new char[5];

		//copy the noStudentsPerYear

		Faculty::NO_FACULTIES += 1;
	}

	//other constructor with other combinations of values

	Faculty(): address("Romania"), countryId(0) {
		Faculty::NO_FACULTIES += 1;
	}

	Faculty(const Faculty& faculty)
		:countryId(faculty.countryId), address(faculty.address) {
		//faculty.avgTax = this->avgTax;
		this->avgTax = faculty.avgTax;
		//copy the other fields including the dynamic ones
	}

	~Faculty() {
		delete[] this->name;
		delete[] this->bachelorPrograms;
		delete[] this->noStudentsPerYear;
		cout << endl << "Faculty destructor";
	}

	//public interface
	void setAvgTax(float value) {
		if (value <= 0 || value > Faculty::MAX_TAX) {
			throw "Value invalid";
		}
		this->avgTax = value;
	}

	float getAvgTax() {
		return this->avgTax;
	}

	//DON't
	char* getName_wrongVersion() {
		return this->name;
	}
	//DO - return copy
	char* getName() {
		if (this->name == nullptr)
			return nullptr;

		char* copy = new char[strlen(this->name) + 1];
		strcpy_s(copy, strlen(this->name) + 1, this->name);
		return copy;
	}

	void setName(const char* newName) {
		//not ok
		// don't do shallow copy
		//this->name = newName;

		//don't create memory leaks
		if (this->name != nullptr)
			delete[] this->name;

		//copy the name
		this->name = new char[strlen(newName) + 1];
		strcpy_s(this->name, strlen(newName) + 1, newName);
	}

	void setPrograms(const string* newPrograms, const int noNewPrograms) {
		if (this->bachelorPrograms != nullptr)
			delete[] this->bachelorPrograms;

		this->bachelorPrograms = new string[noNewPrograms];
		for (int i = 0; i < noNewPrograms; i++) {
			this->bachelorPrograms[i] = newPrograms[i];
		}

		//noNewPrograms = 0;

		this->noPrograms = noNewPrograms;

	}


	int doSomething() {
		return this->avgTax * 2;
	}


	int getMinStudentsPerYear() {
		if (this->noYears == 0)
			return 0;
		int min = this->noStudentsPerYear[0];
		for (int i = 0; i < this->noYears; i++) {
			if (min > this->noStudentsPerYear[i])
				min = this->noStudentsPerYear[i];
		}
		return 0;
	}

	int countYearWithMinValue() {

		int minStudents = this->getMinStudentsPerYear();
		int count = 0;
		for (int i = 0; i < this->noYears; i++) {
			if (minStudents == this->noStudentsPerYear[i])
				count += 1;
		}
		return count;
	}


	static void printMessage() {
		cout << endl << "Hello";
	}

};

int Faculty::MAX_STUDENTS = 1000;
float Faculty::MAX_TAX = 900.0;
string Faculty::DEFAULT_COUNTRY = "Romania";
int Faculty::NO_FACULTIES = 0;


int main() {
	char name[] = "CSIE";
	string programs[2] = { "Informatics", "Cybernetics" };
	int noPrograms = 2;
	int noStudentsPeryear[3] = { 800, 700, 600 };
	int noYears = 3;

	Faculty csie(name, programs, 2,
		noStudentsPeryear, noYears, "Romania", 1, 5000, FacultyDomain::ECONOMICS);

	Faculty man;

	Faculty csieCopy = csie; //copy ctor

	//test destructor
	//delete man;
	//~man;

	{
		Faculty cig;
	}

	Faculty* pFaculty = new Faculty();
	delete pFaculty;
	pFaculty = nullptr;

	string newPrograms[3] = { "Informatics", "Cybernetics", "Statistics"};
	csie.setPrograms(newPrograms, 3);

	//test getter
	//char* yourName = csie.getName_wrongVersion();
	char* yourName = csie.getName();
	yourName[0] = 'X';
	delete[] yourName;
	yourName = nullptr;
	//csie.name = nullptr;


	int vb1 = 10;
	int vb2 = vb1;
	vb1 = 100;

	csie.doSomething();
	Faculty::printMessage();


	cout << endl << "The end";
}

