/*
Author: Thanh Le, Vitor Miranda, Ritvik Mandyam

This is a details PseudoCode for all our side-classes, the three main modules and the main
*/
//Date Class - PseudoCode
/*

I. setDay(int d)

// Mutator for set day

// if day is less than 1 or greater than 31

// it will exit since it's invalid

II. setMonth(int m)

// Mutator for set month

// if month is less than 1 or greater than 12, it will exit

// since it's invalid

III. setYear(int d)

// Mutator for set year

// if year is less than 1900, then it's invalid because the store

// may not open at that time

IV. string Date::toString()

// Function to show day, month and year in format dd/mm/yyyy

// It will convert day, month and year to string and put in that

// format
*/
//Helpers Class -PseudoCode
/*


I. getDataFIleSize(std::string fileName)

// Function to get intended size of book for inventory by counting how many book in data file parameter: string fileName - data file name

// it will do the following

1. open file

2. loop through file, ignore empty line and counting book

3. close file and return counting

II. Book* Helpers::installDataToInventory(string fileName, int fileSize)

// Function to initiate data from data file for inventory parameter: string fileName - data file name, int fileSize - given size of inventory

// It will do the following

1. open file

2. loop through data file until the end

3. if line is empty, then ignore

4. clear the trailing space

5. declare arrayString[10] - represent each field in data file

6. Initiate book object with from index in arrayString

7. Add book object to bookObject array

III. string getConsoleLine()

// Function to get console line input from user

IV. correctingValidInput(int &userInput)

// Function to validate input and correct it - int version

// It will do the following

1. Ask input from the user

2. If input is string, it will let user know it's invalid and input again

3. Clear the error and take user to the end by using clear() and ignore()

4. Ask user to input again until there is valid input

V. correctingValidInput(double &userInput)

// Overload to validate input and correct it - double

// Logic is similar to above
*/
//BookSoldInfo Class - Pseudocode
/*
I. BookSoldInfo()

// Default Constructor to initialize variable in BookSoldInfo Class

II. BookSoldInfo(all parameters)

// Constructor which takes parameter and set variable in BookSoldInfo

// Class to variable in paramater
*/
//Cashier Module Pseudo-Code
/*
I.CashierModule

// Constructor which take InventoryDatabase reference as parameterm so it can update directly to Inventory whenever there is book(s) sold

II.~CashierModule

// Destructor which will remove array book sold after CashierMododule

// Object finishes running. In this way, it will remove the memory to prevent memory leak

III. getSoldBookArraySize

// Accessor which is return the size of book sold array

IV. calculateSaleTax

// Function to calculate the sale tax, return the total price that customer has to pay.

//This function takes 3 parameters: saleTax - sale tax at local city, retailPrice - Retail Price of the book, quantitySold - Quantity of the book(s) that the customer buy

// This function will do the following

1. take sale tax and divide by 100 since sale tax would be input as percentage

2. total Sale tax = retail price * sale tax

3. total sale price = (total sale tax + retail price) * total sale tax

4. return total sale price

V. cashierMenu

// Function to show main menu for cashier

// The cashier menu will include:

1. Cashier - calculate current sale

2. Cashier Report - show report of sale record

3. Exit - exit current Cashier Main Menu

// Ask customer to choose which option do they want.

// Get input and validate input by calling correctingValidInput(int selection) in Helpers namespace

1 - then it will call cashierFunction() for calculating total price and update inventory

2 - then it will call showCashierRecord() for it will show sale record.

VI. printSaleBookInfo

// it show the book info in human readable

VII.addSoldBookdToArray

// Function to add bookSoldInfo Object to bookSoldArray it will take the BookSoldInfo object as parameter and will do the following:

1. Declare new temp array with new size + 1

2. loop through the current book sold array and copy item from bookSoldArray to tempArray

3. add the current book sold object to the end of tempArray

4. update the book sold array size - size++

5. Free old memory by deleting current bookSoldArray

6. Update bookSoldArray by set bookSoldArray = tempArray

VIII. showField

// Function to show field for the item

IX. showField

// Overload function to show each item for the field based on

// the field in previous showField() function

X.showCustomeReceiptScreen

// Function to show customer receipt from the bookSoldArray. It has parameter:

// int startingPoint - the size of current bookSoldArray since new book object would be expanded to current bookSoldArray, double saleTax - sale tax of current sale

// This function will do the following:

1. It will start by asking how would the customer pay

2. Show the Field by calling showField()

3. Loop through bookSoldArray and it will start with the new record which is startingPoint is the first index

- Get bookSoldInfo Object

- Show information of bookSoldInfo Object by calling overload showField() function

- get the subtotal of each book by taking quantity Sale * retail price

- Adding totalSalePrice that customer will have to pay

4. Print the sub total, tax, total and payment method

XI. cashierFunction

// Main Cashier Function to calculate current sale and update inventory. It will do the following:

1. If no book in inventory, let customer know and exit

2. Get the current Inventory

3. Enter the current sale tax

4. Enter the ISBN number

5. Find book with ISBN by calling function findbook in Inventory Module

6. If no book found let customer know and return

7. print book sale information by calling printSaleBookInfo

8. Ask customer if it is the book that they are looking for. If not, it will start from beginning again

9. Show retail price, quantity remain in inventory and ask customer how many books do they want to buy.

10. If quantity sold is greater than quantity in hand, let customer know. Otherwise, processing to payment

11. Let user know amount due before tax + asking day, month, sold of the book. Usually current day

12. calculating total price of the book by calling calculateSaleTax function

13. Update inventory by subtracting quantity sold

14. Initialize book sold object by gathering all information above and add it to bookSoldArray by calling addSoldBookToArray()

15. Ask customer if the want to continue, if yes, then repeating step 5 - 18.

16. Show customer receipt with total price, sale tax and subtotal by calling function showCustomerReceiptScreen.

XII. showCashierRecord

Show Cashier Record. It will show sale record in bookSoldArray

1. Show Field of the sale record by calling showField()

2. if size of bookSoldArray is 0. Meaning that there is no book sold.

3. Loop through soldBookArray and show information of each bookSoldInfo object in that array since they contain sale information.
*/
//InventoryDatabase Module
/*
I. InventoryDatabase()

Default Constructor

II.InventoryDatabase(string invFile)

//Constructor with parameter, it takes the data file name as parameter. And, do the following:

1. get the total book count by calling getDataFileSize in Helpers namespace.

2. Initialize books array with size of max book

3. Install data file to Inventory by calling function installDataToInventory in Helpers Namespace

III. findBook(string isbn, int* index)

take string isbn as parameter

4. loop through books array object and look for that book

5. if no isbn, it will return null

6. otherwise, it will return book object

IV. lookUpBook()

// Function to look up book and print out information

1. Asking user to input isbn

2. Looking for book object by isbn by calling function findbook

3. If null, then there is no book, let user know

4. Print out book information.

VI. deleteBook()

// Function to delete book

1. Declare tempArray with max amount of book

2. Ask user to enter ISBN

3. Look for that book with ISBN by calling function findBook

4. If null, then could not find that book with given ISBN and let user know

5. Otherwise, look to entire array and delete that book by shifting index of current book object and assign it to temp array

6. Delete current book array and bookDelete object to free memory

7. Set temp array book to books object array

VII. addBook()

// Function to add new book to inventory

1. If current book in inventory less than maximum book, then continue. Otherwise, let user knows about it

2. Input ISBN. It will check to see if that book is existed in inventory. If yes, then adding to current. If no, then starting adding new one

3. Asking user about book information

4. Adding it to the end of books array and delete book object to free memory

VIII. editBook()

// Function to edit information of the book based on the given ISBN

1. Ask user to input ISBN

2. Look for that book based on given ISBN

3. If no book found, let user know

4. Otherwise, it will ask user to see which information that user would like to edit (For example: Title, Author, etc)

5. Based on the selection, it will show the current information and set new value for that information

IX. mainMenu()

// Function to show main menu for inventory database. It will include the following:

1. Look up books

2. Add books

3. Delete books

4. Edit books

5. Exit
*/
//ReportDatabase Module
/*
1.ReportModule()
Defult constructor to set values

2. ReportModule(InventoryDatabase&)
 constructor to set the inventory

3. ReportMainMenu(InventoryDatabase&)
Menu for report module
contains different options to all report types

4.ReportInventoryList(InventoryDatabase&)

make report about all items on inventoryList

5.ReportWholeSaleValue(InventoryDatabase&)
Make report aboout whole sale value

6.ReportListByQuantity(InventoryDatabase&(

generate a list by quantity of the inventory

7.ReportListByCost(InventoryDatabase&)
Generate a list ordered by whole sale cost

8.ReportListByAge(InventoryDatabase&)
Generate a list about the oldest to youngest book on inventory

*/

#include "InventoryDatabase.h"// including headers
#include "CashierModule.h"
#include "Helpers.h"
#include "ReportModule.h"
using namespace std;

void mainMenu();

int main() {
	mainMenu();
	system("pause");
	return 0;
}

void mainMenu() {
	InventoryDatabase db = InventoryDatabase("inv.txt"); //Creating database with intentory.txt
	CashierModule cashier = CashierModule(db); // pushing inventory
	ReportModule Report = ReportModule(db); // pushing inventory

	int selection;

	do {
		cout << "================== Welcome to Serendipity Bookstore!" << endl;
		cout << "================== 1. Make sale" << endl;
		cout << "================== 2. Check inventory" << endl;
		cout << "================== 3. Create reports" << endl;
		cout << "================== 4. Exit" << endl;



		cout << "What would you like to do? (enter a choice between 1 and 4): ";
		Helpers::correctingValidInput(selection);
		switch (selection) {
		case 1:
			cashier.cashierMenu(); // Calling main function to sale menu
			system("cls");
			break;
		case 2:
			db.mainMenu(); // Calling Data Base function to dp menu
			system("cls");
			break;
		case 3:

			Report.ReportMainMenu(db); // Calling report menu

			break;

		}


	} while (selection != 4);  //loop validation
}

