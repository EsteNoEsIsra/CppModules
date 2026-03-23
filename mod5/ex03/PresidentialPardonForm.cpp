#include "PresidentialPardonForm.h"
#include "Bureaucrat.h"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm",25 ,5) , target("default")
{
    std::cout << "Constructor Default" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &_target) : AForm("PresidentialPardonForm",25 ,5) , target(_target)
{
    // if(obj.getGradeToExec() < 1 || obj.getGradeToSign() < 1)
    //     throw AForm::GradeTooHighException();
    // if(obj.getGradeToExec() > 150 || obj.getGradeToSign() > 150)
    //     throw AForm::GradeTooLowException();
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &to_copy) : AForm(to_copy), target(to_copy.target)
{
}
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &original)
{
    if (this != &original)
    {
        this->target = original.target;
    }
    return *this;
}
PresidentialPardonForm::~PresidentialPardonForm()
{
   // std::cout << "Destructor Default" << std::endl;
}

std::string PresidentialPardonForm::getTarget() const { return this->target;}


void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() >  this->getGradeToExec())
        throw AForm::GradeTooLowException();
    else if (this->getSigned() == false)
        throw AForm::FormNotSigned();
    std::cout << "Informs that " << executor.getName() << 
        " been pardoned by Zaphod Beeblebrox" << std::endl;
}
