#include "person.h"


Person::Person() {
	firstName = " ";
	lastName = " ";
}

Person::Person(string fNameIn, string lNameIn) {
	firstName = fNameIn;
	lastName = lNameIn;
}

Person::Person(const Person& persIn) {
	this->firstName = persIn.firstName;
	this->lastName = persIn.lastName;
}

void Person::setFirstName(string fIn){
	firstName = fIn;
}

void Person::setLastName(string lIn) {
	lastName = lIn;
}

string Person::getFirstName() const {
	return firstName;
}

string Person::getLastName() const {
	return lastName;
}

void Person::print() {
	cout<< firstName << " " << lastName;
}