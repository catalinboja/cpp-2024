
#include <iostream>
#include <string.h>

using namespace std;

class Product
{
	char name[100];
	float price;
	bool isOnSale;
public:
	char* getName() {
		char* copy = new char[strlen(this->name) + 1];
		strcpy_s(copy, strlen(this->name) + 1, this->name);
		return copy;
	}

	void setName(const char* name) {
		if (name == nullptr || strlen(name) < 2)
		{
			throw "Name missing or not ok";
		}
		//shallow copy
		//this->name = name;
		strcpy_s(this->name,99, name);
	}

	void setPrice(float price) {
		if (price <= 0) {
			throw "Wrong price";
		}
		this->price = price;
	}

	void setOnSale(){
		this->isOnSale = true;
	}

	void removeFromSale() {
		this->isOnSale = false;
	}

	//class constructor
	Product() {

	}

	Product(const char* name, float price) {
		this->setName(name);
		this->setPrice(price);
		this->isOnSale = false;
	}

	void printInfo() {
		cout << endl << "******************";
		cout << endl << "Name : " << this->name;
		cout << endl << "Price : " << this->price;
		if(this->isOnSale)
			cout << endl << "Is on sale";

	}
};

Product search(
	Product* products, 
	int noProducts, 
	const char* nameFilter) {

	for (int i = 0; i < noProducts; i++) {
		if (strcmp(products[i].getName(), nameFilter) == 0)
			return products[i];
	}

	return Product("No product", 1);
}

Product* search2(
	Product* products,
	int noProducts,
	const char* nameFilter) {

	for (int i = 0; i < noProducts; i++) {
		if (strcmp(products[i].getName(), nameFilter) == 0)
			return &products[i];
	}

	return nullptr;
}

int main() {
	Product p;
	Product laptop("Lenovo", 3500);
	p.setName("Phone");

	p.printInfo();
	laptop.printInfo();

	Product products[] = {
		laptop,
		Product("Asus", 3000),
		Product("HP",4000)
	};
	int noProducts = 3;

	//search for Lenovo
	char searchFilter[] = "HP";
	for (int i = 0; i < noProducts; i++) {
		if (strcmp(products[i].getName(), searchFilter) == 0)
		{
			cout << endl << "Found it. Index is " << i;
		}
	}

	//test search
	Product searchedProduct =
		search(products, 3, "asfasd");
	searchedProduct.printInfo();

	Product* pProduct =
		search2(products, noProducts, "HP");
	if(pProduct != nullptr)
		pProduct->printInfo();


	return 0;
}
