
//copy constructor
//constant and static attributes
//static methods
//overloading operators (=, <, >, >=, ==, +, -, *, +=, ++, --, !, cast, [])


#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class Product {
private:
	//define default values for your attributes
	char* name = nullptr;
	std::string description = "No description";
	float price = 0;
public:
	static int DESC_MIN_SIZE;
	static int NO_PRODUCTS;

private:
	//default ctor
	Product() {
		std::cout << std::endl << "Default ctor";
		Product::NO_PRODUCTS += 1;
	}

public:
	Product(const char* name) {
		this->setName(name);
		Product::NO_PRODUCTS += 1;
	}

	Product(const char* name,
		std::string desc, float price) {
		this->setName(name);
		this->setDesc(desc);
		this->price = price;
		Product::NO_PRODUCTS += 1;
	}

	//destructor
	~Product() {
		//executed by default when an object is destroyed
		std::cout << std::endl << "Destructor";
		delete[] this->name;
		//this->name = nullptr;
		Product::NO_PRODUCTS -= 1;
	}

	//copy ctor
	Product(const Product& product) {
		//this->name = product.name;

		//product.price = this->price;

		this->price = product.price;
		this->setName(product.getName());
		this->setDesc(product.description);

		Product::NO_PRODUCTS += 1;
	}


	std::string getDescription() {
		return this->description;
	}
	void setDesc(std::string description) {

		//int minSize = 5;

		if (description.empty() ||
			description.size() < DESC_MIN_SIZE) {
			throw "Invalid description";
		}
		this->description = description;
	}
	const char* getName() const{
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

		//avoid the memory leak
		delete[] this->name;

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

	//overload operator =
	void operator=(const Product& p) {
		//test for self equality
		if (this == &p) {
			return;
		}

		this->setName(p.getName());
		this->setDesc(p.description);
		this->price = p.price;
	}

	//don't
	void deleteMySpaceInHeap() {
		delete[] this->name;
	}
};

//init the static
int Product::DESC_MIN_SIZE = 3;
int Product::NO_PRODUCTS = 0;

void testDestructor() {
	Product p("Test");
}

//uses the copy constructor
void doSomething(Product p) {

}

//DON'T uses the copy constructor
void doSomething2(Product* p) {

}

//DON'T uses the copy constructor
void doSomething3(Product& p) {

}

//uses the copy constructor
Product createProduct() {
	Product t("test");
	return t;
}

int main() {
	Product laptop("Lenovo");
	laptop.setName("New Lenovo");

	//copy the laptop
	Product anotherLaptop = laptop;

	doSomething(laptop);

	laptop.printInfo();
	anotherLaptop.printInfo();

	//operator =
	anotherLaptop = laptop;
	laptop = laptop;
	//anotherLaptop.operator=(laptop)

	//test the destructor
	Product* p = new Product("Test");
	delete p;

	string newDescription = "";
	if (newDescription.size() >= Product::DESC_MIN_SIZE) {
		laptop.setDesc(newDescription);
	}

	testDestructor();

	{
		Product test("test");
		int vb = 10;
	}

	cout << endl << "------------------";


	cout << endl << "Total products in memory " << Product::NO_PRODUCTS;


}