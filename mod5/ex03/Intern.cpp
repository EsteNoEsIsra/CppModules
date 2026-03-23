#include "Intern.h"

Intern::Intern()
{
    	std::cout << "Intern Default Constructor called" << std::endl;

}
Intern::Intern(const Intern &to_copy)
{
    std::cout << "Intern Copty Constructor called" << std::endl;
    *this = to_copy;
}
Intern &Intern::operator=(const Intern &original)
{
    std::cout << "Intern asignation called" << std::endl;
    if(this != &original)
    {
        *this = original;
    }
    return *this;
}

static AForm	*makePresidentialPardonForm(const std::string _target)
{
	return (new PresidentialPardonForm(_target));
}

static AForm	*makeRobotomyRequestForm(const std::string _target)
{
	return (new RobotomyRequestForm(_target));
}

static AForm	*makeShrubberyCreationForm(const std::string _target)
{
	return (new ShrubberyCreationForm(_target));
}

Intern::~Intern()
{
    std::cout << "Intern Destructor called" << std::endl;
}

AForm *Intern::makeForm(std::string _nameform, std::string _target)
{
    std::string formNames[] = {"Presidential Pardon", "Robotomy Request", "Shrubbery Creation"};
    AForm *(*funtions[])(std::string) = {makePresidentialPardonForm, makeRobotomyRequestForm, makeShrubberyCreationForm};

    for(int i = 0; i < 3; i++)
    {
        if(_nameform == formNames[i])
        {
            std::cout << "Intern creates " << _nameform << std::endl;
            return (funtions[i](_target));
        }
    }
    std::cout << RED << "Error: Form " << _nameform << "' doesnt exist" << RESET << std::endl;
    return NULL;
}