#include "publisher.h"

Publisher::Publisher() {
	name = " ";
	address = " ";
}

Publisher::Publisher(string nameIn, string addressIn) {
	name = nameIn;
	address = addressIn;
}

Publisher::Publisher(const Publisher &pubIn) {
	this->name = pubIn.name;
	this->address = pubIn.address;
}


void Publisher::setPubName(string fIn) {
	name = fIn;
}

void Publisher::setAddress(string aIn) {
	address = aIn;
}

string Publisher::getName() const {
	return name;
}

string Publisher::getAddress() const {
	return address;
}

void Publisher::print() {
	cout << "Publisher Name: " << name << endl;
	cout << "Address: " << address << endl;
}