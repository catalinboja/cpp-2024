#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class StringUtils {
public:
	static void serializeString(string value, ofstream& file) {
		//write the size of the string + \0
		int valueSize = value.size() + 1;
		file.write((char*)&valueSize, sizeof(int));
		//write the value + \0
		file.write(value.c_str(), valueSize * sizeof(char));
	}

	static string deserializeString(ifstream& file) {
		//read string size + \0
		int stringSize;
		file.read((char*)&stringSize, sizeof(int));
		//read string
		char buffer[1000];
		file.read(buffer, sizeof(char) * stringSize);
		return string(buffer);
	}
};

class Box {
	//char*
	//string*
	//int*

	int noItems = 0;
	string* items = nullptr;

	string address = "";
	float weight = 0;
	const int id;

public:
	static float MAX_WEIGHT;

	Box(int id, float weight, string address)
		: id(id), weight(weight), address(address) {
		//this->id = id;
	}

	Box(int id, float weight, string address, int noItems, string* newItems)
		:id(id), weight(weight), address(address), noItems(noItems)
	{
		this->items = new string[noItems];
		for (int i = 0; i < noItems; i++) {
			this->items[i] = newItems[i];
		}
	}

	Box() : id(0) {

	}

	~Box() {
		delete[] this->items;
	}

	Box(const Box& box)
		: id(box.id), weight(box.weight), address(box.address) {
		this->noItems = box.noItems;
		this->items = new string[this->noItems];
		for (int i = 0; i < this->noItems; i++) {
			this->items[i] = box.items[i];
		}
	}

	void operator=(const Box& box) {
		//this->id = box.id;
		if (this == &box) {
			return;
		}

		this->weight = box.weight;
		this->address = box.address;
		this->noItems = box.noItems;

		delete[] this->items;
		this->items = new string[this->noItems];
		for (int i = 0; i < this->noItems; i++) {
			this->items[i] = box.items[i];
		}
	}

	void writeIntoBinaryFile(ofstream& file) {
		//write id
		file.write((char*)&this->id, sizeof(int));
		//write the weight
		file.write((char*)&this->weight, sizeof(Box::weight));
		//write the address
		StringUtils::serializeString(this->address, file);
		//write the number of items
		file.write((char*)&this->noItems, sizeof(int));
		//write the items
		for (int i = 0; i < this->noItems; i++) {
			StringUtils::serializeString(this->items[i], file);
		}
	}

	friend void operator<<(ostream& console, const Box& other);
};

float Box::MAX_WEIGHT = 1.5;


//overload <<
void operator<<(ostream& console, const Box& other) {
	console << endl << "id: " << other.id;
	console << endl << "items: ";
	for (int i = 0; i < other.noItems; i++) {
		console << other.items[i] << " ";
	}
	console << endl << "address: " << other.address;
	console << endl << "weight: " << other.weight << endl;
}

int main() {

	Box emptyBox;
	Box box1(1, 0.5, "ASE");

	string items[] = { "keyboard", "mouse", "pc" };
	int noItems = 3;

	Box delivery(2, 1, "Home", noItems, items);

	Box temp = delivery;
	emptyBox = delivery;

	cout << delivery;
	cout << temp;
	cout << emptyBox;

	//writing into text files
	//ios::trunc for truncate mode
	ofstream deliveryList("delivery.txt", ios::app); //in append mode
	if (deliveryList.is_open()) {
		deliveryList << "\t Delivery list";
		deliveryList << delivery;
		deliveryList << temp;
	}
	deliveryList.close();

	//writing into binary files
	ofstream data("delivery.bin", ios::binary | ios::trunc);
	delivery.writeIntoBinaryFile(data);
	temp.writeIntoBinaryFile(data);

	data.close();
}