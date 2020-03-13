#pragma once
#include <string>
#include <iostream>
using namespace std;


class Person {
public:
	Person();
	Person(string, string);
	Person(const Person&);

	void setFirstName(string);
	void setLastName(string);
	
	string getFirstName() const;
	string getLastName() const;

	virtual void print();
private:
	string firstName;
	string lastName;
};