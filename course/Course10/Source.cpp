#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Student {
public:
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

	Student(): noGrades(0), name("John"),isErasmus(false),age(0) {

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

	static void writeStudentsToFile(
		string fileName, Student* students, int noStudents) {
		ofstream file(fileName);
		if (file.is_open()) {
			file << endl << "Students Report";
			for (int i = 0; i < noStudents; i++) {
				students[i].writeToStream(file);
			}
			file.close(); //DON'T forget to close the file
		}
		else {
			throw exception("Issues with the file");
		}
	}

	static Student* readStudentsFromFile(string filename, int& noStudents) {
		ifstream file(filename);
		if (file.is_open()) {
			file >> noStudents;
			Student* students = new Student[noStudents];
			for (int i = 0; i < noStudents; i++) {
				string name;
				file >> name; //file >> students[i].name
				int age;
				file >> age;
				string isErasmus;
				file >> isErasmus;
				bool isErasmusCheck = isErasmus == "true";
				int grades[100];
				int noGrades;
				file >> noGrades;
				for (int j = 0; j < noGrades; j++) {
					file >> grades[j];
				}
				students[i].name = name;
				students[i].age = age;
				students[i].isErasmus = isErasmusCheck;
				students[i].noGrades = noGrades;
				for (int j = 0; j < noGrades; j++) {
					students[i].grades[j] = grades[j];
				}
			}
			return students;
		}
		else {
			throw exception("Issues with the file");
		}
	}

};



int main() {
	int grades[] = { 10,10,9 };
	Student alice("Alice", grades, 3, false, 20);

	Student students[3];
	students[0] = alice; //operator =
	students[1] = Student("Bob", grades, 3, true, 21);

	Student* pStudents = new Student[3];
	pStudents[0] = alice;
	pStudents[1] = Student("Bob", grades, 3, true, 21);

	alice.writeToStream(cout);

	//files 
	//writing into files
	//ofstream outputFile();

	Student::writeStudentsToFile("Report.txt", students, 3);

	cout << endl << "Done";

	//rules for generating text input files
	//write a single value on a single line - one line one value
	//for a collection of values write the number of values before the values

	Student* newStudents = nullptr;
	int noNewStudents = 0;

	newStudents = Student::readStudentsFromFile("Input.txt", noNewStudents);
	cout << endl << noNewStudents;
	newStudents[1].writeToStream(cout);


}