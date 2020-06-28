#include<iostream>

int saveNumEnter(std::string message)
{   
    std::cin.clear();
    std::cin.sync();
    int i;
    while (!(std::cin >> i) || std::cin.get() != '\n' || i <= 0)
    {
        std::cout << message << std::endl;
        std::cin.clear();
        std::cin.sync();
    }
    return i;
}




