#include <iostream>


//a, b and values are on doSomething stack
// oneMilBuffer is a pointer variable on doSomething stack
// the 1 mil byte array is in HEAP 
void doSomething(int a, int b) {
	int values[100];

	//needs 1 million bytes

	char* oneMilBuffer = new char[1e6];
	//char* oneMilBuffer = (char*)malloc(1e6);

	delete[] oneMilBuffer;
}

int add(int a, int b) {
	return a + b;
}

char* doSomethingAndKeepTheMemory() {

	//needs 1 million bytes
	//IF you see NEW is in HEAP
	char* oneMilBuffer = new char[1e6];
	//char* oneMilBuffer = (char*)malloc(1e6);

	return oneMilBuffer;
}

struct Student {
	int age;
	int code;
	char* name;
};

Student createStudentFromConsole() {
	Student stud;
	stud.age = 23;
	stud.code = 1;

	return stud;
}




//values are on main stack
int main() {

	int values[1000];

	char* bufferAddress = doSomethingAndKeepTheMemory();

//dynamic arrays
//of numbers, students........but not chars
//1. define it
	int* newValues;
	Student* students = new Student[100];
	//2. create it -> allocate it -> IN HEAP
	newValues = new int[100];
	//3. play it -> process it
	//3.1 init the values
	for (int i = 0; i < 100; i++) {
		newValues[i] = 0;
	}
	//3.2 process the values (add them, max, min, average, search....anything)
	//4. copy arrays
	int* copy = new int[100];
	for (int i = 0; i < 100; i++) {
		copy[i] = newValues[i];
	}

	//5. resize and add more elements
	int* newCopy = new int[200]; //double the size
	for (int i = 0; i < 100; i++) {
		newCopy[i] = copy[i];
	}


	//6. delete it
	delete[] copy;
	delete[] newValues;
//of chars
//1. define it
	char* name;
//2. create it -> allocate it -> IN HEAP
	name = new char[100];
//3. play it -> process it
//3.1 init the values
	//like saying there is no name
	name[0] = '\0';

	//DON'T 
	name[0] = 'J';
	name[1] = 'o';
	name[2] = 'h';
	name[3] = 'n';
	name[4] = '\0';

	strcpy_s(name,99, "John");
	//3.2 process the values (search for substrings, text operations)
	//4. copy arrays

	char* nameCopy = new char[100];
	strcpy_s(nameCopy, 99, name);

	//5. resize it
	char* newNameCopy = new char[200];
	strcpy_s(newNameCopy, 199, nameCopy);

	//6. concatenate strings

	//7. delete it
	delete[] nameCopy;
	delete[] copy;





	return 0;
}