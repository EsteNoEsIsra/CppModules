#include "PhoneBook.hpp"

#include <string>
#include <iostream>
int main()
{
    std::string command;
    PhoneBook phoneBook;

    while(true)
    {
        std::cout << "***************************************" << std::endl;
        std::cout << "*         *PhoneBook Application      *" << std::endl;
        std::cout << "***************************************" << std::endl;
        std::cout << "*Enter a command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin ,command);

        if (command == "ADD")
        {
            phoneBook.addContact();
        }
        else if (command == "SEARCH")
        {
            phoneBook.displayContacts();
        }   
        else if (command == "EXIT")
            break;
        else
            std::cout << "Invalid command." << std::endl;
    }
    std::cout << "***************************************" << std::endl;
    std::cout << "*       Goodbye Student.              *" << std::endl;
    std::cout << "***************************************" << std::endl;
    return 0;
}