#include <iostream>
#include <string>

using namespace std;

class Box {
public:
	string address;
	float weight;
};

class Driver {
public:
	string name;
	int age;
};

 enum VanType {DIESEL, GASOLINE, ELECTRIC};

 //define exception classes to be used for validation
 class InvalidBoxWeightException {

 };

 class ExceedMaxWeightException {
	 string msg;
 public:
	 ExceedMaxWeightException(string ms) : msg(ms) {

	 }

	 string getMessage() {
		 return this->msg;
	 }
 };

 class MissingBucharestException : public exception {
 public:
	 MissingBucharestException() {

	 }

	 MissingBucharestException(string msg): exception(msg.c_str()) {
	 }
 };

 class DeliveryVan {
 public:
	 static float MAX_WEIGHT;

	 string licensePlates;
	 VanType type = VanType::GASOLINE;
	 Driver driver; // 1:1 has a relation
	 Box* boxes = nullptr; //1:M has a relation
	 int noBoxes = 0;

	 float getCurrentWeight() {
		 float sum = 0;
		 for (int i = 0; i < this->noBoxes; i++) {
			 sum += this->boxes[i].weight;
		 }
		 return sum;
	 }

	 void addBox(Box box) {  //uses copy ctor from Box
		 //validate the box
		 //check if the box has a positive weight
		 if (box.weight <= 0) {
			 throw InvalidBoxWeightException();
		 }

		 //check if the van exceeds maximum weight
		 if (this->getCurrentWeight() + box.weight
		 > DeliveryVan::MAX_WEIGHT)
		 {
			 throw new ExceedMaxWeightException(
				 "The van will exceed max weight");
		 }

		 //check if the address has Bucharest
		 if (box.address.find("Bucharest") == -1) {
			 throw MissingBucharestException(
				 "The adddress is missing Bucharest");
		 }

		 //add the box
		 Box* newList = new Box[this->noBoxes + 1]; //default ctor
		 for (int i = 0; i < this->noBoxes; i++) {
			 newList[i] = this->boxes[i]; //operator = from Box
		 }
		 newList[this->noBoxes] = box; //operator = from Box
		 this->noBoxes += 1;

		 delete[] this->boxes;
		 this->boxes = newList;
	 }

	 void printInfo() {
		 //display all the van info
		 //driver info, van info, all boxes
		 //print the current weight

		 //from @Alin

		 cout << "Van License Plates: " << this->licensePlates << endl;
		 string vanTypeNames[] = { "Diesel", "Gasoline", "Electric" };

		 cout << "Van Type: " << vanTypeNames[this->type] << endl;
		 cout << "Driver Name: " << this->driver.name << endl;
		 cout << "Driver Age: " << this->driver.age << endl;
		 cout << "Boxes in the van: " << endl;

		 for (int i = 0; i < this->noBoxes; i++) {
			 cout << "Box " << i + 1 << ": " << endl;
			 cout << "  Address: " << this->boxes[i].address << endl;
			 cout << "  Weight: " << this->boxes[i].weight << " kg" << endl;
		 }

		 cout << "Current Total Weight: " << this->getCurrentWeight() << " kg" << endl;
	 }

 };

 float DeliveryVan::MAX_WEIGHT = 10.0;

 int main() {
	 DeliveryVan van1;
	 van1.licensePlates = "B-01-FAN";
	 Driver driver;
	 driver.name = "John";
	 driver.age = 24;
	 van1.driver = driver; //operator = from Driver

	 Box box;
	 box.address = "Piata Romana, Bucharest";
	 box.weight = 5;

	 try {
		 van1.addBox(box);
	 }
	 catch (InvalidBoxWeightException ex) {
		 cout << endl << "Check the box weight. Is invalid";
	 }
	 catch (ExceedMaxWeightException* pEx) {
		 cout << endl << "Error: " << pEx->getMessage();
		 delete pEx;
	 }
	 catch (MissingBucharestException ex) {
		 cout << endl << "Address isue: " << ex.what();
	 }
	 catch (...) {
		 cout << endl << "Houston we have a problem";
	 }

	 van1.printInfo();
 }