/*
Author: Thanh Le, Vitor Miranda, Ritvik Mandyam

This is the Functions from Inventory Database Class
*/


#include "InventoryDatabase.h"
#include "Helpers.h"


// Default constructor
InventoryDatabase::InventoryDatabase() {};

// Constructor with parameter 
InventoryDatabase::InventoryDatabase(string invFile) {
	this->invFilePath = invFile;
	this->bookCount = Helpers::getDataFIleSize(invFile);
	this->books = new Book[this->maxBooks];
	this->books = Helpers::installDataToInventory(invFile, this->maxBooks);
}

// Accessor
// return array books object
Book* InventoryDatabase::getBooksDatabase() {
	return this->books;
}

// Get book in inventory
int InventoryDatabase::getBookCount() {
	return this->bookCount;
}

//Function
// Find book object 
Book* InventoryDatabase::findBook(string isbn, int* index) {
	for (int i = 0; i < this->bookCount; i++) {
		if (this->books[i].getIsbn() == isbn) {
			if (index != nullptr) *index = i;
			return &(this->books[i]);
		}
	}
	if (index != nullptr) *index = -1;
	return nullptr;
}

// Function to look up book 
void InventoryDatabase::lookUpBook() {
	std::cout << "------------------------------------------------------------" << std::endl;
	std::cout << "Looking up a book" << std::endl;
	std::cout << "------------------------------------------------------------" << std::endl;
	string isbn;
	std::cout << "Enter the ISBN to search for: ";
	cin >> isbn;
	Book* book = findBook(isbn);
	if (book != nullptr) {
		std::cout << "------------------------------------------------------------" << std::endl;
		std::cout << "Found book" << std::endl;
		std::cout << "------------------------------------------------------------" << std::endl;
		std::cout << book->bookDataAsHumanReadableString();
		std::cout << "========================================================================================================================" << std::endl;
	}
	else {
		cout << "------------------------------------------------------------" << std::endl;
		cout << "Could not find a book with the specified ISBN in the database." << std::endl;
		cout << "========================================================================================================================" << std::endl;
	}
}

// Function to delete Book 
void InventoryDatabase::deleteBook() {
	Book* newBooks = new Book[this->maxBooks];
	string isbn;
	std::cout << "------------------------------------------------------------" << std::endl;
	std::cout << "Deleting a book" << endl;
	std::cout << "------------------------------------------------------------" << std::endl;
	std::cout << "Enter the ISBN of the book to delete: ";
	std::cin >> isbn;
	int deleteIndex;
	Book* bookToDelete = findBook(isbn, &deleteIndex);
	if (bookToDelete != nullptr) {
		for (int i = 0; i < this->bookCount; i++) {
			if (i < deleteIndex) {
				newBooks[i] = this->books[i];
			}
			else if (i > deleteIndex) {
				newBooks[i - 1] = this->books[i];
			}
		}
		delete[] this->books;
		this->books = newBooks;
		this->bookCount--;
		this->saveBooksDatabase();
		std::cout << "------------------------------------------------------------" << std::endl;
		std::cout << "Deleted book with ISBN " << isbn << std::endl;
		std::cout << "========================================================================================================================" << std::endl;
	}
	else {
		std::cout << "------------------------------------------------------------" << std::endl;
		std::cout << "Could not find book with specified ISBN." << std::endl;
		std::cout << "========================================================================================================================" << std::endl;
	}
}

// Function to add book 
void InventoryDatabase::addBook() {
	std::cout << "------------------------------------------------------------" << std::endl;
	std::cout << "Adding a new book                                          " << std::endl;
	std::cout << "------------------------------------------------------------" << std::endl;
	if (this->bookCount < this->maxBooks) {
		Book* book = new Book;
		string isbn;
		Book* bookExists;

		std::cout << "ISBN: ";
		std::getline(std::cin, isbn);
		bookExists = findBook(isbn);
		if (bookExists == nullptr) {
			book->setIsbn(Helpers::getConsoleLine());
		}
		else {
			std::cout << "We already have this book in our inventory, adding another copy.";
			book->setQuantityOnHand(book->getQuantityOnHand() + 1);
			this->saveBooksDatabase();
			return;
		}

		std::cout << "Title: ";
		book->setTitle(Helpers::getConsoleLine());
		std::cout << "Author: ";
		book->setAuthor(Helpers::getConsoleLine());
		std::cout << "Publisher: ";
		book->setPublisher(Helpers::getConsoleLine());
		std::cout << "Quantity on hand: ";
		book->setQuantityOnHand(stoi(Helpers::getConsoleLine()));
		std::cout << "Wholesale cost: $";
		book->setWholesaleCost(stof(Helpers::getConsoleLine()));
		std::cout << "Retail price: $";
		book->setRetailPrice(stof(Helpers::getConsoleLine()));
		std::cout << "Day Add (dd): ";
		book->setDay(stoi(Helpers::getConsoleLine()));
		std::cout << "Month Add (mm): ";
		book->setMonth(stoi(Helpers::getConsoleLine()));
		std::cout << "Year Add (yyyy): ";
		book->setYear(stoi(Helpers::getConsoleLine()));
		books[this->bookCount++] = *book;
		this->saveBooksDatabase();
		delete book;
		std::cout << "========================================================================================================================"<< std::endl;
	}
	else {
		std::cout << "No more space in inventory database!";
		std::cout << "========================================================================================================================" << std::endl;
	}

}

