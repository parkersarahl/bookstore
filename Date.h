#pragma once

// Date class
class Date {
    private:
        int day, month, year;
    public:
        Date(int d = 1, int m = 1, int y = 2000);
        void display() const;
    };


