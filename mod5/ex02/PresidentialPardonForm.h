#pragma once

#include "AForm.h"


class PresidentialPardonForm : public AForm
{
    private:
        int toSign;
        int toExec;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const AForm &obj);
        PresidentialPardonForm(const PresidentialPardonForm &to_copy);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &original);
        ~PresidentialPardonForm();

        int getToSign() const ;
        int getToExec() const ;
        void execute(Bureaucrat const & executor) const;
};
