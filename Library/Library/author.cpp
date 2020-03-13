#include "author.h"



Author::Author() {
	penName = " ";
	numBooks = 0;
}

Author::Author(string fNameIn, string lNameIn) :Person(fNameIn, lNameIn) {

}

Author::Author(string fNameIn, string lNameIN, string penNameIN, int numBookIn):Person(fNameIn,lNameIN) {
	penName = penNameIN;
	numBooks = numBookIn;

}

void  Author::print() {
	cout << "Author: ";
	Person::print();
}

void Author::setNumBooks(int numIn) {
	numBooks = numIn;
}

void Author::setPenName(string nameIn) {
	penName = nameIn;
}

