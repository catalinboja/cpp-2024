
// do's and don't
// dynamic arrays in C/C++
// dynamic array of strings
// dynamic array of chars
// dynamic array of numbers

// operations
// define and init arrays
// copy an array
// delete an array
// process array data: searching a value, 
// process arrays of numbers :computing the sum, average, minimum and maximum value


//2nd meeting - classes
//3rd meeting - operators

#include <string>
#include <iostream>
using namespace std;

int main() {
	//define dynamic/static arrays for testing
	// define and init arrays
	const char* location = "Bucharest";
	
	string locations[3] = { "Bucharest", "Ploiesti", "Sibiu" };
	int noOfLocations = 3;

	float distances[3] = { 11.5, 34.8, 67.9 };


	char* newLocation = new char[5] {"test"};
	//alternative
	newLocation = new char[strlen("Bucharest") + 1];
	strcpy_s(newLocation, strlen("Bucharest") + 1, "Bucharest");

	float* newDistances = new float[3] {10, 20, 30};
	string* newLocations = new string[2]{ "Bucharest","Timisoara" };

	int* heapValues = new int[1000];
	int valuesOnStack[1000];


	//delete[] newLocation;

	// copy an array into a static one
	char copyLocation[100];
	strcpy_s(copyLocation, 99, location);
	strcpy_s(copyLocation, 99, newLocation);

	string copyLocations[3];
	//copyLocations = new string[3];
	for (int i = 0; i < noOfLocations; i++) {
		copyLocations[i] = locations[i];
	}

	int noOfDistances = 3;
	float copyDistances[3];
	for (int i = 0; i < noOfDistances; i++) {
		copyDistances[i] = distances[i];
	}


	// copy an array into a dynamic one
	char* heapCopyOfLocation = nullptr;
	//allocate
	heapCopyOfLocation = new char[strlen(location) + 1];
	strcpy_s(heapCopyOfLocation, strlen(location) + 1, location);

	string* heapCopyOfLocations = nullptr;
	heapCopyOfLocations = new string[noOfLocations];
	for (int i = 0; i < noOfLocations; i++) {
		heapCopyOfLocations[i] = locations[i];
	}
	//delete[] heapCopyOfLocations;

	float* heapCopyOfDistances = nullptr;
	//float* heapCopyOfDistances = new float[5];

	if (heapCopyOfDistances != nullptr)
		delete[] heapCopyOfDistances;
	heapCopyOfDistances = new float[noOfDistances];
	for (int i = 0; i < noOfDistances; i++) {
		heapCopyOfDistances[i] = distances[i];
	}

	string name = "john";
	string name2;
	name2 = name;

	// delete an array
	//YOU CAN'T for STATIC ARRAYS
	//delete[] locations;

	delete [] heapCopyOfDistances;
	heapCopyOfDistances = nullptr;

	delete [] heapCopyOfLocation;
	heapCopyOfLocation = nullptr;

	delete [] heapCopyOfLocations;
	heapCopyOfLocations = nullptr;



	// process array data: searching a value
	const char* ASELocation = "Bucharest";
	const char* testLocation = new char[100] {"Bucharest"};

	//DON'T DO THIS
	if (ASELocation == "Bucharest") {
		cout << endl << "ASE location is Bucharest";
	}

	if (ASELocation == testLocation) {
		cout << endl << "ASE location is Bucharest";
	}

	//USE strcmp
	if (strcmp(ASELocation, "Bucharest") == 0) {
		cout << endl << "THE ASE location is Bucharest";
	}
	if (strcmp(ASELocation, testLocation) == 0) {
		cout << endl << "THE ASE location is Bucharest";
	}

	string student = "John";
	string newName = "John";

	if (student == "John") {
		cout << endl << "the name is John";
	}

	if (student == newName) {
		cout << endl << "the name is John";
	}

	cout << "The end";
}