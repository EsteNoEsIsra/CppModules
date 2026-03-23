#ifndef INTERN_H
#define INTERN_H
#   define RED      "\033[31m"
#   define RESET    "\033[0m"

#pragma once
# include "AForm.h"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"

class Intern
{
    private:

    public:
        Intern();
        Intern(const Intern &to_copy);
        Intern &operator=(const Intern &original);
        ~Intern();

        AForm *makeForm(std::string _nameform, std::string _target);

};

#endif