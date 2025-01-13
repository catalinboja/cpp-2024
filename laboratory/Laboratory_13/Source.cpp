#include <iostream>
#include <string>
using namespace std;

class Product {
protected:
	string name;
	float price;

public:
	Product(string name, float price) : name(name), price(price) {

	}

	float getPrice() {
		return this->price;
	}

	virtual void printInfo() {
		cout << endl << "Name: " << this->name;
		cout << endl << "Price: " << this->price;

	}
};

class StockProduct : public Product {
protected:
	int stockItems;
public:
	StockProduct():Product("",0) {

	}

	StockProduct(string name, float price, int noItems)
		: Product(name, price), stockItems(noItems) {
	}

};

class Toy : public StockProduct {
protected:
	int minAge;
public:
	Toy(string name, float price, int noItems, int minAge)
		: StockProduct(name, price, noItems) {
		this->minAge = minAge;
	}

	//override the Product printInfo
	void printInfo() {
		this->Product::printInfo();
		cout << endl << "Stock items: " << this->stockItems;
		cout << endl << "Min age: " << this->minAge;
	}
};

class ITProduct : public StockProduct {
protected:
	int warrantyInMonths;
public:
	ITProduct(string name, float price): StockProduct(name, price,0) {

	}

	ITProduct(string name, float price, int warranty) {
		this->name = name;
		this->price = price;
		this->stockItems = 0;
		this->warrantyInMonths = warranty;
	}
};

int main() {
	Product product("Laptop", 2300);
	product.printInfo();

	StockProduct stockProduct;
	StockProduct laptopStockProduct("Laptop", 2300, 10);

	Toy rcCar("RC Car", 150, 100, 5);
	ITProduct desktopPC("Gaming PC", 9000, 36);

	//an array that ca store everything
	Product* products[5];
	products[0] = &laptopStockProduct;
	products[1] = &rcCar;
	products[2] = &desktopPC;
	products[3] = new Toy("Doll", 25, 1000, 3);

	ITProduct* pLaptop = new ITProduct("Dell Laptop", 2400);
	products[4] = pLaptop;

	for (int i = 0; i < 5; i++) {
		products[i]->printInfo();
	}

}