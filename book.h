#pragma once
#include "Entity.h"
#include <iostream>
#include <string>

using namespace std;

class Book : public Entity {
    private:
        string title;
        string author;
        double price;
        int stock;
        static int bookCount; 
    public:
        Book(string title, string author, double price, int stock, bool countAsNew = true);
        Book(const Book& other, bool countAsNew = true); // Copy constructor
        ~Book();
    
        // Accessors
        string getTitle();
        string getAuthor();
        double getPrice();
        int getStock();
    
        // Mutators
        void setPrice(double p);
        void setStock(int s);
    
        // Override display function
        void display() const;

        //Static function to get Book count
        static int getBookCount();
    };