#include <iostream>
#include <string>

using namespace std;

// enum
// init arrays of numbers/strings, arrays of chars

enum class ExamType {ORAL = 10, COMPUTER = 40, QUIZ };

class LaboratoryTest {
	string name;
public:
	LaboratoryTest(string name) : name(name) {

	}

	LaboratoryTest() {
		this->name = "";
	}
};
class Exam {
	string* studentNames;
	int noStudents;
	char* courseName;
	float* studentGrades;
	ExamType type;
public:
	Exam(const char* name,
		string* students,
		float* grades,
		int noStudents,
		ExamType type) {

		//copy the name
		this->courseName = new char[strlen(name) + 1];
		strcpy_s(this->courseName, strlen(name) + 1, name);

		//copy student names array
		this->studentNames = new string[noStudents];
		for (int i = 0; i < noStudents; i++) {
			this->studentNames[i] = students[i];
		}

		//copy student grades
		this->studentGrades = new float[noStudents];
		for (int i = 0; i < noStudents; i++) {
			this->studentGrades[i] = grades[i];
		}

		//copy the rest
		this->type = type;
		this->noStudents = noStudents;
	}

	ExamType convert(int typeCode) {
		switch (typeCode)
		{
		case 10:
			return ExamType::ORAL;
		case 40:
			return ExamType::COMPUTER;
		case 41:
			return ExamType::QUIZ;
		default:
			throw exception("Invalid code");
		}
	}

	void readExamTypeFromConsole() {
		cout << endl << "New exam type (ORAL - 10, COMPUTER - 40, QUIZ - 41): ";
		int newExamType;
		cin >> newExamType;

		try {
			this->type = this->convert(newExamType);
		}
		catch (exception e) {
			cout << endl << "Input code is invalid";
		}
	}

	string getTypeAsString() {
		switch (this->type)
		{
		case ExamType::ORAL:
			return "Oral exam";
		case ExamType::QUIZ:
			return "Quiz exam";
		case ExamType::COMPUTER:
			return "Computer exam";
		default:
			return "Unknown";
		}
	}

	//overload cast to string
	operator string() {
		return this->courseName;
	}

	//overload cast to int
	explicit operator int() {
		return this->noStudents;
	}

	operator LaboratoryTest() {
		return LaboratoryTest(this->courseName);
	}
};

// NOT OK because you return an address from stack
int* createArray() {
	int values[10];
	for(int i = 0; i < 10; i++){
		values[i] = i + 1;
	}
	return values;
}

int* createArrayOk() {
	int* values = new int[10];
	for (int i = 0; i < 10; i++) {
		values[i] = i + 1;
	}
	return values;
}

//NOT OK 
Exam* createExam() {
	Exam examTemp("Temp",nullptr, nullptr,0, ExamType::ORAL);
	return &examTemp;
}

Exam* createExam() {
	Exam* examTemp = new Exam("Temp", nullptr, nullptr, 0, ExamType::ORAL);
	return examTemp;
}



int main() {
	
	ExamType exType = ExamType::COMPUTER;
	if (exType == ExamType::COMPUTER) {
		cout << endl << "Exam at computer";
	}

	char course[] = "OOP";
	string students[] = { "John", "Alice" };
	float grades[] = {8.5, 10};

	Exam examOOP(course, students, grades, 2, ExamType::QUIZ);
	Exam examDS("DS", students, grades, 2, ExamType::COMPUTER);

	Exam* webTech =
		new Exam("Web Tech", students, grades, 2, ExamType::COMPUTER);


	examOOP.readExamTypeFromConsole();
	cout << endl << examOOP.getTypeAsString();

	float floatVb = (float)34.799999999999999999999999999;
	int* pointer = (int*)malloc(100);

	string examName = (string)examOOP;
	cout << endl << "Exam name: " << examName;

	int noStudentsInExam = (int)examOOP;
	cout << endl << "No students: " << noStudentsInExam;

	int value = 2 + (int)examOOP;
	cout << endl << "Value: " << value;

	LaboratoryTest test = examOOP;

	int* values = createArrayOk();

	cout << endl << "values[0]: " << values[0];

}