#include "book.h"

//default constructor
Book::Book() {
	title = " ";
	subject = " ";
	callNumber = 0;
	dueDate = " ";
	publishingDate = " ";
	status = 0;
	cost = 0;
	floor = 0;
	borrowerID = 0;

}

//general constructror
Book::Book(string titleIn, string subjectIn,string publishDateIn,string dueDateIn,
	Author & authIn,Publisher & pubIn, int callNumIn,int statusIn, int floorIn,int costIN,int borrowerIN ) {
	
	//strings
	title = titleIn;
	subject = subjectIn;
	publishingDate = publishDateIn;
	dueDate = dueDateIn;

	//objects
	author = authIn;
	publisher = pubIn;


	//ints
	callNumber = callNumIn;
	status = statusIn;
	floor = floorIn;
	borrowerID = borrowerIN;
	cost = costIN;
 }

//copy constructor
Book::Book(const Book & bookIN) {
	this->title = bookIN.title;
	this->subject = bookIN.subject;
	this->publishingDate = bookIN.publishingDate;
	this->dueDate = bookIN.dueDate;

	this->author = bookIN.author;
	this ->publisher = bookIN.publisher;

	this->status = bookIN.status;
	this->callNumber = bookIN.callNumber;
	this->floor = bookIN.floor;
	this->cost = bookIN.cost;
	this->borrowerID = bookIN.borrowerID;
}

//display book
void Book::print() {
	cout << "Title: " << title<<endl;
	author.print();
	cout << endl;
	publisher.print();
	cout << "Book Status:" << displayStatus() << endl;
	cout << "Book Location :Floor " << floor << endl;
	cout << "Call Number: " << callNumber << endl;
	cout << "Borrower ID:" << borrowerID << endl;

}



string Book::getTitle() const {
	return title;
}

string Book::getSubject() const {
	return subject;
}

string Book::getPublishingDate() const {
	return publishingDate;
}

string Book::getDueDate() const {
	return dueDate;
}

int Book::getCallNumber() const {
	return callNumber;
}

int Book::getStatus() const {
	return status;
}

int Book::getFloor() const {
	return floor;
}

int Book::getCost() const {
	return cost;
}

int Book::getBorrowerID() const  {
	return borrowerID;
}


Author Book::getAuthor() const {
	return this->author;
}

Publisher Book::getPublisher() const {
	return this->publisher;
}
string Book::displayStatus() {
	string bookStatus;

	if (this->status == 1) {
		bookStatus = "In Library";
	}	
	if (this->status == 2) {
		bookStatus = "On Loan";
	}
	if (this->status == 3) {
		bookStatus = "In Reapir";
	}
	if (this->status == 4) {
		bookStatus = "Unavailable";
	}
	
	return bookStatus;
}

void Book:: setTitle(string stringIN) {
	title = stringIN;
}

void Book::setDueDate(string stringIN) {
	dueDate = stringIN;
}

void Book::setPublishingDate(string stringIN) {
	publishingDate = stringIN;
}

void Book::setSubject(string stringIN) {
	subject = stringIN;
}

void Book::setCallNumber(int numIN) {
	callNumber = numIN;
}

void Book::setStatus(int numIN) {
	status= numIN;
}

void Book::setFloor(int numIN) {
	floor = numIN;
}

void Book::setCost(int numIN) {
	cost = numIN;
}
void Book::setBorrowerID(int numIN) {
	borrowerID = numIN;
}
