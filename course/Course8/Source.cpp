
// overloaded operators
// constant attributes
// static methods

#include <iostream>
#include <string>
using namespace std;

class Utility {
public:
	static char* copyCharArray(const char* value) {
		return nullptr;
	}
};

class Person {

};

class Student {


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

	Student(string name): id(1), uniqueId(++Student::COUNTER){
		//this->id = 1;
		//Student::COUNTER += 1;
		//this->uniqueId = Student::COUNTER;

		if (name.size() < Student::MIN_NAME_SIZE) {
			throw "Wrong name";
		}
	}

	Student(string name, int id): id(id), uniqueId(++Student::COUNTER){
		this->name = name;
		//this->id = id;
	}

	// : is named the ctor initialization list
	Student(string name, int id, int inputAge) 
		: id(id),name(name), age(inputAge), uniqueId(++Student::COUNTER){
		//this->name = name;
		//this->id = id;
	}

	//don't provide a setter for id -> no one can change it


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
	void operator=(const Student& s) {
		this->age = s.age;
		//this->id = s.id;
		this->name = s.name;
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

	//Student operator+(int v) {

	//}

	friend Student operator+(int v, Student s);
};

int Student::MIN_NAME_SIZE = 3;
//const int Student::MAX_NAME_SIZE = 255;
int Student::COUNTER = 0;

Student operator+(int v, Student s) {
	Student result = s;
	result.age += v;
	return result;
}

void operator<<(ostream& console, Student s) {

}

void operator>>(istream& console, Student& s) {

}

int main() {
	string name = "John";
	//Student::MIN_NAME_SIZE = 0;
	//Student::MAX_NAME_SIZE = 500;

	//Student temp("ajkfhdjkfhwklf;lr");

	if (name.size() >= Student::getNameMinSize() &&
		name.size() < Student::MAX_NAME_SIZE) {
		Student john("John");
		john.takeExam("OOP");

		//john.id = 100;
	}

	Student::checkUniversityFees();

	Student alice("Alice", 2);
	Student bob("Bob", 2, 20);
	

	const int vb = 10;
	//vb = 20;

	//overload operators

	// operator =	
	bob = alice;

	// input and output streams << and >>
	cout << endl << bob;
	cin >> bob;

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

	//logic operator - unary - !
	if (!bob) {
		cout << endl << "Bob can't buy an enery drink";
	}

	//post an pre operators - ++obj, obj++, --obj, obj--
	Student temp = ++bob; //create a copy of Bob with age + 1
	Student clone = bob--;

	//cast operator - (type)
	Person person = (Person)bob;
	int bobAge = (int)bob;

	//function operator - ()
	bool hasValidAge = bob(10, 35);// check if Bob age is between given limits

	//index operator - []
	int secondGrade = bob[1];
}