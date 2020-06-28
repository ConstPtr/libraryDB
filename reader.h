#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include "book.h"
#include "func.h"

class reader
{
    private:
        unsigned int _readerID;
        std::string _firstName;
        std::string _lastName;
        unsigned int _phone;   
    public:
        reader();
        reader(int ID, std::string fName, std::string lName, int phone);
        ~reader();
        bool operator<(const reader& read) const;
        bool operator==(const reader& read) const;
        void setReader();
        void setReader(int ID);
        void display() const;
        int getID() const;
        std::string getFirstName() const;
        std::string getLastName() const;
        int getPhone() const;
        reader getReader() const;
};