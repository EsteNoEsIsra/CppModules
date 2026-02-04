#include "PhoneBook.hpp"


PhoneBook::PhoneBook()
{
    contactNum = 0;
}

void PhoneBook::addContact()
{
    if (contactNum < maxContacts)
    {
        std::string firstName;
        std::string lastName;
        std::string nickname;
        std::string phoneNumber;
        std::string darkestSecret;

        std::cout << "Enter First Name: ";
        std::getline(std::cin , firstName);
        
        if (firstName.empty())
        {
            std::cout << "First Name cannot be empty or contain only whitespace. Contact not added." << std::endl;
            return;
        }
        contacts[contactNum].setFirstName(firstName);

        std::cout << "Enter Last Name: ";
        std::getline(std::cin , lastName);
     
        if (lastName.empty())
        {
            std::cout << "Last Name cannot be empty. Contact not added." << std::endl;
            return;
        }
        contacts[contactNum].setLastName(lastName);

        std::cout << "Enter Nickname: ";
        std::getline(std::cin , nickname);

        if (nickname.empty())
        {
            std::cout << "Nickname cannot be empty. Contact not added." << std::endl;
            return;
        }
        contacts[contactNum].setNickname(nickname);

        std::cout << "Enter Phone Number: ";
        std::getline(std::cin , phoneNumber);

        if (phoneNumber.empty())
        {
            std::cout << "Phone Number cannot be empty. Contact not added." << std::endl;
            return;
        }
        else if (phoneNumber.find_first_not_of("0123456789") != std::string::npos)
        {
            std::cout << "Phone Number must contain only digits. Contact not added." << std::endl;
            return;
        }

        contacts[contactNum].setPhoneNumber(phoneNumber);

        std::cout << "Enter Darkest Secret: ";
        std::getline(std::cin , darkestSecret);

        if (darkestSecret.empty())
        {
            std::cout << "Darkest Secret cannot be empty. Contact not added." << std::endl;
            return;
        }
        contacts[contactNum].setDarkestSecret(darkestSecret);

        contactNum++;
        std::cout << "Contact added successfully." << std::endl;
    }
    else
    {
        std::cout << "PhoneBook is full. Deleting the oldest contact." << std::endl;
        for (int i = 0; i < maxContacts - 1; i++)
        {
            contacts[i] = contacts[i + 1];
        }
        contactNum = maxContacts - 1;
        addContact();
    }
}

void PhoneBook::displayContacts()
{
    std::string input;
    int index;

    if (contactNum == 0)
    {
        std::cout << "No contacts to display." << std::endl;
        return;
    }
    std::cout << "********************************************" << std::endl;
    std::cout << "Index | First Name |  Last Name  |  Nickname  " << std::endl;
    std::cout << "********************************************" << std::endl;
    for (int i = 0; i < contactNum; i++)
    {
        std::cout << "(" << i + 1 << ")   | " 
            << std::setw(10) << formatLongString(contacts[i].getFirstName()) << " | "
            << std::setw(10) << formatLongString(contacts[i].getLastName()) << "  | "
            << std::setw(10) << formatLongString(contacts[i].getNickname()) << std::endl;
    }

    
    std::cout << "Enter the index of the contact to view details: " << std::endl;
    std::getline(std::cin ,input);

    if (input.empty() || input.length() != 1 || input.find_first_not_of("0123456789") != std::string::npos)
    {
        std::cout << "Invalid index." << std::endl;
        return;
    }
    index = atoi(input.c_str());

    if (index < 1 || contactNum < index)
    {
        std::cout << "Invalid index." << std::endl;
        return;
    }

    displayContactDetails(index - 1);
}

void PhoneBook::displayContactDetails(int index)
{
    std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
    std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
    std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
}

std::string PhoneBook::formatLongString(std::string str)
{
    if (str.length() > 10)
        return (str.substr(0, 9) + ".");
    else
        return (str);
}