#pragma once
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
    private:
        static const int maxContacts = 8;// 8 contacts maximum
        Contact contacts[maxContacts];
        int contactNum;   
    public:
        PhoneBook();
        void addContact();
        void displayContacts();
        void displayContactDetails(int index);
        std::string formatLongString(std::string str);
};

#endif