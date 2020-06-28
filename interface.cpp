#include "interface.h"

interface::interface(){}
interface::interface(library& lib, fileManage& file)
{
    _lib = &lib;
    _file = &file;
}

interface::~interface()
{
}

void interface::mainMenu()
{
    constexpr unsigned int exit = 3;
    int unsigned num = 0;
    do
    {
        std::cout << "\nProgram menu:" << std::endl;
        std::cout << "=============" << std::endl;
        std::cout << "1. Books" << std::endl;
        std::cout << "2. Readers" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << ">";
        num = saveNumEnter("Enter the correct menu item!");
        switch (num)
        {
        case 1:
            system("cls");
            booksMenu();
            break;
        case 2:
            system("cls");
            readersMenu();
            break;
        }
    }while(num != exit);
}

void interface::booksMenu()
{
    int unsigned num = 0;
    do
    {
        std::cout << "\nBooks managment menu:" << std::endl;
        std::cout << "=====================" << std::endl;
        std::cout << "1. Add book" << std::endl;
        std::cout << "2. Show all books" << std::endl;
        std::cout << "3. Show available books" << std::endl;
        std::cout << "4. Find book" << std::endl;
        std::cout << "5. Back" << std::endl;
        std::cout << ">";
        num = saveNumEnter("Enter the correct menu item!");
        switch (num)
        {
        case 1:
            system("cls");
            _lib->addBook();
            break;
        case 2:
            system("cls");
            _lib->showBooks("all");
            break;
        case 3:
            system("cls");
            _lib->showBooks("available");
            break;
        case 4:
            system("cls");
            if(_lib->findBook())
                directBook();
            break;
        case 5:
            system("cls");
            return;
        default:
            std::cout << "Enter the correct menu item!" << std::endl;
            break;
        }
    }while (true);
}

void interface::directBook()
{
    int unsigned num = 0;
    do
    {
        std::cout << "\nManage book:" << std::endl;
        std::cout << "=============" << std::endl;
        std::cout << "1. Show book info" << std::endl;
        std::cout << "2. Show book holders" << std::endl;
        std::cout << "3. Update book info" << std::endl;
        std::cout << "4. Delete book" << std::endl;
        std::cout << "5. Back" << std::endl;
        std::cout << ">";
        num = saveNumEnter("Enter the correct menu item!");
        switch (num)
        {
        case 1:
            system("cls");
            _lib->bookInfo();
            break;
        case 2:
            system("cls");
            _lib->showHolder();
            break;
        case 3:
            system("cls");
            _lib->updateBook();
            break;
        case 4:
            system("cls");
            _lib->deleteBook();
            return;
            break;
        case 5:
            system("cls");
            return;
        default:
            std::cout << "Enter the correct menu item!" << std::endl;
            break;
        }
    }while (true);
}

void interface::readersMenu()
{
    int unsigned num = 0;
    do
    {
        std::cout << "\nReaders managment menu:" << std::endl;
        std::cout << "=====================" << std::endl;
        std::cout << "1. Add reader" << std::endl;
        std::cout << "2. Show all readers" << std::endl;
        std::cout << "3. Find reader" << std::endl;
        std::cout << "4. Back" << std::endl;
        std::cout << ">";
        num = saveNumEnter("Enter the correct menu item!");
        switch (num)
        {
        case 1:
            system("cls");
            _lib->addReader();
            break;
        case 2:
            system("cls");
            _lib->showReaders();
            break;
        case 3:
            system("cls");
            if(_lib->findReader())
                directReader();
            break;
        case 4:
            system("cls");
            return;
        default:
            std::cout << "Enter the correct menu item!" << std::endl;
            break;
        }
    }while (true);
}

void interface::directReader()
{
    int unsigned num = 0;
    do
    {
        std::cout << "\nManage reader:" << std::endl;
        std::cout << "=============" << std::endl;
        std::cout << "1. Reader info" << std::endl;
        std::cout << "2. Give a book" << std::endl;
        std::cout << "3. Return a book" << std::endl;
        std::cout << "4. Update reader info" << std::endl;
        std::cout << "5. Delete reader" << std::endl;
        std::cout << "6. Back" << std::endl;
        std::cout << ">";
        num = saveNumEnter("Enter the correct menu item!");
        switch (num)
        {
        case 1:
            system("cls");
            _lib->readerInfo();
            break;
        case 2:
            system("cls");
            _lib->giveBook();
            break;
        case 3:
            system("cls");
            _lib->returnBook();
            break;
        case 4:
            system("cls");
            _lib->updateReader();
            return;
            break;
        case 5:
            system("cls");
            _lib->deleteReader();
            return;
            break;
        case 6:
            system("cls");
            return;
        default:
            std::cout << "Enter the correct menu item!" << std::endl;
            break;
        }
    } while(true);
}