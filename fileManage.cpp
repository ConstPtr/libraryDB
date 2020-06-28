#include "fileManage.h"

fileManage::fileManage(){}
fileManage::fileManage(library& lib)
{
    _lib = &lib;
    readBooks();
    readReaders();
    readAmount();
    readHolders(); 
}

fileManage::~fileManage()
{ 

    _lib->setItersBegin();
    writeBooks();
    writeReaders();
    writeAmount();
    writeHolders();
}

void fileManage::writeBooks()
{
    constexpr int zero = 0;
    std::ofstream writeFile("books.bin", std::ios::binary);
    if(!writeFile)
    {
        std::cout << "Can't create file \"books.bin\"" << std::endl;
        return;
    }
    auto b = _lib->getBookForWrite();
    while(b.getID() != zero)
    {   
        unsigned int id = b.getID();
        std::string buffTitle = b.getTitle();
        std::string buffAuthor = b.getAuthor();
        unsigned int year = b.getYear();
        const char* title = buffTitle.data();
        const char* author = buffAuthor.data();
        int titleLen = strlen(title) + 1;
        int authorLen = strlen(author) + 1;
        writeFile.write(reinterpret_cast<char*>(&titleLen), sizeof(int));
        writeFile.write(reinterpret_cast<char*>(&authorLen), sizeof(int));
        writeFile.write(reinterpret_cast<char*>(&id), sizeof(int));
        writeFile.write(title, titleLen);
        writeFile.write(author, authorLen);
        writeFile.write(reinterpret_cast<char*>(&year), sizeof(int));
        b = _lib->getBookForWrite();
    }
    writeFile.close();
}

void fileManage::writeReaders()
{
    constexpr int zero = 0;
    std::ofstream writeFile("readers.bin", std::ios::binary);
    if(!writeFile)
    {
        std::cout << "Can't create file \"readers.bin\"" << std::endl;
        return;
    }
    auto r = _lib->getReaderForWrite();
    while(r.getID() !=  zero)
    {
        unsigned int id = r.getID();
        std::string bufferFName = r.getFirstName();
        std::string bufferLName = r.getLastName();
        unsigned int phone = r.getPhone();
        const char* fname = bufferFName.data();
        const char* lname = bufferLName.data();
        int fNameLen = strlen(fname) + 1;
        int lNameLen = strlen(lname) + 1;
        writeFile.write(reinterpret_cast<char*>(&fNameLen), sizeof(int));
        writeFile.write(reinterpret_cast<char*>(&lNameLen), sizeof(int));
        writeFile.write(reinterpret_cast<char*>(&id), sizeof(int));
        writeFile.write(fname, fNameLen);
        writeFile.write(lname, lNameLen);
        writeFile.write(reinterpret_cast<char*>(&phone), sizeof(int));
        r = _lib->getReaderForWrite();
    }
    writeFile.close();
}

void fileManage::readBooks()
{
    std::ifstream readFile;
    readFile.open("books.bin", std::ios::binary);
    if(!readFile)
    {
        std::cout << "Can't open file \"books.bin\"" << std::endl;
        return;
    }
    int titleLen;
    int authorLen;
    int id;
    int year;
    while(readFile.peek() != EOF)
    {
        readFile.read(reinterpret_cast<char*>(&titleLen), sizeof(int));
        readFile.read(reinterpret_cast<char*>(&authorLen), sizeof(int));
        char bufferTitle[titleLen + 1];
        char bufferAuthor[authorLen + 1];
        readFile.read(reinterpret_cast<char*>(&id), sizeof(int));
        readFile.read(bufferTitle, titleLen);
        readFile.read(bufferAuthor, authorLen);
        readFile.read(reinterpret_cast<char*>(&year), sizeof(int));
        std::string title(bufferTitle);
        std::string author(bufferAuthor);
        book temp(id, title, author, year);
        _lib->addBook(temp);
    }
    readFile.close();
}

void fileManage::readReaders()
{
    std::ifstream readFile;
    readFile.open("readers.bin", std::ios::binary);
    if(!readFile)
    {
        std::cout << "Can't open file \"readers.bin\"" << std::endl;
        return;
    }
    int fNameLen;
    int lNameLen;
    int id;
    int phone;
    while(readFile.peek() != EOF)
    {
        readFile.read(reinterpret_cast<char*>(&fNameLen), sizeof(int));
        readFile.read(reinterpret_cast<char*>(&lNameLen), sizeof(int));
        char bufferFName[fNameLen + 1];
        char bufferLName[lNameLen + 1];
        readFile.read(reinterpret_cast<char*>(&id), sizeof(int));
        readFile.read(bufferFName, fNameLen);
        readFile.read(bufferLName, lNameLen);
        readFile.read(reinterpret_cast<char*>(&phone), sizeof(int));
        std::string title(bufferFName);
        std::string author(bufferLName);
        reader temp(id, title, author, phone);
        _lib->addReader(temp);
    }
    readFile.close();
}

void fileManage::writeAmount()
{
    constexpr int zero = 0;
    std::ofstream writeFile("amount.bin", std::ios::binary);
    if(!writeFile)
    {
        std::cout << "Can't create file \"amount.bin\"" << std::endl;
        return;
    }
    auto temp = _lib->getAmountForWrite();
    int id = temp.first;
    int amount = temp.second;
    while(id != zero)
    {
        writeFile.write(reinterpret_cast<char*>(&id), sizeof(int));
        writeFile.write(reinterpret_cast<char*>(&amount), sizeof(int));
        temp = _lib->getAmountForWrite();
        id = temp.first;
        amount = temp.second;
    }
    writeFile.close();
}

void fileManage::readAmount()
{
    std::ifstream readFile;
    readFile.open("amount.bin", std::ios::binary);
    if(!readFile)
    {
        std::cout << "Can't open file \"amount.bin\"" << std::endl;
        return;
    }
    int id;
    int amount;
    while(readFile.peek() != EOF)
    {        
        readFile.read(reinterpret_cast<char*>(&id), sizeof(int));
        readFile.read(reinterpret_cast<char*>(&amount), sizeof(int));
        _lib->addAmount(id, amount);
    }
    readFile.close();
}

void fileManage::writeHolders()
{
    constexpr int zero = 0;
    std::ofstream writeFile("holders.bin", std::ios::binary);
    if(!writeFile)
    {
        std::cout << "Can't create file \"holders.bin\"" << std::endl;
        return;
    }
    auto temp = _lib->getHolderForWrite();
    int bookId = temp.first;
    int readerId = temp.second;
    while(bookId != zero)
    {
        writeFile.write(reinterpret_cast<char*>(&bookId), sizeof(int));
        writeFile.write(reinterpret_cast<char*>(&readerId), sizeof(int));
        auto temp = _lib->getHolderForWrite();
        bookId = temp.first;
        readerId = temp.second;
    }
    writeFile.close();
}

void fileManage::readHolders()
{
    std::ifstream readFile;
    readFile.open("holders.bin", std::ios::binary);
    if(!readFile)
    {
        std::cout << "Can't open file \"holders.bin\"" << std::endl;
        return;
    }
    int bookId;
    int readerId;
    while(readFile.peek() != EOF)
    {
        readFile.read(reinterpret_cast<char*>(&bookId), sizeof(int));
        readFile.read(reinterpret_cast<char*>(&readerId), sizeof(int));
        _lib->addHolder(bookId, readerId);
    }
    readFile.close();
}