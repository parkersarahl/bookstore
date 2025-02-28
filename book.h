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
    public:
        Book(string title, string author, double price, int stock);
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
    };