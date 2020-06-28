#include "library.h"
#include "book.h"
#include "reader.h"

library::library()
{
    lastBookId = 0;
    lastReaderId = 0;
}
library::~library()
{
}

bool library::findBook()
{
    std::cout << "Enter book info: " << std::endl;
    book temp;
    temp.setBook();
    _bookIt = _books.find(temp);
    if(_bookIt == _books.end())
    {
        std::cout << "No such book exists.\n" << std::endl;
        return false;
    }
    return true;
}

void library::addBook()
{
    std::cout << "Add new book!" << std::endl;
    book temp;
    lastBookId++;
    temp.setBook(lastBookId);
    std::cout << "Amount: ";
    int amount = saveNumEnter("Enter correct amount!");
    for(const auto& bk : _books)
    {
        if(bk == temp)
        {
            std::cout << "\nThe book is already in the library.\n" << std::endl;
            return;
        }
    }
    _books.insert(temp);
    _bookAmount.insert(std::make_pair(lastBookId, amount));
    std::cout << "\nThe book has been added to the library.\n" << std::endl;
}

void library::updateBook()
{
    if(_bookIt == _books.end())
    {
        std:: cout << "\nNo such book exists.\n" << std::endl;
        return;
    }
    std::cout << "Update info" << std::endl;
    book temp;
    int id = _bookIt->getID();
    temp.setBook(id);
    _books.erase(_bookIt);
    _books.insert(temp);
    _bookIt = _books.find(temp);
    std::cout << "Amount: ";
    int amount = saveNumEnter("Enter correct amount!");
    _bookAmount[temp.getID()] = amount;
}

void library::setItersBegin()
{
    _bookIt = _books.begin();
    _readerIt = _readers.begin();
    _holdIt = _holders.begin();
    _amountIt = _bookAmount.begin();
    _iter = _holdIt->second.begin();
}

void library::addBook(book temp)
{
    _books.insert(temp);
}

book library::getBookForWrite()
{
    if(_bookIt == _books.end())
        return book(0, "", "", 0);
    auto temp = _bookIt->getBook();
    _bookIt++;
    return temp;
}

void library::deleteBook()
{
    _holdIt = _holders.find(_bookIt->getID());
    if(_holdIt->second.empty())
    {
        _amountIt = _bookAmount.find(_bookIt->getID());
        _books.erase(_bookIt);
        _bookAmount.erase(_amountIt);
        std::cout << "\nThe book has been deleted.\n" << std::endl;
    }
    else
    {
        std::cout << "\nThe reader has the book. You cannot delete it.\n" << std::endl;
    }
}

void library::bookInfo()
{
    _amountIt = _bookAmount.find(_bookIt->getID());
    std::cout << "Book info" << std::endl;
    _bookIt->display();
    std::cout << "  Amount: " << _amountIt->second << "\n" << std::endl;
}

void library::showBooks(std::string key)
{
    if(_books.empty())
    {
        std::cout << "\nNo books\n" << std::endl;
        return;
    }

    constexpr int zero = 0;
    if(key == "all")
    {
        for(const book& bk : _books)
        {
            bk.display();
            std::cout << "--------------" << std::endl;
        }
    }
    else if(key == "available")
    {
        for(const book& bk : _books)
        {
            for(_amountIt = _bookAmount.begin(); _amountIt != _bookAmount.end(); _amountIt++)
            {
                if(_amountIt->first == bk.getID() && _amountIt->second > zero)
                {
                    bk.display();
                    std::cout << "  Amount: " << _amountIt->second << std::endl;
                    std::cout << "--------------" << std::endl;
                }   
            }
        }
    }
}

void library::showHolder()
{
    if(_holders.empty())
    {
        std::cout << "\nAll books are in the library.\n" << std::endl;
        return;
    }
    _holdIt = _holders.find(_bookIt->getID());
    std::set<int>::iterator i;
    if(_holdIt->second.empty())
    {
        std::cout << "\nAll copies are in the library.\n" << std::endl;
        return;
    }
    else
    {
        for(const auto& bookHold : _holdIt->second)
            for(const auto& readerH : _readers)
                if(readerH.getID() == bookHold)
                {
                    readerH.display();
                    std::cout << "--------------" << std::endl;
                }
    }
}

bool library::findReader()
{
    std::cout << "Enter reader info" << std::endl;
    reader temp;
    temp.setReader();
    _readerIt = _readers.find(temp);
    if(_readerIt == _readers.end())
    {
        std::cout << "\nNo such reader exists.\n" << std::endl;
        return false;
    }
    return true;
}

void library::updateReader()
{
    if(_readerIt == _readers.end())
    {
        std:: cout << "\nNo such reader exists.\n" << std::endl;
        return;
    }
    std::cout << "Update info" << std::endl;
    reader temp;
    int id = _readerIt->getID();
    temp.setReader(id);
    _readers.erase(_readerIt);
    _readers.insert(temp);
    _readerIt = _readers.find(temp);
}

