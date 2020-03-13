#pragma once
#include <string>
#include "person.h"
#include "publisher.h"
#include <iostream>
#include "author.h"
using namespace std;

class Book {
public:
	//constructors
	Book();
	Book(string,string,string,string,Author &, Publisher &, int,int,int,int,int);
	Book(const Book &);
	
	//displays string value status. status is stored as int
	string displayStatus(); // used to output current status of book
	

	void print();
	//getters
	string getTitle() const;
	string getSubject() const;
	string getPublishingDate()const;
	string getDueDate()const;

	int getCallNumber() const;
	int getStatus() const;
	int getFloor() const;
	int getCost() const;
	int getBorrowerID() const;

	//setters
	void setTitle(string);
	void setSubject(string);
	void setPublishingDate(string);
	void setDueDate(string);

	void setCallNumber(int);
	void setStatus(int);
	void setFloor(int);
	void setCost(int);
	void setBorrowerID(int);

	Author getAuthor() const;
	Publisher getPublisher() const;


private:
	string title;   //the title of the book
	string subject; //a category/genre of book
	string publishingDate;//date the book was published
	string dueDate;
	
	Author author;  //firstname,lastname
	Publisher publisher; // publishers name, address
	
	int status;
	int callNumber; // a unique 9 digit number assigned the each book, different copies of the book will have different call numbers
	int floor;
	int cost;
	int borrowerID;

	
};