#pragma once
#include "person.h"


//inherits from person
class Author : public Person {
public:

	Author();
	Author(string, string);
	Author(string, string, string, int);
	virtual void print();

	void setNumBooks(int);
	void setPenName(string);

private:
	string penName;//can be used if author has a penName
	int numBooks;
};
