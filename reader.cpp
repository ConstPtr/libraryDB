#include "reader.h"

reader::reader()
{
}
reader::~reader()
{
}

reader::reader(int ID, std::string fName, std::string lName, int phone)
{
    _readerID = ID;
    _firstName = fName;
    _lastName = lName;
    _phone = phone;
}

bool reader::operator<(const reader& r) const
{
    if(_lastName == r._lastName)
    {
        if(_firstName == r._firstName)
        {
            return (_phone < r._phone) ? true : false;
        }
        return (_firstName < r._firstName) ? true : false; 
    }   
    return (_lastName < r._lastName) ? true : false;
}

bool reader::operator==(const reader& r) const
{
    return (_firstName == r._firstName && 
            _lastName  == r._lastName && 
            _phone     == r._phone) ? true : false;
}

void reader::setReader()
{
    std::cout << "First name: ";
    std::getline(std::cin, _firstName);
    std::cout << "Last name: ";
    std::getline(std::cin, _lastName);
    std::cout << "Phone number: ";
    _phone = saveNumEnter("Enter correct phone number!");
}

void reader::setReader(int ID)
{
    std::cout << "Enter reader info" << std::endl;
    _readerID = ID;
    std::cout << "First name: ";
    std::getline(std::cin, _firstName);
    std::cout << "Last name: ";
    std::getline(std::cin, _lastName);
    std::cout << "Phone number: ";
    _phone = saveNumEnter("Enter correct phone number!");
}

void reader::display() const
{
    std::cout << "Name: " << _firstName << " " << _lastName << std::endl;
    std::cout << "Phone number: " << _phone << std::endl;
}

int reader::getID() const
{
    return _readerID;
}

std::string reader::getFirstName() const
{
    return _firstName;
}

std::string reader::getLastName() const
{
    return _lastName;
}

int reader::getPhone() const
{
    return _phone;
}

reader reader::getReader() const
{
    return *this;
}