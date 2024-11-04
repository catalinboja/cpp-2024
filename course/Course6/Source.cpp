//constructors
//constant and static attributes
//static methods
//memory leak
//dangling pointers
//destructor
//copy constructor
//this week extra meeting - Wednesday, 19:30
//team project meeting - Thursday, 19:30

#include <iostream>
#include <string>
#include <string.h>

class Product {
private:
	//define default values for your attributes
	char* name = nullptr;
	std::string description = "No description";
	float price = 0;

private:
	//default ctor
	Product() {
		std::cout << std::endl << "Default ctor";
	}

public:
	Product(const char* name) {
		this->setName(name);
	}

	Product(const char* name, 
		std::string desc, float price) {
		this->setName(name);
		this->setDesc(desc);
		this->price = price;
	}

	//destructor
	~Product() {
		//executed by default when an object is destroyed
		std::cout << std::endl << "Destructor";
		delete[] this->name;
	}

	//copy ctor
	//not finished
	Product(Product& product) {
		//this->name = product.name;

		this->price = product.price;
		this->setName(product.getName());
		this->setDesc(product.description);
	}


	
	//ctor with default values
	//Product(const char* name, 
	//	std::string description = "Something",
	//	float price = 100) {
	//	this->setName(name);
	//	this->setDesc(description);
	//	this->price = price;
	//}
	

	std::string getDescription() {
		return this->description;
	}
	void setDesc(std::string description) {
		if (description.empty() ||
			description.size() < 5) {
			throw "Invalid description";
		}
		this->description = description;
	}
	char* getName() {
		//don't
		//return this->name;
		char* copy = new char[strlen(this->name) + 1];
		strcpy_s(copy, strlen(this->name) + 1, this->name);
		return copy;
	}

	void setName(const char* newName) {
		if (newName == nullptr ||
			strlen(newName) < 3) {
			throw "Invalid name";
		}
		int maxSize = strlen(newName) + 1;
		this->name = new char[maxSize];
		strcpy_s(this->name, maxSize, newName);
	}

	void printInfo() {
		std::cout << std::endl << "*******************";
		
		if (this->name != nullptr) {
			std::cout << std::endl << "Name: " << this->name;
		}
		else {
			std::cout << std::endl << "No name";
		}
		std::cout << std::endl << "Description: " 
			<< this->description;
		std::cout << std::endl << "Price: " << this->price;
	}

	//don't
	void deleteMySpaceInHeap() {
		delete[] this->name;
	}
};

int main() {
	//Product p1;
	//p1.printInfo();
	//TO DO: DON'T FORGET to init values

	//testing ctors
	Product laptop("Laptop");
	laptop.printInfo();

	Product smartphone("Samsung", "8 GB RAM", 1500);
	smartphone.printInfo();

	//Product pc("PC-PC", "Desktop PC");
	//pc.printInfo();

	//for (;;) {
	//	Product* newProduct = new Product("test", "bla bla bla", 100);
	//	std::cout << std::endl << "Creating products...";
	//	//newProduct->deleteMySpaceInHeap();
	//	delete newProduct;
	//}

	int* values = new int[5];
	values[0] = 5;

	std::cout << std::endl
		<< "First value: " << values[0];

	delete[] values;
	//avoid the dangling pointer
	values = nullptr;

	//a dangling pointer without previous instruction
	if (values != nullptr) {
		values[0] = 5;

		std::cout << std::endl
			<< "First value: " << values[0];
	}

	Product copy = laptop;

}