#pragma once

#include <string>
using namespace std;

class ExamSubject
{
private:
	std::string course = "";
	int* pointesPerRequirement = nullptr;
	int noRequirements = 0;
	float maximumAllowedTime = 0;
public:
	//always validate the input
	void initCourseName(string newName) {
		if (newName.empty()) {
			throw "Wrong name";
		}
		this->course = newName;
	}

	string getExamCourse() {
		return this->course;
	}

	float getTime() {
		return this->maximumAllowedTime;
	}

	int* getPoints() {
		//return this->pointesPerRequirement;
		int* copy = new int[this->noRequirements];
		for (int i = 0; i < this->noRequirements; i++) {
			copy[i] = this->pointesPerRequirement[i];
		}
		return copy;
	}

	int getNoPoints() {
		return this->noRequirements;
	}

	void setPoints(int* newPoints, int newNoPoints) {
		this->noRequirements = newNoPoints;
		delete[] this->pointesPerRequirement;
		this->pointesPerRequirement = new int[newNoPoints];
		for (int i = 0; i < newNoPoints; i++) {
			this->pointesPerRequirement[i] = newPoints[i];
		}
	}

	ExamSubject() {

	}

	ExamSubject(string name, int* points, int noPoints, float maxTime) {
		this->initCourseName(name);
		this->setPoints(points, noPoints);
		if (maxTime <= 0) {
			throw "Wrong max time";
		}
		this->maximumAllowedTime = maxTime;
	}

	ExamSubject(string name) {
		this->initCourseName(name);
		//redundant - they already inited at definition
		this->pointesPerRequirement = nullptr;
		this->noRequirements = 0;
		this->maximumAllowedTime = 0;
	}

	~ExamSubject() {
		delete[] this->pointesPerRequirement;
	}

	//copy ctr
	ExamSubject(const ExamSubject& subject) {
		this->course = subject.course;
		this->setPoints(subject.pointesPerRequirement, subject.noRequirements);
		this->maximumAllowedTime = subject.maximumAllowedTime;

		//subject.course = this->course;
		//this->pointesPerRequirement = subject.pointesPerRequirement;
	}


};
