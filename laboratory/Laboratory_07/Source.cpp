#include <iostream>
#include <string>
using namespace std;

class Courier {
	string* addresses = nullptr; //places where deliveries must be done
	int noLocations = 0;
	string phone = "";
	bool hasAnElectricVan = false;

	static int ADDRESS_MIN_SIZE;
	static int PHONE_SIZE;

public:
	static int NO_LOCATIONS_IN_BUCHAREST;

private:
	Courier() {
		this->phone = "";
	}

public:
	void setPhone(string phoneNo) {
		if (phoneNo.size() != Courier::PHONE_SIZE) {
			throw "Phone size wrong";
		}
		this->phone = phoneNo;
	}

	void usesAnElectricVan() {
		this->hasAnElectricVan = true;
	}

	void usesAClassicVan() {
		this->hasAnElectricVan = false;
	}

	void addAddress(string newAddress) {
		if (newAddress.size() < Courier::ADDRESS_MIN_SIZE) {
			throw "Wrong address";
		}

		string* newArray = new string[this->noLocations + 1];
		for (int i = 0; i < this->noLocations; i++) {
			newArray[i] = this->addresses[i];
		}
		newArray[this->noLocations] = newAddress;
		this->noLocations += 1;

		delete[] this->addresses;
		this->addresses = newArray;

		//TO DO implement a method to lower case the tring
		if (newAddress.find("Bucharest") != -1) {
			Courier::NO_LOCATIONS_IN_BUCHAREST += 1;
		}
	}

	void print() {
		cout << endl << "Courier phone: " << this->phone;
		if (this->hasAnElectricVan) {
			cout << endl << "The van is eletric";
		}
		if (this->addresses != nullptr) {
			cout << endl << "Locations: ";
			for (int i = 0; i < this->noLocations; i++) {
				cout << endl << this->addresses[i];
			}
		}
	}

	Courier(string phone) {
		this->setPhone(phone);
	}

	~Courier() {
		//TO DO: check if any of the addresses are in Bucharest
		delete[] this->addresses;
	}

	Courier(const Courier& courier) {
		//solution 1
		for (int i = 0; i < courier.noLocations; i++) {
			this->addAddress(courier.addresses[i]);
		}

		//solution 2
		//this->addresses = new string[courier.noLocations];
		//for (int i = 0; i < courier.noLocations; i++) {
		//	this->addresses[i] = courier.addresses[i];
		//}
		//this->noLocations = courier.noLocations;
		this->phone = courier.phone;
		this->hasAnElectricVan = courier.hasAnElectricVan;
	}

	//overload = operator
	void operator=(const Courier& c) {

		if (this == &c) {
			return;
		}

		this->phone = c.phone;
		this->hasAnElectricVan = c.hasAnElectricVan;

		delete[] this->addresses;

		this->addresses = new string[c.noLocations];
		for (int i = 0; i < c.noLocations; i++) {
			this->addresses[i] = c.addresses[i];
		}
		this->noLocations = c.noLocations;
	}

	void processCourier() {
		Courier temp;
		//do something with temp
	}
};

int Courier::PHONE_SIZE = 10;
int Courier::ADDRESS_MIN_SIZE = 5;
int Courier::NO_LOCATIONS_IN_BUCHAREST = 0;

int main() {
	Courier c1("1234567890");
	c1.usesAnElectricVan();
	c1.addAddress("Calea Dorobanti, Bucharest");
	c1.addAddress("Str Poetilor, Voluntari");

	c1.print();

	Courier c2 = c1;
	c2.print();

	Courier c3("1234566666");
	c3.print();

	c3 = c1;
	c3.print();

	cout << endl << "No of locations in Bucharest: " <<
		Courier::NO_LOCATIONS_IN_BUCHAREST;
	//Courier c2;
}