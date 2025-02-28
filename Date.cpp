#include "Date.h"
#include <iostream>

using namespace std;
Date:: Date(int day, int month, int year){
    this->day = day;
    this->month = month;    
    this->year = year;
}
// Destructor
Date:: ~Date(){}

void Date:: display()const {
    cout << "Date: " << day << "/" << month << "/" << year << endl;
}
