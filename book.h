#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "func.h"

class book
{
    private:
        unsigned int _bookID;
        std::string _title;
        std::string _author;
        unsigned int _year;
    public:
        book();
        book(int ID, std::string title, std::string author, int year);
        ~book();
        bool operator<(const book& bk) const;
        bool operator==(const book& bk) const;
        void setBook();
        void setBook(int ID);
        void showHolder();
        void display() const;
        int getID() const;
        std::string getTitle() const;
        std::string getAuthor() const;
        int getYear() const;
        book getBook() const;
};