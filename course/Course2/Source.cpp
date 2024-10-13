
#include <iostream>
using namespace std;

void printNumber(int number) {
	cout << endl << "Number value :" << number;
}

void changeVariableValue(int variable, int newValue) {
	variable = newValue;
	//noOfPersons = newValue;
}

void changeVariableValue2(int* pointerToVariable, int newValue) {
	*pointerToVariable = newValue;
	//noOfPersons = newValue;
}

int main() {


	int n;		//DON'T
	int NoOfStudents; //CAMEL CASE
	int noOfStudents; //MIXED CAMEL CASE
	int no_of_students; //SNAKE
	//int no-of-students; //KEBAB
	int nNoOfStudents; //HUNGARIAN

	noOfStudents = 10;

	//pointers
	int noOfPersons;

	//pointer to a memory space where an int will be
	//stores always numbers which are addresses
	int* pointerToNoOfPersons;

	//init pointers
	noOfPersons = 10;
	pointerToNoOfPersons = (int*)10; //NOT SAFE

	//init with a variable address
	pointerToNoOfPersons = &noOfPersons;

	noOfPersons = 1000;
	std::cout << "\n No of persons: " << noOfPersons;



	//generic pointer
	void *pointerToEverything;


	//playing with values at different addresses
	*pointerToNoOfPersons = 2000;

	std::cout << "\n No of persons: " << noOfPersons;

	printNumber(noOfPersons);

	changeVariableValue(noOfPersons, 3000);
	printNumber(noOfPersons);

	changeVariableValue2(&noOfPersons, 3000);
	printNumber(noOfPersons);

	//return 0;
}