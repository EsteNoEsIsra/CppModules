#pragma once

#include "AForm.h"

class PresidentialPardonForm : public AForm
{
    private:
        
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm &to_copy);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &original);
        ~PresidentialPardonForm();

       // virtual void execute(Bureaucrat const & executor) const = 0;
};
