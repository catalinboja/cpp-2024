
#include <iostream>
using namespace std;

//processing arrays

void printArray(int* values, int no) {
	cout << endl << "Array values: ";
	for (int i = 0; i < no; i++) {
		cout << " " << values[i];
	}
}

void initArrayWithGivenValue(int* values, int no, int value) {
	for (int i = 0; i < no; i++) {
		values[i] = value;
	}
}

void initArrayWithGivenValue2(int*& values, int no, int value) {
	for (int i = 0; i < no; i++) {
		values[i] = value;
	}
}

void initArrayWithGivenValue3(int** values, int no, int value) {
	for (int i = 0; i < no; i++) {
		*values[i] = value;
	}
}

void resizeArrays(int*& pValues, int &noElements, int newSize) {
	delete[] pValues;
	pValues = new int[newSize];
	noElements = newSize;
}

void resizeArrays2(int* * pValues, int& noElements, int newSize) {
	delete[] *pValues;
	*pValues = new int[newSize];
	noElements = newSize;
}

int main() {

	int values[50];
	int noOfValues = 50;

	initArrayWithGivenValue(values, noOfValues, 0);
	printArray(values, noOfValues);


	const int number = 10;
	//number = 20;

	//NEVER
	//values = new int[51];

	int* valuesInHeap = new int[50];
	int noOfValuesInHeap = 50;

	initArrayWithGivenValue(valuesInHeap, noOfValuesInHeap, 1);
	printArray(valuesInHeap, noOfValuesInHeap);

	//resize the array
	//valuesInHeap = new int[60]; // memory leak
	//valuesInHeap = new int[60]; // memory leak
	//valuesInHeap = new int[60]; // memory leak
	//valuesInHeap = new int[60]; // memory leak
	//valuesInHeap = new int[60]; // memory leak


	delete[] valuesInHeap; // avoid the memory leak
	valuesInHeap = new int[60]; 

	// resizeArrays(valuesInHeap, noOfValuesInHeap, 100);
	resizeArrays2(&valuesInHeap, noOfValuesInHeap, 100);
	initArrayWithGivenValue(valuesInHeap, noOfValuesInHeap, 10);
	printArray(valuesInHeap, noOfValuesInHeap);

	return 0;
}

