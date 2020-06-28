#pragma once
#include <iostream>
#include <memory>
#include "library.h"
#include "fileManage.h"

class interface
{
    private:
        library* _lib;
        fileManage* _file;
    public:
        interface();
        interface(library& lib, fileManage& file);
        ~interface();
        void mainMenu();
        void booksMenu();
        void readersMenu();
        void directBook();
        void directReader();

        void writeData();
        void readData();

        void writeHolders();
        void readHolders();
        void writeAmount();
        void readAmount();
};