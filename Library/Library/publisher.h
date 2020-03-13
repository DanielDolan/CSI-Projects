#pragma once
#include <string>
#include <iostream>
using namespace std;


class Publisher {
public:
	Publisher();
	Publisher(string, string);
	Publisher(const Publisher &);

	void setPubName(string);
	void setAddress(string);

	string getName() const;
	string getAddress() const;

	void print();
private:
	string name;
	string address;
};