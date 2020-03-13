#pragma once
#include "person.h"
#include <vector>
#include "book.h"


//inherits from person
class Borrower :public Person {
public:	
	Borrower();
	Borrower(string,string,string,string,int);

	string getAddress() const;
	string getPhoneNum() const;
	int getIdNumber() const;

	void setAddress(string);
	void setPhoneNum(string);
	void setIdNumber(int);
	void print();




private:
	string address;
	string phoneNumber;
	int idNumber;
	int fees; 

};