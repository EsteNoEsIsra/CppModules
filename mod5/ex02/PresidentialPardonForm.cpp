#include "PresidentialPardonForm.h"
#include "Bureaucrat.h"

PresidentialPardonForm::PresidentialPardonForm() : toSign(25),toExec(5)
{
    std::cout << "Constructor Default" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const AForm &obj) : toSign(25),toExec(5)
{
    if(obj.getGradeToExec() < 1 || obj.getGradeToSign() < 1)
        throw AForm::GradeTooHighException();
    if(obj.getGradeToExec() > 150 || obj.getGradeToSign() > 150)
        throw AForm::GradeTooLowException();
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &to_copy) : toSign(to_copy.toSign), toExec(to_copy.toExec)
{
    *this = to_copy;
}
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &original)
{
    if (this != &original)
    {
        *this = original;
    }
    return *this;
}
PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "Destructor Default" << std::endl;
}

//int PresidentialPardonForm::getToSign() {return this.toSign;} 
//int PresidentialPardonForm::getToExec() {return this.toExec;} 

void execute(Bureaucrat const & executor) 
{
    if (executor.getGrade() >  5 /*getToSign()*/)
        throw AForm::GradeTooLowException();     
    std::cout << "Informs that " << executor.getName() << 
        " been pardoned by Zaphod Beeblebrox" << std::endl;
}