#pragma once
#include <string>
using namespace std;

struct Student {
	string name;
};

void initStudentName(Student& s, string newName) {
	if (newName.empty()) {
		//cout << endl << "Empty name";
		throw "Wrong name";
	}
	s.name = newName;
}