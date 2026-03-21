#pragma once 

#include "AForm.h"
#include "fstream"
class ShrubberyCreationForm : public AForm
{
    private:
        std::string target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string &_target);
        ShrubberyCreationForm(const ShrubberyCreationForm &to_copy);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &original);
        ~ShrubberyCreationForm();

        std::string getTarget() const ;
        
        virtual void execute(Bureaucrat const & executor) const;



};


