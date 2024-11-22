
// overloaded operators
// constant attributes
// static methods

#include <iostream>
#include <string>
using namespace std;

class Person {
public:
	string name;
	int age;
};

class Student {

	char* nameAsString = nullptr;

	int grades[100];
	string name = "";
	int age = 0;
	float gradesAverage = 0;

	static int MIN_NAME_SIZE;
	static int COUNTER;

public:
	const int id;
	const int uniqueId;

	const static int MAX_NAME_SIZE = 255;

	Student(string name) : id(1), uniqueId(++Student::COUNTER) {
		//this->id = 1;
		//Student::COUNTER += 1;
		//this->uniqueId = Student::COUNTER;

		if (name.size() < Student::MIN_NAME_SIZE) {
			throw "Wrong name";
		}
	}

	Student(string name, int id) : id(id), uniqueId(++Student::COUNTER) {
		this->name = name;
		//this->id = id;
	}

	// : is named the ctor initialization list
	Student(string name, int id, int inputAge)
		: id(id), name(name), age(inputAge), uniqueId(++Student::COUNTER) {
		//this->name = name;
		//this->id = id;
	}

	//copy ctor
	Student(const Student& s): id(s.id), uniqueId(s.uniqueId){
		this->age = s.age;
		this->name = s.name;
		for (int i = 0; i < 100; i++) {
			this->grades[i] = s.grades[i];
		}
		if (s.nameAsString == nullptr) {
			this->nameAsString = nullptr;
		}
		else {
			this->nameAsString = new char[strlen(s.nameAsString) + 1];
			strcpy_s(this->nameAsString, strlen(s.nameAsString) + 1, s.nameAsString);
		}

	}

	//don't provide a setter for id -> no one can change it

	int getAge() {
		return this->age;
	}

	void setAge(int value) {
		this->age = value;
	}


	//static methods are called directly
	//there is NO this in static methods
	static int getNameMinSize() {
		return Student::MIN_NAME_SIZE;
	}

	static void checkUniversityFees() {
		//do something related with students but 
		// not to a particular student
	}

	void takeExam(string course) {
		// this is a method for each student
	}

	//overload operators
	//operator =
	void operator=(const Student& s) {
		this->age = s.age;
		//this->id = s.id;
		this->name = s.name;

		if (s.nameAsString == nullptr) {
			this->nameAsString = nullptr;
		}
		else {
			this->nameAsString = new char[strlen(s.nameAsString) + 1];
			strcpy_s(this->nameAsString, strlen(s.nameAsString) + 1, s.nameAsString);
		}
	}

	void operator+=(int v) {
		this->age += v;
	}

	Student operator-(int v) {
		////the MISTAKE
		//this->age -= v;
		//return *this;

		Student result = *this;
		result.age -= v;
		return result;
	}

	bool operator>=(Student s) {
		return this->age >= s.age;
	}

	bool operator==(Student s) {
		if (this->name == s.name) {
			return true;
		}
		else {
			return false;
		}
		//for char* use strcmp -> returns 0 if they are equal
	}

	Student operator*(float value) {
		//IN +,/,- and * NEVER change your operands
		Student result = *this;
		result.age *= value;
		return result;
	}

	bool operator!() {
		if (this->age >= 18) {
			return true;
		}
		else {
			return false;
		}
	}

	//pre increment
	Student operator++() {
		this->age += 1;
		return *this;
	}

	//post increment
	Student operator++(int) {
		Student result = *this;
		this->age += 1;
		return result;
	}

	explicit operator Person() {
		Person p;
		p.age = this->age;
		p.name = this->name;
		return p;
	}

	explicit operator int() {
		return this->age;
	}

	bool operator()(int min, int max) {
		if (this->age >= min && this->age <= max) {
			return true;
		}
		else {
			return false;
		}
	}

	int& operator[](int index) {
		if (index >= 0 && index < 100)
			return this->grades[index];
		else
			throw "Wrong index";
	}

	//Student operator+(int v) {

	//}

	friend Student operator+(int v, Student s);
	friend void operator<<(ostream& console, const Student& s);
	friend void operator>>(istream& console, Student& s);
};

int Student::MIN_NAME_SIZE = 3;
//const int Student::MAX_NAME_SIZE = 255;
int Student::COUNTER = 0;

//Student operator++(Student s) {
//
//}
//
//Student operator++(Student s, int ) {
//
//}

Student operator+(int v, Student s) {
	Student result = s;
	result.age += v;
	return result;
}

//or Student operator*(float value, const Student& s) 
Student operator*(float value, Student s) {
	Student result = s;
	result.setAge(s.getAge() * value);
	return result;
}

void operator<<(ostream& console, const Student& s) {
	console << endl << "Student name: " << s.name;
	console << endl << "Student age: " << s.age;
}

void operator>>(istream& console, Student& s) {
	cout << endl << "Student new name: ";
	console >> s.name;
	cout << endl << "Student new age:";
	int age = 0;
	console >> age;
	s.setAge(age);
}

int main() {

	Student alice("Alice", 2);
	Student bob("Bob", 2, 20);

	Student temp("John Doe", 1, 0);


	//overload * to multiply student age by a value
	//student * float
	
	temp = bob * 1.2;

	//overload operators

	// operator =	
	bob = alice;

	// input and output streams << and >>
	cout << endl << bob;
	//cin >> bob;
	cout << endl << bob;

	//float * student
	cout << endl << "-----------------";
	temp = 1.2 * bob;
	cout << temp;
	cout << bob;

	//math operators - binary +=, -=, *=, /=
	bob += 2; //add 2 to Bob's age


	//math operators - binary +, -, * and /
	//these operator DON"T change the value of the operands
	bob = bob - 2; //create a copy of Bob with age - 2
	bob = 2 + bob;

	//logic operator - binary ==,>=,>,<,<=
	if (bob >= alice) {
		cout << endl << "Bob has an age bigger or equal than Alice";
	}

	if (bob == temp) {
		cout << endl << "They are the same";
	}

	////logic operator - unary - !
	//! should return true if the student has an age >= 18
	if (!bob) {
		cout << endl << "Bob can't buy an enery drink";
	}


	int vb = 10;
	//int vb2 = ++vb; //vb -> 11; vb2 -> 11
	int vb3 = vb++; //vb -> 11; vb3 -> 10


	////post an pre operators - ++obj, obj++, --obj, obj--
	Student temp = ++bob;  //create a copy of Bob with age + 1
	Student clone = bob++; //create a copy of Bob with age + 1



	////cast operator - (type)
	Person person = (Person)bob;
	int bobAge = (int)bob;



	////function operator - ()
	bool hasValidAge = bob(10, 35);// check if Bob age is between given limits

	////index operator - []
	int secondGrade = bob[1]; //read 2nd grade
	bob[1] = 10; //set 2nd grade

}