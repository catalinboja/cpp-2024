#include <iostream>
#include <string>
#include <fstream>

using namespace std;

enum Party {Republican, Democratic, Independent};

class ElectionCandidate {
private:
	Party party = Party::Independent;
	char* name = nullptr;
	int votes = 0;
	const string region;
	static int TOTAL_CANDIDATES;
	const static int NAME_MIN_SIZE;

public:
	void setName(const char* name) {
		if (strlen(name) < ElectionCandidate::NAME_MIN_SIZE) {
			throw exception("Invalid name");
		}

		if (this->name != nullptr) {
			delete[] this->name;
		}

		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
	}

	char* getName() {
		if (this->name == nullptr) {
			return nullptr;
		}
		char* copy = new char[strlen(name) + 1];
		strcpy_s(copy, strlen(name) + 1, name);
		return copy;
	}

	ElectionCandidate(
		const char* name, Party party, int votes, string region)
		:region(region), votes(votes), party(party) {
		this->setName(name);
		ElectionCandidate::TOTAL_CANDIDATES += 1;
	}

	~ElectionCandidate() {
		delete[] this->name;
		ElectionCandidate::TOTAL_CANDIDATES -= 1;
	}

	ElectionCandidate(const ElectionCandidate& candidate):
		region(candidate.region), 
		votes(candidate.votes), 
		party(candidate.party)
	{
		this->setName(candidate.name);
		ElectionCandidate::TOTAL_CANDIDATES += 1;
	}

	void operator=(const ElectionCandidate& candidate) {
		if (this == &candidate) {
			return;
		}
		this->setName(candidate.name);
		this->votes = candidate.votes;
		this->party = candidate.party;
	}

	static int getNoCandidates() {
		return ElectionCandidate::TOTAL_CANDIDATES;
	}

	ElectionCandidate operator++() {
		this->votes += 1;
		return *this;
	}

	bool operator==(ElectionCandidate& candidate) {
		if (this->party == candidate.party &&
			strcmp(this->name, candidate.name) == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	bool checkName(string value) {
		if (strcmp(this->name, value.c_str()) == 0) {
			return true;
		}
		else {
			return false;
		}

		////alternative
		//string name = string(this->name);
		//if (name == value) {
		//	return true;
		//}
		//else {
		//	return false;
		//}
	}

	float getPopularityIndex() {
		float weight = 0;
		switch (this->party)
		{
		case Party::Independent:
			weight = 1.5;
			break;
		case Party::Democratic:
			weight = 1.2;
			break;
		case Party::Republican:
			weight = 1;
			break;
		default:
			weight = 0;
		}
		return weight * this->votes;
	}

	friend void operator <<(ostream& console, ElectionCandidate& candidate);
};

void operator <<(ostream& console, ElectionCandidate& candidate) {
	console << endl << candidate.name << " | " << candidate.votes
		<< " | " << candidate.party << " | " << candidate.region;
}

int ElectionCandidate::TOTAL_CANDIDATES = 0;
const int ElectionCandidate::NAME_MIN_SIZE = 3;

int main() {
	ElectionCandidate john("john", Party::Republican, 2000, "Alabama");
	cout << endl << "Name: " << john.getName();
	john.setName("John Test");
	cout << endl << "Name: " << john.getName();

	ElectionCandidate *candidate = 
		new ElectionCandidate("john", Party::Republican, 2000, "Alabama");
	delete candidate;


	//another way to test destructor
	{
		ElectionCandidate temp("john", Party::Republican, 2000, "Alabama");
	}

	ElectionCandidate johnClone = john;
	cout << endl << johnClone.getName();

	ElectionCandidate temp("Bob", Party::Republican, 2000, "Alabama");
	temp = john;

	cout << endl << temp.getName();

	cout << endl << "Total canditates: "
		<< ElectionCandidate::getNoCandidates();

	cout << john;
	++john;
	cout << john;

	cout << temp;
	temp.setName("Bob");

	if (john == temp) {
		cout << endl << "The same";
	}
	else {
		cout << endl << "Different";
	}

	if (john.checkName("john")) {
		cout << endl << "Same name";
	}
	else {
		cout << endl << "Different name";
	}

	cout << endl << "Popularity: " << john.getPopularityIndex();

	ofstream file("Candidate.txt");
	if (file.is_open()) {
		file << john;
		file.close();
	}
	else {
		throw exception("File error");
	}
}