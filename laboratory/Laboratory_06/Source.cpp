#include <iostream>
#include <string>
#include <string.h>

using namespace std;

class Box {
private:
	float weight = 0;
	string address = "";
	float* taxes = nullptr; //paid taxes everytime we transfer to a different country
	int noCustomPasses = 0;
public:

	Box(string address) {
		this->setAddress(address);
	}

	Box(string address,float weight) {
		this->setAddress(address);
		this->setWeight(weight);
	}

	Box(string address, float weight,
		float* taxes, int noTaxes) {
		this->setWeight(weight);
		this->setAddress(address);
		this->setTaxes(taxes, noTaxes);
	}

	~Box() {
		//just clean HEAP
		delete[] this->taxes;
		//don't
		//this->taxes = nullptr;
		//this->noCustomPasses = 0;
	}

	//copy ctor
	Box(const Box& box) {
		//box.address = this->address;
		cout << endl << "Calling COPY CTOR";
		this->address = box.address;
		this->weight = box.weight;
		//shallow copy
		//this->taxes = box.taxes;
		this->setTaxes(box.taxes, box.noCustomPasses);
	}

	void setWeight(float weight) {
		if (weight <= 0) {
			throw "Wrong value";
		}
		this->weight = weight;
	}


	float* getTaxes() {
		float* copy = new float[noCustomPasses];
		for (int i = 0; i < noCustomPasses; i++) {
			copy[i] = taxes[i];
		}
		return copy;
	}
	int getNoTaxes() {
		return noCustomPasses;
	}

	void setTaxes(float* taxes, int noTaxes) {
		noCustomPasses = noTaxes;
		//shadowing
		//taxes = new float[noTaxes];

		//avoid the memory leak
		if(this->taxes != nullptr)
			delete[] this->taxes;

		this->taxes = new float[noTaxes];
		for (int i = 0; i < noTaxes; i++) {
			this->taxes[i] = taxes[i];
		}
	}

	void setAddress(string newAddress) {
		if (newAddress.empty()) {
			throw "Missing address";
		}
		this->address = newAddress;
	}

	void setAddress(const char* newAddress) {
		if (newAddress == nullptr) {
			throw "Missing address";
		}
		this->address = string(newAddress);
	}

	string getAddress() {
		return address;
	}

	const char* getAddressAsCharArray() {
		return address.c_str();
	}

	void print() {
		cout << endl << "--------------------";
		cout << endl << "Address: " << address;
		cout << endl << "Weight: " << weight;
		if (this->taxes != nullptr) {
			cout << endl << "Paid taxes: ";
			for (int i = 0; i < noCustomPasses; i++) {
				cout << " " << taxes[i];
			}
		}
	}
};

void doSomething(Box b) {

}

Box doBox() {
	Box b("test");
	return b;
}

int main() {
	Box b1("Calea Dorobanti 15");
	Box b2("Piata Victoriei", 1.56);

	float taxes[] = { 7,10 };
	Box b3("Piata Romana", 2.3, taxes, 2);

	b1.print();
	b2.print();
	b3.print();


	//create a copy of b3
	Box b3Copy = b3; //copy ctor

	b3Copy.print();

	doSomething(b1);
	Box t = doBox();


	//b1 = b3; //is =


	float* taxesCopy = b3.getTaxes();

	//avoid memory leak
	delete[] taxesCopy;
	taxesCopy = new float[10];
}