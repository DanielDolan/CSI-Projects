#include "borrower.h"


Borrower::Borrower() :Person() {
	address = " ";
	phoneNumber = " ";
	idNumber = 0;
	
}


Borrower::Borrower(string fName, string lName,string addressIn, string numIn,int idIN ) 
	: Person(fName, lName) {
	address = addressIn;
	phoneNumber = numIn;
	idNumber = idIN;
}


string Borrower::getAddress() const {
	return  this->address;
}
 
string Borrower::getPhoneNum() const {
	return  this->phoneNumber;
}

int Borrower::getIdNumber() const {
	return  this->idNumber;
}

void Borrower::setAddress(string addressIn) {
	address = addressIn;
}

void Borrower::setPhoneNum(string phoneIn) {
	phoneNumber = phoneIn;
}

void Borrower::setIdNumber(int idNumIn) {
	idNumIn = idNumIn;
}

void Borrower::print() {
	cout<<"Client Name: ";
	Person::print();
	cout << "\nAddress: " << address << endl;
	cout << "Phone Number: " << phoneNumber << endl;
	cout << "User ID: " << idNumber << endl;
}