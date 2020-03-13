//CSC 330 Project 1


/*Readme:Welcome to version one of library management system.
 User is currently able to check status of books, return books, check out books
 and search for books. Data is currently loaded and saved to a CSV file that is packaged with the program
 Any status changes made to the book will save in the CSV file when program is saved and reloaded.
 */




#include <iostream>
#include "book.h"
#include "borrower.h" 
#include <string>
#include <fstream>
#include "library.h"
int displayMenu() ;
using namespace std;
//use a map for book/person loaner.
int main()
{   
	string userInput;
	int userChoice = 0;
	int userSelection;
	Library libraryOne("LibraryCSV.csv","Clients.csv");
	libraryOne.loadBooks(); // used to load books
	libraryOne.loadBorrowers();//used to load clients/borrowers
	


	//Begin user interaction here

	
	do {

		if (userChoice == 1) {
			cout << "View all Books: 1\n";
			cout << "View books on loan: 2\n";
			do {
				cin >> userSelection;
				if (!userSelection)
				{
					// user didn't input a number
					cin.clear(); // reset failbit
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
					// next, request user reinput
					cout << "Invalid Input\n";
				}
			} while (!userSelection);
			if (userSelection == 1)
				libraryOne.displayAllBooks();
			else if (userSelection == 2)
				libraryOne.displayBooksOnLoan();
		}

		if (userChoice == 2) {
			libraryOne.displayClients();
		}


		if (userChoice == 3) {
			cout << "Please Enter Call Number" << endl;
			do {
				cin >> userSelection;
				if (!userSelection)
				{
					// user didn't input a number
					cin.clear(); // reset failbit
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
					// next, request user reinput
					cout << "Invalid Input\n";
				}
			} while (!userSelection);
		
			if (!libraryOne.searchBook(userChoice)) {
				cout << "Book Not Found.\n";
				system("pause");
				system("CLS");
			}

		}


		if (userChoice == 4) {
			cout << "Please Entere CallID to return.\n";
			cin >> userSelection;
			do{
			if (!userSelection)
			{
				// user didn't input a number
				cin.clear(); // reset failbit
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
				// next, request user reinput
				cout << "Invalid Input\n";
			}
		} while (!userSelection);
			libraryOne.returnBook(userSelection);
		}

		if (userChoice == 5) {
			cout << "Please enter book call Number: \n";
			do {
				cin >> userSelection;
				if (!userSelection)
				{
					// user didn't input a number
					cin.clear(); // reset failbit
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
					// next, request user reinput
					cout << "Invalid Input\n";
				}
			} while (!userSelection);
			libraryOne.checkOutBook(userSelection);
		}

		userChoice = displayMenu();

		system("CLS");

	} while (userChoice != 9);

	
	libraryOne.saveBookData(); //saves Data when exiting program. book information will be saved when reloading
	system("pause");

	return 0;
}
//displays choices for worker.
int displayMenu() { 
	int userChoice;
	cout << "----Library Managment System----" << endl << endl;
	cout << "Please Make A Selection." << endl;
	cout << "View Books: 1" << endl;
	cout << "View Clients: 2" << endl;
	cout << "Check Book Status: 3" << endl;
	cout << "Return Book: 4" << endl;
	cout << "Check out Book: 5" << endl;
	cout << "Exit Program: 9" << endl;
	cin >> userChoice;
	if(!userChoice)
	{
		// user didn't input a number
		cin.clear(); // reset failbit
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
		// next, request user reinput
	}
	
	return userChoice;
}