#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// reading & writing from/to binary files
// serialization an deserialization
// inheritance

class Student {
public:
	//char* temp = new char[100];
	string name;
	int grades[100];
	int noGrades;
	bool isErasmus;
	int age;

	Student(string name, int* grades,
		int noGrades, bool isErasmus, int age)
		:
		name(name), isErasmus(isErasmus), age(age) {
		for (int i = 0; i < noGrades; i++) {
			this->grades[i] = grades[i];
		}
		this->noGrades = noGrades;
	}

	Student() : noGrades(0), name("John"), isErasmus(false), age(0) {

	}

	//method to write a Student data into a file stream
	void writeToStream(ostream& output) {
		output << endl << this->name << " | " << this->age;
		output << " | " << (this->isErasmus ? "Is Erasmus" : "NO Erasmus");
		output << endl << "Grades:";
		for (int i = 0; i < this->noGrades; i++) {
			output << " " << this->grades[i];
		}
	}

	//method to serialize in a binary way a Student
	void serialize(ofstream& binFile) {
		//write the values one by one
		//write the name - ONLY the chars like "Alice" + '\0'
		//if name was a char*
		//binFile.write(this->name, strlen(this->name) + 1)

		//for strings and char arrays put the size of it
		int nameSize = this->name.size() + 1;
		binFile.write((char*)&nameSize, sizeof(int));

		binFile.write((char*)this->name.c_str(), this->name.size() + 1);
		//write the no of grades
		binFile.write((char*)&this->noGrades, sizeof(int));
		//write the grades
		//option 1 write the entire array of 100 ints
		//binFile.write((char*)this->grades, 100 * sizeof(int));
		//binFile.write((char*)this->grades, sizeof(Student::grades));

		//option 2 - write only the values that we use
		binFile.write((char*)this->grades, this->noGrades * sizeof(int));
		//for (int i = 0; i < this->noGrades; i++) {
		//	binFile.write((char*)&this->grades[i], sizeof(int));
		//}

		//write isErasmus
		binFile.write((char*)&this->isErasmus, sizeof(bool));
		//write the age
		binFile.write((char*)&this->age, sizeof(int));
	}

	void deserialize(ifstream& binFile) {
		//read the name
		char temp[1000];
		int nameSize;
		binFile.read((char*) & nameSize, sizeof(int) );
		binFile.read(temp, nameSize *sizeof(char));

		this->name = string(temp);
		//if name was char*
		//delete[] this->name;
		//this->name = new char[nameSize];
		//strcpy_s(this->name, nameSize, temp);

		//read no of grades
		binFile.read((char*)&this->noGrades, sizeof(int));
		//read rades
		for (int i = 0; i < this->noGrades; i++) {
			binFile.read((char*)&this->grades[i], sizeof(int));
		}
		//read is Erasmus
		binFile.read((char*) & this->isErasmus, sizeof(bool));

		//read age
		binFile.read((char*)&this->age, sizeof(int));

	}

};


void operator<<(ostream& stream, Student& stud) {
	stud.writeToStream(stream);
}


int main() {
	int grades[] = { 10,10,9 };
	Student alice("Alice", grades, 3, false, 20);
	Student bob("Bob", grades, 3, true, 21);

	Student students[3];
	students[0] = alice; //operator =
	students[1] = Student("Bob", grades, 3, true, 21);

	Student* pStudents = new Student[3];
	pStudents[0] = alice;
	pStudents[1] = Student("Bob", grades, 3, true, 21);

	alice.writeToStream(cout);

	//creating binary files
	//opening binary file in append mode
	ofstream binaryFile("student.data", ios::binary | ios::trunc );

	//creating a text logs file
	ofstream logFile("logs.txt", ios::app);
	logFile << endl << "Example with files";

	// common mistake 1
	//write a student in a binary file
	// << is always writing strings
	//binaryFile << alice;

	//common mistake 2
	//when using write
	//1. what value o you want to write
	//2. check if is an address, if not get the address with &
	//3. check if is a char*, if not cast it
	//4. 2nd param is the no of bytes

	// 2nd common mistake - write objects with pointers
	// write the values not the pointers/addresses
	// object serialization
	//binaryFile.write((char*)&alice, sizeof(Student));

	alice.serialize(binaryFile);
	binaryFile.close();

	cout << bob;

	ifstream binFile("student.data", ios::binary);
	bob.deserialize(binFile);
	binFile.close();

	cout << bob;

}
