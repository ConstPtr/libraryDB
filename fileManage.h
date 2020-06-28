#pragma once
#include <iostream>
#include <fstream>
#include "library.h"
#include "reader.h"
#include "book.h"

class fileManage
{
    private:
        library* _lib;
    public:
        fileManage();
        fileManage(library& lib);
        ~fileManage();
        void writeBooks();
        void readBooks();
        void writeReaders();
        void readReaders();
        void writeHolders();
        void readHolders();
        void writeAmount();
        void readAmount();
        
};