#include <iostream>
#include "func.h"
#include "book.h"
#include "reader.h"
#include "library.h"
#include "interface.h"
#include "fileManage.h"
 
int main()
{
      library lib;
      fileManage file(lib);
      interface userInterface(lib, file);
      userInterface.mainMenu();
      
      return EXIT_SUCCESS;
}