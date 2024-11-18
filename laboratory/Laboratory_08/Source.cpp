
//Reminder
// Nov 25, 10:30 AM - laboratory test
// 2nd year mandatory
// 3rd year and supplementary 
//	- 1/2 on Monday - 1/2 on Friday 15:00
//  - the list is on online.ase.ro at the seminar

#include <iostream>
#include <string>
using namespace std;

class Box {
	const string awb; //don't init the constants 
	string street = "";
	int streetNo = 0;
	string city = "";
	float weight = 0;

public:

	const static float MAX_WEIGHT;

	Box(string awb): awb(awb), city("Bucharest") {
		//this->city = "Bucharest";
	}

	Box(string awb, string city, float weight)
		:awb(awb), city(city), weight(weight)
	{
		//this->city = city;
		//this->weight = weight;
	}

	//operator =
	void operator=(const Box b) {
		this->city = b.city;
		this->weight = b.weight;
		this->street = b.street;
		this->streetNo = b.streetNo;
		//this->awb = b.awb;
	}

	string getAWB() {
		return this->awb;
	}

	void setCity(string newCity) {
		this->city = newCity;
	}

	void operator-=(double value) {
		this->weight -= value;
	}

	void operator-=(const char* value) {

	}

	bool operator!() {
		if (this->weight < 1)
			return true;
		else
			return false;
	}

	explicit operator float() {
		return this->weight;
	}


	friend void operator <<(ostream& console, Box b);
	friend void operator>>(istream& console, Box& b);
};

const float Box::MAX_WEIGHT = 1000;

void operator <<(ostream& console, Box b) {
	console << endl << "Box details:";
	console << endl << "AWB: " << b.getAWB();
	console << endl << "Address: " << b.city << " Street "
		<< b.street << ", no " << b.streetNo;
	console << endl << "Weight: " << b.weight;
}

void operator>>(istream& console, Box& b) {
	cout << endl << "New city:";
	string newCity;
	console >> newCity;
	b.setCity(newCity);
	cout << endl << "New Street:";
	console >> b.street;
	cout << endl << "New Street number:";
	console >> b.streetNo;
	cout << endl << "New weight:";
	console >> b.weight;
}

//void operator-=(Box& b, float value) {
//
//}


int main() {
	Box b1("BU232024");
	Box b2("SMD03BUC", "Bucharest", 0.3);

	b1 = b2; //operator =
	Box b3 = b2; //copy ctor

	cout << b2;
	cin >> b2;
	cout << b2;

	b2 -= 0.2; //decrease weight by 0.2

	b2 -= "34";

	float weight = 0.5;

	if (!b2) {
		cout << endl << "Is a light box (less than 1 kg)";
	}

	float value = (float)b2; //convert the box to its weight value
	

}

