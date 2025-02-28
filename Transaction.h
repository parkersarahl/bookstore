#include <string>
#include "Entity.h"
#include "Book.h"
#include "Date.h"

using namespace std;

class Transaction: public Entity {
    private:
        string type;
        Book* book;
        Date date;
    public:
        Transaction(string type, Book* book, Date date);
        ~Transaction();
    
        void display() const;
};