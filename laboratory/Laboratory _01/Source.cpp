
//recap

// data types (focus on char)
// enums
// arrays
// pointers
// functions

#include <stdio.h>

enum color { red = 10, blue = 20, black };

void printHelloMessage() {
	printf("\n Hello !");

	int array[100];
	//int index = 10000;
	int index = 10;
	array[index] = 10;	//index out of bounds exception

}

void main() {
	int noOfStudents;
	int noOfProfessors;

	noOfStudents = 10;
	noOfProfessors = 5;

	printHelloMessage();

	//data types
	int intValue = 10;		//4 bytes or 32 bits
	unsigned int anotherIntValue = 20;	//4 bytes
	short int aSmallNumber = 100; //2 bytes or 16 bits
	long long int aBigValue = 1000; //8 bytes or 64 bits

	float aRealValue = 2.3; //4 bytes
	double aPrecisionRealValue = 0.00000009; //8 bytes

	char aVerySmallNumber; //1 byte - 8 bits
	//char initial = "A"; //['A','\0']
	char initial = 'A';

	initial = 48; //ASCII Code of '0'

	color favouriteColor = color::blue;
	//favouriteColor = BLUE;
	//favouriteColor = 23;

	printf("%c", initial);
	printf("\n Color: %d", favouriteColor);

	//arrays
	int values[10];
	values[0] = 10; //first
	values[9] = 100; //last

	int someValues[] = {1,2,3,4,5}; //only at the definition
	int otherValues[5] = {1,2,3,4,5}; //only at the definition
	//someValues = {10,20,30,40,50};


	char name[100];
	name[0] = 'J';
	name[1] = 'o';
	name[2] = 'h';
	name[3] = 'n';
	name[4] = '\0';

	char anotherName[100] = "Alice";
	char anotherName2[] = "Alice";
	//anotherName = "Bob";

	printf("\n Name is %s", name);
	printf("\n Name is %s", anotherName);
	printf("\n Name is %s", anotherName2);

}