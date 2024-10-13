#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

struct Person {
	int code;
	int age;
	char name[100];
};

void printPerson(Person aPerson) {
	//Person person;
	std::cout << std::endl << "Persone code: " << aPerson.code;
	std::cout << std::endl << "Persone age: " << aPerson.age;
	std::cout << std::endl << "Persone name: " << aPerson.name;
}

void initPerson(Person person, int age, int code, const char* name) {
	person.age = age;
	person.code = code;
	strcpy_s(person.name, name);
}

void initPerson2(Person* person, int age, int code, const char* name) {
	person->age = age;
	person->code = code;
	strcpy_s(person->name, name);
}

int main() {

	Person person;
	person.code = 1;
	//person.age = 27;
	//person.name[0] = '\0';
	//strcpy_s(person.name, "John Doe");

	initPerson(person, 27, 1, "John Doe");

	initPerson2(&person, 27, 1, "Bob");

	printPerson(person);
}
