#include "library.h"

Library::Library() {
	bookFile = "No File Loaded";
	bookFile = " ";
	borrowerFile = " ";
	bookPos = 0;
	clientPos = 0;
};

Library::Library(string fileIN,string secondFileIn) {
	bookFile = fileIN;
	borrowerFile = secondFileIn;
	bookPos = 0;
	clientPos = 0;
}
void Library::loadBooks() {
	fstream bookList;
	string readTitle, authorfName, authorLname, subject,
		callNum, getfloor, publisher, publishedDate,
		getCost, dueDate, pubAddress, status,idStringIN;
	Publisher readPub;
	Author    readPers;
	int floor, cost, callNumIn, statusIN,idNumIN;


	bookList.open(bookFile);

	if (!bookList) {
		cout << "Unable to load Books. \nFile not found.\n";
		system("pause");
		exit(0); //clsoe program if no file found
	}

	getline(bookList, readTitle);//clears column name
	//fill vector with books
	while (!bookList.eof()) {
		
		getline(bookList, readTitle, ',');
		getline(bookList, authorfName, ',');
		getline(bookList, authorLname, ',');
		getline(bookList, subject, ',');
		getline(bookList, getfloor, ',');
		floor = stoi(getfloor);
		getline(bookList, publisher, ',');
		getline(bookList, pubAddress, ',');
		getline(bookList, callNum, ',');
		callNumIn = stoi(callNum);
		getline(bookList, status, ',');
		getline(bookList, publishedDate, ',');
		statusIN = stoi(status);
		getline(bookList, getCost, ',');
		cost = stoi(getCost);
		getline(bookList, dueDate, ',');
		getline(bookList, idStringIN, '\n');
		idNumIN = stoi(idStringIN);

		if (readTitle.empty())
		{
			break; // ends sequence when end of file is reached
		}

		readPers.setFirstName(authorfName);
		readPers.setLastName(authorLname);
		readPub.setPubName(publisher);
		readPub.setAddress(pubAddress);

		books.push_back(Book(readTitle, subject, publishedDate, dueDate, readPers,
			readPub, callNumIn, statusIN, floor, cost,idNumIN));

	}
	bookList.close();


}
void Library::loadBorrowers() {
	fstream userList;
	string fName, lName, address, phoneNum, idNumIn;
	int idNum;

	userList.open(borrowerFile);

	if (!userList) {
		cout << "Unable to load Books. \nFile not found.\n";
		system("pause");
		exit(0); //clsoe program if no file found
	}

	while (!userList.eof()) {
		getline(userList, fName, ',');
		getline(userList, lName, ',');
		getline(userList, address, ',');
		getline(userList, phoneNum, ',');
		getline(userList, idNumIn, '\n');
		idNum = stoi(idNumIn);

		if (fName.empty())
		{
			break; // ends sequence when end of file is reached
		}

		clients.push_back(Borrower(fName, lName, address, phoneNum, idNum));

	}
	userList.close();


}
void Library::displayAllBooks() {
	for (vector<Book>::iterator iter = books.begin(); iter != books.end(); ++iter) {
		iter->print();
		cout << endl;
	}
}
void Library::displayClients() {
	for (vector<Borrower>::iterator iter = clients.begin(); iter != clients.end(); ++iter) {
		iter->print();
		cout << endl;
	}
}
bool Library::searchBook(int callNumIN) {
//	int userChoice;

	bool found = false;
	bookPos = 0;
	for (vector<Book>::iterator iter = books.begin(); iter != books.end(); ++iter) {

		if (iter->getCallNumber() == callNumIN) {
			cout << endl;
			iter->print();
			found = true;
			return found;
			}
		bookPos++;

	}//end iterator
	cout << "Book Not Found\n";
	system("pause");
	system("CLS");
	return found;
}


void Library::displayBooksOnLoan() {
	for (vector<Book>::iterator iter = books.begin(); iter != books.end(); ++iter) {
		if (iter->getStatus() == 2) {
			iter->print();
			cout << endl;
		}
	}
}
//returns book back to library invintory
void Library::returnBook(int returnCallID) {
	
	if (searchBook(returnCallID)) {
		if (books[bookPos].getBorrowerID() == 0) {
			cout << "\nBook already in inventory.\n\n";
			system("pause");
			system("CLS");
		}
		else {
			books[bookPos].setStatus(1);
			books[bookPos].setBorrowerID(0);
			cout << "\nBook Successfully returned\n\n";
			system("pause");
			system("CLS");
		}
	}
	else { cout << "Book not found.\n\n"; }
}
//checks out book to client
void Library::checkOutBook(int returnCallID){
	int userSelection;
	if (searchBook(returnCallID)) {
		if (books[bookPos].getBorrowerID() != 0) {
			cout << "Book is Unavailable.\n";
			system("pause");
			system("CLS");
		}
		else {
			cout << "\nPlease Enter Borrower ID:\n";
			cin >> userSelection;
			if (searchClient(userSelection)) {
				books[bookPos].setBorrowerID(userSelection);
				books[bookPos].setStatus(2);
				cout << "Book Successfully checked out:\n\n";
				system("pause");
				system("CLS");
			}
			else {
				cout << "Client Not Found.\n\n";
				system("pause");
				system("CLS");
			}
			
		};
	}
}


//used to check if client exists when checking out book
bool Library::searchClient(int clientNum) {
	//	int userChoice;

	bool found = false;
	clientPos = 0;
	for (vector<Borrower>::iterator iter = clients.begin(); iter != clients.end(); ++iter) {

		if (iter->getIdNumber() == clientNum) {
			cout << endl;
			iter->print();
			found = true;
			return found;
		}
		clientPos++;

	}//end iterator
	return found;
}

void Library::saveBookData() {
	ofstream saveBooks;
	saveBooks.open("LibraryCSV.csv");
	saveBooks << "Title,";
	saveBooks << "F.Name,";
	saveBooks << "L.Name,";
	saveBooks << "Genre,";
	saveBooks << "Floor,";
	saveBooks << "Publisher,";
	saveBooks << "PubAddress,";
	saveBooks << "CallNum,";
	saveBooks << "Status,";
	saveBooks << "Publish Date,";
	saveBooks << "Cost,";
	saveBooks << "Return Date,";
	saveBooks << "Currnet Borrower\n"; // used to re-write first line of csv file.
	
	for (vector<Book>::iterator iter = books.begin(); iter != books.end(); ++iter) {
		saveBooks << iter->getTitle() << ",";
		saveBooks << iter->getAuthor().getFirstName() << ",";
		saveBooks << iter->getAuthor().getLastName() << ",";
		saveBooks << iter->getSubject() << ",";
		saveBooks << iter->getFloor() << ",";
		saveBooks << iter->getPublisher().getName() << ",";
		saveBooks << iter->getPublisher().getAddress() << ",";
		saveBooks << iter->getCallNumber() << ",";
		saveBooks << iter->getStatus() << ",";
		saveBooks << iter->getPublishingDate() << ",";
		saveBooks << iter->getCost()<< ",";
		saveBooks << iter->getDueDate() << ",";
		saveBooks << iter->getBorrowerID()<< "\n";
	}
}