// Function to edit book 
void InventoryDatabase::editBook() {
	string isbn;
	std::cout << "------------------------------------------------------------" << std::endl;
	std::cout << "Editing a book                                              " << std::endl;
	std::cout << "------------------------------------------------------------" << std::endl;
	std::cout << "Enter an ISBN to edit: ";
	std::cin >> isbn;
	Book* bookToEdit = findBook(isbn);
	if (bookToEdit != nullptr) {
		int selection = 0;
		while (selection != 7) {
			std::cout << "What would you like to change?" << std::endl;
			std::cout << "1. Title" << std::endl;
			std::cout << "2. Author" << std::endl;
			std::cout << "3. Publisher" << std::endl;
			std::cout << "4. Quantity on hand" << std::endl;
			std::cout << "5. Wholesale cost" << std::endl;
			std::cout << "6. Retail price" << std::endl;
			std::cout << "7. Exit" << std::endl;
			std::cin >> selection;
			string newValue;
			cin.ignore();
			switch (selection) {
			case 1:
				std::cout << "Current title: " << bookToEdit->getTitle() << std::endl;
				std::cout << "New title (leave empty for unchanged): ";
				newValue = Helpers::getConsoleLine();
				if (newValue != "") bookToEdit->setTitle(newValue);
				break;
				
			case 2:
				std::cout << "Current author: " << bookToEdit->getAuthor() << std::endl;
				std::cout << "New author (leave empty for unchanged): ";
				newValue = Helpers::getConsoleLine();
				if (newValue != "") bookToEdit->setAuthor(newValue);
				break;
				
			case 3:
				std::cout << "Current publisher: " << bookToEdit->getPublisher() << std::endl;
				std::cout << "New publisher (leave empty for unchanged): ";
				newValue = Helpers::getConsoleLine();
				if (newValue != "") bookToEdit->setPublisher(newValue);
				break;
				
			case 4:
				std::cout << "Current quantity on hand: " << bookToEdit->getQuantityOnHand() << std::endl;
				std::cout << "New quantity on hand (leave empty for unchanged): ";
				newValue = Helpers::getConsoleLine();
				if (newValue != "") bookToEdit->setQuantityOnHand(stoi(newValue));
				break;
			
			case 5:
				std::cout << "Current wholesale cost: $" << bookToEdit->getWholesaleCost() << std::endl;
				std::cout << "New wholesale cost (leave empty for unchanged): $";
				newValue = Helpers::getConsoleLine();
				if (newValue != "") bookToEdit->setWholesaleCost(stof(newValue));
				break;
				
			case 6:
				std::cout << "Current retail price: " << bookToEdit->getRetailPrice() << std::endl;
				std::cout << "New retail price (leave empty for unchanged): ";
				newValue = Helpers::getConsoleLine();
				if (newValue != "") bookToEdit->setRetailPrice(stof(newValue));
				break;
				
			}
			this->saveBooksDatabase();
		}
	}
	else {
		std::cout << "------------------------------------------------------------" << std::endl;
		std::cout << "Could not find a book with the specified ISBN.              " << std::endl;
		std::cout << "========================================================================================================================" << std::endl;
	}

}

// Main Menu 
void InventoryDatabase::mainMenu() {
	int selection = 0;
	while (selection != 5) {
		std::cout << "========================================================================================================================" << std::endl;
		std::cout << "Welcome to Serendipity Bookstore's inventory database!" << std::endl;
		std::cout << "We have " << this->bookCount << " book(s) available right now." << std::endl;
		std::cout << "------------------------------------------------------------" << std::endl;
		std::cout << "1: Look up books" << std::endl;
		std::cout << "2: Add books" << std::endl;
		std::cout << "3: Delete books" << std::endl;
		std::cout << "4: Edit books" << std::endl;
		std::cout << "5: Exit" << std::endl;
		std::cout << std::endl;
		std::cout << "What would you like to do? (enter an option between 1 and 5): ";
		Helpers::correctingValidInput(selection);
		switch (selection) {
		case 1: {
			lookUpBook();
			break;
		}
		case 2: {
			addBook();
			break;
		}
		case 3: {
			deleteBook();
			break;
		}
		case 4: {
			editBook();
			break;
		}
		default:

			std::cout << "Wrong Input" << std::endl;
			break;
		}
	}
}

void InventoryDatabase::saveBooksDatabase() {
	if (this->ostream.is_open()) {
		this->ostream.close();
	}

	this->ostream.open(this->invFilePath);

	if (this->ostream.is_open()) {
		for (int i = 0; i < this->bookCount; i++) {
			ostream << this->books[i].bookDataAsString() << endl;
		}
	}
	this->ostream.close();
}