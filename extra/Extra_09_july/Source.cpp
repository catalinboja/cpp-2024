#include <string>
#include <iostream>

using namespace std;

//overloading operators

class Faculty {
protected:
	int noStudents;
	string name;
	int studentsPerYear[3] = { 100,200,150 };
	const int id;
public:
	Faculty(string name, int noStudents, int id)
		:name(name), noStudents(noStudents), id(id) {

	}

	Faculty():id(0) {

	}

	void print() {
		cout << this->name << endl;
	}

	int doSomething() {
		this->noStudents = 0;
		return 0;
	}

	Faculty operator-(int param2) {
		Faculty copy = *this;
		copy.noStudents -= param2;
		return copy;
	}

	//Faculty operator-(Faculty param1, int param2);


	//THIS IS A GLOBAL METHOD
	//DON'T RECOMMEND
	friend Faculty operator+ (int param1, Faculty param2)
	{
		//IS WRONG
		//param2.noStudents += param1;

		Faculty copy = param2;
		copy.noStudents += param1;

		return copy;
	}

	//string operator*(int param1, Faculty param2) {

	//}

	friend string operator*(int param1, Faculty param2);

	Faculty operator+(const char* param2) {
		//TODO: concatenate param2 to name
		Faculty copy = *this;
		copy.name += string(param2);
		return copy;
	}

	explicit operator int() {
		return this->noStudents;
	}


	int operator()(int param1, int param2) {
		return this->noStudents + param1 + param2;
	}

	// = always inside the class
	Faculty operator=(Faculty f) {

		//test to avoid self assignment
		if (this == &f) {
			return *this;
		}

		this->noStudents = f.noStudents;
		this->name = f.name;

		return *this;
	}

	int& operator[](int index) {
		if (index >= 0 && index < 3) {
			return this->studentsPerYear[index];
		}
		else
			throw "wrong index";
	}

};

class University {
public:
	//Faculty faculties[10];
	Faculty** faculties = nullptr;
	int noFaculties = 0;

	University() {

	}

	void addFaculty(Faculty f) {
		Faculty** newList = new Faculty*[this->noFaculties + 1];
		for (int i = 0; i < this->noFaculties; i++) {
			newList[i] = this->faculties[i];
		}
		Faculty* newFaculty = new Faculty(f);
		newList[this->noFaculties] = newFaculty;

		delete[] this->faculties;
		this->faculties = newList;

		this->noFaculties += 1;
	}

	void print() {
		cout << "University" << endl;
		for (int i = 0; i < this->noFaculties; i++) {
			this->faculties[i]->print();
		}
	}
};

class UniversitySecond {
public:
	Faculty* faculties = nullptr;
	int noFaculties = 0;

	void addFaculty(Faculty f) {

		Faculty* newList = new Faculty[this->noFaculties + 1];
		for (int i = 0; i < this->noFaculties; i++) {
			newList[i] = this->faculties[i]; //operator =
		}
		newList[this->noFaculties] = f;
		this->noFaculties += 1;

		delete[] this->faculties;
		this->faculties = newList;
	}

	void print() {
		cout << "UniversitySecond" << endl;
		for (int i = 0; i < this->noFaculties; i++) {
			this->faculties[i].print();
		}
	}

};

void operator<< (ostream& param1, Faculty param2) {

}

//Faculty operator+ (int param1, Faculty param2) {
//	param2.noStudents = 0;
//}

//Faculty operator-(Faculty param1, int param2) {
//	//param1.noStudents = 0;
//}

string operator*(int param1, Faculty param2) {
	return "todo";
}


int main() {
	Faculty csie("CSIE", 1000,1);
	Faculty man("MAN", 1000, 4);
	csie.doSomething();

	University ase;
	UniversitySecond upb;

	ase.addFaculty(csie);
	ase.addFaculty(man);

	upb.addFaculty(csie);
	upb.addFaculty(man);

	ase.print();
	upb.print();


	//stream operators
	cout << csie;
	//cin >> csie;
	//cout << endl << csie;

	//operator =
	Faculty f1("", 0, 0);
	f1 = csie;

	Faculty f2 = csie; //copy ctor
	Faculty f3(csie); //copy ctor - I don't use this form

	Faculty temp("", 0, 0);

	//binary math operators
	// THEY DON"T CHANGE THE OPERANDS/PARAMS
	//Faculty temp = csie + 10;

	temp = 20 + csie;
	temp = csie - 10;
	//int result = 10 - csie;
	//temp = csie * 2;
	//temp = csie / 2;
	string msg = 2 * csie;

	temp = csie + " faculty";
	//temp = csie + f1;

	//csie += 2; //csie = csie + 2
	//csie -= 10;
	//csie *= 5;
	//csie /= 2;

	//logic operators
	//if (f1 == csie) {
	//	cout << endl << "They have the same name";
	//}

	//if (f1 > csie) {
	//	cout << endl << "F1 has more students";
	//}

	// <, <=, >=, !=

	//if (!csie) {
	//	cout << endl << "There are no students";
	//}

	//unary math operators
	//f1 = csie++; //post
	//f1 = ++csie; //pre

	//also for --

	//f1 = !csie; //makes number of students 0

	int result = csie(10, 2000); //function operator

	int noStudentsIn2ndYear = csie[1]; //index operator
	csie[2] = 500;

	int noStudents = (int)csie; //explicit cast operator


}