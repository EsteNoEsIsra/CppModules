#pragma once

#include "AForm.h"

class PresidentialPardonForm : public AForm
{
    private:
        std::string target;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string &_target);
        PresidentialPardonForm(const PresidentialPardonForm &to_copy);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &original);
        ~PresidentialPardonForm();

        std::string getTarget() const ;
        
        virtual void execute(Bureaucrat const & executor) const;



};
