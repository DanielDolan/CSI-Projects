#pragma once

#include <iostream>
#include "book.h"
#include "borrower.h" 
#include <string>
#include <fstream>


class Library {
public:
	Library();
	Library(string,string);
	void loadBooks();//pass function name of library file
	void loadBorrowers();
	void displayAllBooks();
	void displayBooksOnLoan();
	void displayClients();
	bool searchBook(int);//returns true if book is found
	void returnBook(int); //pass in call ID to return book to library
	void checkOutBook(int);
	bool searchClient(int);//returns true if client exists
	void saveBookData(); //saves data back to file via CSV format




	private:
		vector<Book>  books; // vector to store books in.
		vector<Borrower> clients;
		string bookFile;
		string borrowerFile;
		int bookPos; //used to track book pos during search
		int clientPos;

};