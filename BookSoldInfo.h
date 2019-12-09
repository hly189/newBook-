
/*
Author: Thanh Le, Vitor Miranda, Ritvik Mandyam

This is Book sold Header
*/

#pragma once
#include "Book.h"
#include "Date.h"

class BookSoldInfo : public Book {
private:
	Date dateSold;
	double saleTax, totalSalePrice;
	int quantitySale, quanityRemaining;
public:
	// Default constructor 
	BookSoldInfo();
	// Constructor which takes parameter
	BookSoldInfo(double saleTax, double totalSalePrice, int quantitySale, int quanityRemaining, int daySold
		, int monthSold, int yearSold);
	// Default Destructor
	~BookSoldInfo();

	// acessor
	//get book object 
	Book* getBookObject();
	// get Sale Tax 
	double getSaleTax();
	// get total Sale Price
	double getTotalSalePrice();
	// get quantity Sale 
	int getQuantitySale();
	// get quantity Remaining
	int getQuantityRemaining();
	// get date sold in string 
	string getDateSold();
	// set retail 
	void setRetail(double retail); 
	// get retail 
	double getRetail(); 
};
