#include "Book.h"

using namespace std;

// Constructor implementation
Book::Book(string title, string author, double price, int stock) {
    this->title = title;
    this->author = author;
    this->price = price;
    this->stock = stock;
}
// Destructor implementation (if needed)
Book::~Book() {}

//Accessors
string Book::getTitle() { 
    return title; 
}
string Book::getAuthor()  { 
    return author; 
}
double Book:: getPrice()  { 
    return price; 
}
int Book:: getStock() { 
    return stock; 
}

// Mutators

void Book:: setPrice(double p) { 
    price = p; 
}
void Book:: setStock(int s) { 
    stock = s; 
}

// Override display function
void Book:: display() const {
    cout << "Title: " << title << ", Author: " << author << ", Price: $" << price << ", Stock: " << stock << endl;
}