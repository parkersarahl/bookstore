#include <iostream>
#include <string>
#include <vector>
#include "Entity.cpp"
#include "Book.cpp"
#include "Transaction.cpp"
#include "Date.cpp"

using namespace std;


// Node for Linked List
class Node {
public:
    Book* book;
    Node* next;
    Node(Book* b) : book(b), next(nullptr) {}
};

// Catalog class (Linked List for Book Management)
class Catalog {
private:
    Node* head;
public:
    Catalog() : head(nullptr) {}

    // Add book
    void addBook(Book* b) {
        Node* newNode = new Node(b);
        newNode->next = head;
        head = newNode;
    }

    // Search book
    Book* searchBook(const string& title) {
        Node* temp = head;
        while (temp) {
            if (temp->book->getTitle() == title)
                return temp->book;
            temp = temp->next;
        }
        return nullptr;
    }

    // Display books
    void displayBooks() const {
        Node* temp = head;
        while (temp) {
            temp->book->display();
            temp = temp->next;
        }
    }
};



// Main User Interface
int main() {
    Catalog catalog;

    // Adding books
    Book* book1 = new Book("C++ Primer", "Lippman", 45.99, 10);
    Book* book2 = new Book("Effective C++", "Scott Meyers", 39.99, 5);
    
    catalog.addBook(book1);
    catalog.addBook(book2);

    cout << "Bookstore Catalog:\n";
    catalog.displayBooks();

    // Searching for a book
    string searchTitle = "Effective C++";
    Book* foundBook = catalog.searchBook(searchTitle);
    if (foundBook) {
        cout << "\nBook Found: ";
        foundBook->display();
    } else {
        cout << "\nBook Not Found.\n";
    }

    // Processing a transaction
    Transaction sale("Sale", book1, Date(27, 2, 2025));
    cout << "\nTransaction Details:\n";
    sale.display();

    return 0;
}
