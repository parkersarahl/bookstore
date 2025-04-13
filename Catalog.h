#include "Book.h"

// Node for Linked List
class Node {
    public:
        Book* book;
        Node* next;
        Node* prev; // Pointer to the previous node in the list
        Node(Book* b); // Constructor
    };
    
    // Catalog class (Doubly Linked List for Book Management)
    class Catalog {
    private:
        Node* head;
        Node* tail;
    public:
        Catalog(); // Constructor
        ~Catalog(); // Destructor
    
        // Add book
        void addBook(Book* b);
    
        // Search book
        Book* searchBook(const string& title);
    
        // Display books
        void displayBooks() const;
    
        // Remove book
        void removeBook(const string& title);
        
       
        // Decrease stock
        void decreaseStock(const string& title);

        //Find the book with the lowest price
        Book* findLowestPriceBook() const;

    };
    
    