#pragma once 

#include <iostream>
#include <string>

class Bureaucrat
{
    private:
        const std::string name;
        unsigned int grade;
    public:

    Bureaucrat();
    Bureaucrat(const Bureaucrat &to_copy);
    Bureaucrat &operator=(const Bureaucrat &original);
    ~Bureaucrat();    


    int getGrade()const ;
    std::string getName();
};