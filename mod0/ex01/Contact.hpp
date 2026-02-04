#pragma once
#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>
# include <iomanip>

class Contact
{
    private:
        std::string firstName;
        std::string lastName;
        std::string nickname;
        std::string phoneNumber;
        std::string darkestSecret;
        
    public:
        void setFirstName(std::string _firstName);
        void setLastName(std::string _lastName);
        void setNickname(std::string _nickname);
        void setPhoneNumber(std::string _phoneNumber);
        void setDarkestSecret(std::string _darkestSecret);

        std::string getFirstName() const { return firstName; }
        std::string getLastName() const { return lastName; }
        std::string getNickname() const { return nickname; }
        std::string getPhoneNumber() const { return phoneNumber; }
        std::string getDarkestSecret() const { return darkestSecret; }
};

#endif