#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <algorithm>
#include <fstream>
#include "reader.h"
#include "book.h"

class library
{
    private:
        int lastBookId;
        int lastReaderId;
        std::set<book> _books;
        std::set<reader> _readers;
        std::map<int, std::set<int>> _holders;
        std::map<int, int> _bookAmount;
        std::set<book>::iterator _bookIt;
        std::set<reader>::iterator _readerIt;
        std::map<int, std::set<int>>::iterator _holdIt;
        std::map<int, int>::iterator _amountIt;
        std::set<int>::iterator _iter;
    public:
        library();
        ~library();

        bool findReader();
        void addReader();
        void updateReader();
        void deleteReader();
        void showReaders();
        void readerInfo();
        void giveBook();
        void returnBook();
        
        bool findBook();
        void addBook();  
        void updateBook();
        void bookInfo();
        void deleteBook();
        void showBooks(std::string key);
        void showHolder();
        
        void setItersBegin();
        book getBookForWrite();
        reader getReaderForWrite();
        std::pair<int, int> getAmountForWrite();
        std::pair<int, int> getHolderForWrite();
        void addBook(book temp);
        void addReader(reader temp);
        void addHolder(int bookId, int readerId);
        void addAmount(int id, int amount);
};