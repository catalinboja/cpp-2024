
#include <iostream>

//using pointers to pass data to functions
//using pointers to manage extra memory - HEAP vs STACK
//default values for data


//extra meeting on Thursday, 7:30 PM on ZOOM

namespace Student {
	int noStudents;
}

namespace Faculty {
	int noStudents;
}


void print2Values(int value1, int value2) {
	std::cout << std::endl << "Value 1: " << value1;
	std::cout << std::endl << "Value 2: " << value2;
}

void interchange(int value1, int value2) {
	int temp = value1;
	value1 = value2;
	value2 = temp;
}

void interchangeWithPointers(int* pValue1, int* pValue2) {
	int temp = *pValue1;
	*pValue1 = *pValue2;
	*pValue2 = temp;
}

void interchangeWithReferences(int& value1, int& value2) {
	int temp = value1;
	value1 = value2;
	value2 = temp;
}

int* init100ElementsArray() {
	int elements[100];
	for (int i = 0; i < 100; i++) {
		elements[i] = i + 1;
	}

	std::cout << std::endl << "-------------------" << std::endl;
	for (int i = 0; i < 100; i++) {
		std::cout << " " << elements[i];
	}
	return elements;
}

int* init100ElementsArrayInHeap() {
	int* elements = new int[100];
	for (int i = 0; i < 100; i++) {
		elements[i] = i + 1;
	}

	std::cout << std::endl << "-------------------" << std::endl;
	for (int i = 0; i < 100; i++) {
		std::cout << " " << elements[i];
	}
	return elements;
}

int main() {

	int vb1 = 10;
	int vb2 = 20;

	Student::noStudents = 100;
	Faculty::noStudents = 50;

	print2Values(vb1, vb2);

	int temp = vb1;
	vb1 = vb2;
	vb2 = temp;

	print2Values(vb1, vb2);

	//interchange(vb1, vb2);
	interchangeWithPointers(&vb1, &vb2);

	print2Values(vb1, vb2);

	interchangeWithReferences(vb1, vb2);

	print2Values(vb1, vb2);

	float prices[100];
	int noPrices;


	//int* myArray = init100ElementsArray();
	int* myArray = init100ElementsArrayInHeap();

	std::cout << std::endl << "-------------------" << std::endl;
	for (int i = 0; i < 100; i++) {
		std::cout << " " << myArray[i];
	}

	return 0;
}