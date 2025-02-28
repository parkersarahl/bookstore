#include <string>
#include "entity.h"
#include "book.h"
#include "date.h"

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