void library::addReader()
{
    std::cout << "Add new reader!" << std::endl;
    reader temp;
    lastReaderId++;
    temp.setReader(lastReaderId);
    for(const auto& rd : _readers)
    {
        if(rd == temp)
        {
            std::cout << "\nThe reader is already in the library.\n" << std::endl;
            return;
        }
    }
    _readers.insert(temp);
    std::cout << "\nThe reader has been added to the library.\n" << std::endl;
}

void library::addReader(reader temp)
{
    _readers.insert(temp);
}

reader library::getReaderForWrite()
{
    if(_readerIt == _readers.end())
        return reader(0, "", "", 0);
    auto temp = _readerIt->getReader();
    _readerIt++;
    return temp;
}

void library::showReaders()
{   
    if(_readers.empty())
    {
        std::cout << "\nNo readers!\n" << std::endl;
        return;
    }
    for(const reader rd : _readers)
    {
        rd.display();
        std::cout << "--------------" << std::endl;
    }
}

void library::deleteReader()
{
    _holdIt = _holders.begin();
    while(_holdIt != _holders.end())
    {
        if(_holdIt->second.find(_readerIt->getID()) != _holdIt->second.end())
        {
            std::cout << "\nCannot be deleted. The reader has books.\n" << std::endl;
            return;
        }
       _holdIt++;
    }
    _readers.erase(_readerIt);
    std::cout << "\nThe reader has been deleted.\n" << std::endl;
}

void library::readerInfo()
{
    if(_readerIt == _readers.end())
    {
        std::cout << "\nNo such reader exists.\n" << std::endl;
        return;
    }
    int status = 0;
    _readerIt->display();
    std::cout << "Readers books:" << std::endl;
    for(_holdIt = _holders.begin(); _holdIt != _holders.end(); _holdIt++)
    {
        if(_holdIt->second.find(_readerIt->getID()) != _holdIt->second.end())
        {   
            status = 1;
            for(const book& bk : _books)
            {
                if(bk.getID() == _holdIt->first)
                {
                    bk.display();
                    std::cout << "--------------" << std::endl;
                }
            }
        }
    }
    if(status == 0)
        std::cout << "\nNo books\n" << std::endl;
    std::cout << std::endl;
}

void library::giveBook()
{
    constexpr int zero = 0;
    findBook();
    _amountIt = _bookAmount.find(_bookIt->getID());
    _holdIt = _holders.find(_bookIt->getID());
    if(_amountIt->second == zero)
    {
        std::cout << "\nBooks has run out!\n" << std::endl;
        return;
    }
    else if(_holdIt == _holders.end())
    {
        std::set<int> holders;
        holders.insert(_readerIt->getID());
        _holders.insert(std::make_pair(_bookIt->getID(), holders));
        _amountIt->second--;
    }
    else if(_holdIt->second.find(_readerIt->getID()) != _holdIt->second.end())
    {
        std::cout << "\nUser already has this book.\n" << std::endl;
        return;
    }
    else
    {
        _holdIt->second.insert(_readerIt->getID());
        _amountIt->second--;
        std::cout << "\nThe reader took the book!\n" << std::endl;
    }
}

void library::returnBook()
{
    findBook();
    _holdIt = _holders.find(_bookIt->getID());
    _amountIt = _bookAmount.find(_bookIt->getID());
    if(_holdIt == _holders.end())
    {
        std::cout << "\nAll book copies in the library.\n" << std::endl;
    }
    else if(_holdIt->second.find(_readerIt->getID()) != _holdIt->second.end())
    {
        _holdIt->second.erase(_holdIt->second.find(_readerIt->getID()));
        _amountIt->second++;
        std::cout << "\nThe reader returned the book!\n" << std::endl;
    }
    else
    {
        std::cout << "\nThe reader does not have this book.\n" << std::endl;
    }
}

void library::addAmount(int id, int amount)
{
    _bookAmount.insert(std::make_pair(id, amount));
}

std::pair<int, int> library::getAmountForWrite()
{
    if(_amountIt == _bookAmount.end())
    {
        return std::make_pair(0, 0);
    }
    auto temp = std::make_pair(_amountIt->first, _amountIt->second);
    _amountIt++;
    return temp;
}

std::pair<int, int> library::getHolderForWrite()
{
    if(_holders.empty())
        return std::make_pair(0, 0);
    if(_iter == _holdIt->second.end())
    {
        _holdIt++;
        if(_holdIt == _holders.end())
            return std::make_pair(0, 0);
        _iter = _holdIt->second.begin();
    }
    auto temp = std::make_pair(_holdIt->first, *_iter);
    _iter++;
    return temp;
}

void library::addHolder(int bookId, int readerId)
{
    _holdIt = _holders.find(bookId);
    if(_holdIt == _holders.end())
    {
        std::set<int> readers;
        readers.insert(readerId);
        _holders.insert(std::make_pair(bookId, readers));
    }
    else
    {
        _holdIt->second.insert(readerId); 
    }
}