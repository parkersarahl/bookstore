#include "Transaction.h"
#include "Book.h"
#include "Date.h"
#include "Entity.h"
#include <iostream>
#include <string>

using namespace std;

//Constructor
Transaction::Transaction(string type, Book* book, Date date) {
    this->type = type;
    this->book = book;
    this->date = date;
}

//Destructor
Transaction::~Transaction(){}

//Display function
void Transaction::display() const {
    cout << "Transaction: " << type << ", Book: " << book->getTitle() << ", Date: ";
    date.display();
    cout << endl;
}