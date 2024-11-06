#include <iostream>
#include <string>
#include <string.h>
#include "ExamSubject.h"
#include "Student.h"
using namespace std;


void takeExam(ExamSubject subject) {

}

int main() {
	Student student;
	initStudentName(student, "John");

	student.name = "John";
	//student.name = "";

	for (int i = 0; i < 100; i++) {
		cout << endl << "Bla bla";
	}

	ExamSubject subject;
	//subject.course = "";
	subject.initCourseName("OOP");
	cout << endl << "Exam for "
		<< subject.getExamCourse();

	ExamSubject oopExam("OOP");
	takeExam(oopExam);
}