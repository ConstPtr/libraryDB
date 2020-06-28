#include "book.h"

book::book()
{
}
book::book(int ID, std::string title, std::string author, int year)
{
    _bookID = ID;
    _title = title;
    _author = author;
    _year = year;
}
book::~book()
{
}

bool book::operator<(const book& bk) const
{
    if(_title == bk._title)
    {
        if(_author == bk._author)
        {
            return (_year < bk._year) ? true : false;
        }
        return (_author < bk._author) ? true : false; 
    }   
    return (_title < bk._title) ? true : false;
}

bool book::operator==(const book& bk) const
{
    return (_title  == bk._title  && 
            _author == bk._author && 
            _year   == bk._year) ? true : false;
}

void book::setBook()
{
    std::cout << "Title: ";
    std::getline(std::cin, _title);
    std::cout << "Author: ";
    std::getline(std::cin, _author);
    std::cout << "Year: ";
    _year = saveNumEnter("Enter correct year!");
}

void book::setBook(int ID)
{
    std::cout << "Enter book info" << std::endl;
    _bookID = ID;
    std::cout << "Title: ";
    std::getline(std::cin, _title);
    std::cout << "Author: ";
    std::getline(std::cin, _author);
    std::cout << "Year: ";
    _year = saveNumEnter("Enter correct year!");
}

void book::display() const
{
    std::cout << "  Title: " << _title << std::endl;
    std::cout << "  Author: " << _author << std::endl;
    std::cout << "  Year: " << _year << std::endl;
}

int book::getID() const
{
    return _bookID;
}

std::string book::getTitle() const
{
    return _title;
}
std::string book::getAuthor() const
{
    return _author;
}

int book::getYear() const
{
    return _year;
}

book book::getBook() const
{
    return *this;
}