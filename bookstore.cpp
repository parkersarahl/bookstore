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
    //User interface
    bool finished = false;
    while(!finished){
        cout << "\nSelect: (0)Output (1)Search for a book (2)Process a transaction (3) Add a book  (4)Exit: " << endl; // User interface for input
        int choice;
        cin >> choice; // Get user input for choice
        switch (choice){
            case 0: // Output all books in the catalog
                cout << "\nBookstore Catalog:\n";
                catalog.displayBooks();
                break;
            case 1: { // Search for a book by title 
                cout << "Enter the title of the book to search: ";
                string searchTitle;
                cin.ignore(); // Clear the input buffer
                getline(cin, searchTitle); // Read the entire line for the title
                Book* foundBook = catalog.searchBook(searchTitle);
                if (foundBook) {
                    cout << "\nBook Found: ";
                    foundBook->display();
                } else {
                    cout << "\nBook Not Found.\n";
                }
                break;
            }
            case 2: { // Process a transaction
                cout << "Processing a transaction...\n";
                cout << "Enter the title of the book for the transaction: ";
                string transactionTitle;
                cin.ignore(); // Clear the input buffer
                getline(cin, transactionTitle); // Read the entire line for the title
                Book* foundBook = catalog.searchBook(transactionTitle);
                if (foundBook) {
                    Date date(27, 2, 2025); // Example date for the transaction
                    Transaction sale("Sale", foundBook, date);
                    cout << "\nTransaction Details:\n";
                    sale.display();
                } else {
                    cout << "\nBook Not Found for transaction.\n";
                }
                break;
            }
            case 3: { // Add a new book to the catalog
                string title, author;
                double price;
                int quantity;
                cout << "Enter book title: ";
                cin.ignore(); // Clear the input buffer
                getline(cin, title);
                cout << "Enter author name: ";
                getline(cin, author);
                cout << "Enter price: ";
                cin >> price;
                cout << "Enter quantity: ";
                cin >> quantity;
                Book* newBook = new Book(title, author, price, quantity);
                catalog.addBook(newBook);
                cout << "\nBook added successfully.\n";
                break;
            }
            case 4: { // Exit the program
                finished = true;
                cout << "Exiting the program.\n";
                break;
            }
            default: { // Handle invalid input
                cout << "Invalid choice. Please select again.\n";
                break;
            }
        }
    }

    return 0;
}
