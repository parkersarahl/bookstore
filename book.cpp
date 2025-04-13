#include "Book.h"

using namespace std;

// Constructor implementation
Book::Book(string title, string author, double price, int stock) {
    this->title = title;
    this->author = author;
    this->price = price;
    this->stock = stock;
    bookCount++; // Increment book count when a new book is created
}
Book::Book(const Book& other) {
    // Copy constructor implementation
    this->title = other.title;
    this->author = other.author;
    this->price = other.price;
    this->stock = other.stock;
    bookCount++; // Increment book count for the copied book
}

// Destructor implementation (if needed)
Book::~Book() {
    bookCount--; // Decrement book count when a book is destroyed
    cout << "Book " << title << " destroyed." << endl;
}

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

// Static function to get Book count
int Book:: bookCount =0; // Initialize static member variable
int Book::getBookCount() {
    return bookCount;
} // Assuming bookCount is a static member variable in the Book class.