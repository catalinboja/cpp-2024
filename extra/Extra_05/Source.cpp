#include <iostream>
#include <string>
using namespace std;

class NullBenefitsException : public exception {
public:
	//NullBenefitsException(const char* msg): exception(msg) {
	//}

	NullBenefitsException(string msg) 
		: exception(msg.c_str()) {
	}
};

enum MemberType { PREMIUM = 10, GOLD, PLATINUM};

class Member {
protected:
	string* benefits;
	int noBenefits;
	static int NO_MEMBERS;
	MemberType type;

	//dynamic 
	//NOT THIS
	char** messages;

	//THIS YES
	string* stuff;
	char* name;
	int* values;
	float* otherValues;




public:

	static const int MIN_NO_BENEFITS;

	Member(string* benefits, int no) {
		this->noBenefits = no;
		this->benefits = new string[no];
		for (int i = 0; i < no; i++) {
			this->benefits[i] = benefits[i];
		}
		Member::NO_MEMBERS += 1;
		//Member::NO_MEMBERS++;
		//++Member::NO_MEMBERS;
		//Member::NO_MEMBERS = Member::NO_MEMBERS + 1;
		//Member::NO_MEMBERS = 1 + Member::NO_MEMBERS;
	}

	void setBenefits(string* newBenefits, int no) {

		if (newBenefits == nullptr) {
			//throw NullBenefitsException();
			NullBenefitsException* pEx = 
				new NullBenefitsException("test");
			throw pEx;
		}
		if (no <= 0) {
			throw runtime_error("No benefits");
		}

		delete[] this->benefits;
		this->noBenefits = no;
		this->benefits = new string[this->noBenefits];
		for (int i = 0; i < this->noBenefits; i++) {
			this->benefits = newBenefits;
		}
	}

	int getNoBenefits() {
		return this->noBenefits;
	}

	//string* getBenefits() {
	//	return this->benefits;
	//}

	string* getBenefits() {
		string* copy = new string[this->noBenefits];
		for (int i = 0; i < this->noBenefits; i++) {
			copy[i] = this->benefits[i];
		}
		return copy;
	}

	~Member() {
		delete[] this->benefits;
		Member::NO_MEMBERS -= 1;
	}

	static int getNoMembers() {
		return Member::NO_MEMBERS;
	}
};

int Member::NO_MEMBERS = 0;
const int Member::MIN_NO_BENEFITS = 1;

class PremiumMember: public Member {
	int points;

	void doSomething() {
		this->noBenefits = 0;
	}
};

void doAnAction(Member& m) {

}

//void doAnAction(Member* m) {
//	m->vb = 0;
//}


//virtual methods
class Person {
	//attributes
	string name;
	int age;
public:

	//overriding
	virtual void printInfo() {
		cout << endl << "I am a person";
	}

	virtual string getName() = 0; //virtual pure


	virtual ~Person(){}

};


class Employee: public Person {
	float salary;
public:
	//DON'T
	//void printInfoOfEmployee() {
	//	cout << endl << "I am a person";
	//}

	////overriding
	//void printInfo() {
	//	cout << endl << "I am an employee";
	//}

	string getName() {
		return "";
	}

	~Employee(){}


};

class Student : public Person {
	string faculty;
public:
	Student(){}
	Student(string Faculty){}

	//overriding
	void PrintInfo() {
		cout << endl << "I am a student";
		Person::printInfo();
	}

	string getName() {
		return "";
	}
};

class Prof : public Person {
	string university;
public:
	//overriding
	void printInfo() {
		cout << endl << "I am a prof";
		//Student::printInfo();
	}

	string getName() {
		return "";
	}
};






int main() {
	string benefits[] = { "SPA", "Breakfast" };
	Member m1{ benefits, 2 };

	doAnAction(m1);


	try
	{
		string newBenefits[] = { "SPA", "Breakfast", "See View"};
		//m1.setBenefits(nullptr, 3);
		throw 5;
		//int vb = 0;
		//int result = 30 / vb;
	}
	catch (NullBenefitsException ex) {
		cout << endl << "NULL pointer ";
	}
	catch (NullBenefitsException* pEx) {
		cout << endl << "NULL pointer " << pEx->what();
		delete pEx;
	}
	catch (...) {
		cout << endl << "Houston we have a problem !";
	}


	string benefits2[] = { "SPA", "Breakfast" };
	Member m2{ benefits2, 2 };

	string* yourBenefits = m2.getBenefits();
	int noBenefits = m2.getNoBenefits();

	for (int i = 0; i < noBenefits; i++) {
		cout << endl << "Benefit: " << yourBenefits[i];
	}

	yourBenefits[1] = "Room service";

	string* yourBenefitsCopy = m2.getBenefits();
	for (int i = 0; i < noBenefits; i++) {
		cout << endl << "Benefit: " << yourBenefitsCopy[i];
	}

	delete[] yourBenefits;
	delete[] yourBenefitsCopy;

	//Member::NO_MEMBERS = 100;
	// 
	//Member::MIN_NO_BENEFITS = 100;

	cout << endl << "Min no of benefits " 
		<< Member::MIN_NO_BENEFITS;

	//cout << endl << "No Members: " << Member::NO_MEMBERS;
	cout << endl << "No Members: " << Member::getNoMembers();


	//inheritance + virtualization example
	//Student students[1000]; //1000 student objects 
	//Prof professors[500];
	//Employee admin[200];

	//Student* students[1000]; // 1000 pointers to objects

	//Person persons[5];
	//persons[0] = Student(); // UP-CASTING
	//persons[1] = Person(); //UP-CASTING
	//persons[2] = Prof(); //UP-CASTING

	//Person p;

	Person* persons[3];
	persons[0] = new Student(); // UP-CASTING
	persons[1] = new Employee(); // UP-CASTING 
	persons[2] = new Prof(); // UP-CASTING

	for (int i = 0; i < 3; i++) {
		persons[i]->printInfo(); 
		
		//EARLY-BINDING - without virtual
		// execute the method specific to the variable type
		// delete persons[i];

		//LATE-BINDING - with virtual
		//execute the method specific to the object type
		// at the address location
		//persons[i]->_vfptr[0]();
	}

	MemberType type;
	type = MemberType::PREMIUM;

	if (type == MemberType::PREMIUM) {
		cout << endl << "Is premium";
	}

}