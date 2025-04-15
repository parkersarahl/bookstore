#include "Catalog.h"
#include "Book.h"

// Node Constructor for Linked List
Node:: Node (Book*b) {
            book = new Book(*b, false); // Deep copy of the book object
            next = nullptr;
            prev = nullptr;
        }
    
    // Catalog class (Doubly Linked List for Book Management)
    Catalog::Catalog() : head(nullptr), tail(nullptr) {} // Constructor
    Catalog::~Catalog(){} // Destructor

    // Add book
    void Catalog:: addBook(Book* b) {
        Node* newNode = new Node(b);
        if(!head){
            head =tail =newNode;
        }
        else{
            // If the list is not empty, add the new node to the end of the list
            tail->next = newNode; // Link the new node to the end of the list
            newNode -> prev =tail; // Link the previous tail to the new node
            tail = newNode; // Update tail to new node
            }   
        }
    
        // Search book
        Book* Catalog::searchBook(const string& title) {
            Node* temp = this->head;
            while (temp) {
                if (temp->book->getTitle() == title)
                    return temp->book;
                temp = temp->next;
            }
            return nullptr;
        }
    
        // Display books
        void Catalog::displayBooks() const {
            Node* temp = head;
            while (temp) {
                temp->book->display();
                temp = temp->next;
            }
        }
    
        // Remove book
        void Catalog:: removeBook(const string& title) {
            Node* temp = head;
            while (temp) {
                if (temp->book->getTitle() == title) {
                    if (temp->prev) {
                        temp->prev->next = temp->next;
                    } else {
                        head = temp->next; // Update head if it's the first node
                    }
                    if (temp->next) {
                        temp->next->prev = temp->prev;
                    } else {
                        tail = temp->prev; // Update tail if it's the last node
                    }
                    delete temp->book; // Free the book memory
                    delete temp; // Free the node memory
                    return;
                }
                temp = temp->next;
            }
        }

        // Decrease stock
        void Catalog:: decreaseStock(const string& title) {
            Node* temp = head;
            while (temp) {
                if (temp->book->getTitle() == title) {
                    if (temp->book->getStock() > 0) {
                        temp->book->setStock(temp->book->getStock() - 1);
                        cout << "Stock updated. Remaining stock: " << temp->book->getStock() << endl;
                    } else {
                        cout << "Stock is already at 0. Cannot decrease further." << endl;
                    }
                    return;
                }
                temp = temp->next;
            }
            cout << "Book not found in catalog." << endl;
        }

        // Find the book with the lowest price
        Book* Catalog::findLowestPriceBook() const {
            Node* temp = head;
            if (!temp) return nullptr; // Return nullptr if the list is empty
            Book* lowestPriceBook = temp->book;
            while (temp) {
                if (temp->book->getPrice() < lowestPriceBook->getPrice()) {
                    lowestPriceBook = temp->book;
                }
                temp = temp->next;
            }
            return lowestPriceBook;
        }
    
    