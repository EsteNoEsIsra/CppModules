#include "AForm.h"
#include "Bureaucrat.h"

AForm::AForm() : name("default"), isSigned(false), gradeToSign(0), gradeToExec(0)
{
    std::cout << "Bureaucrat Default Constructor Called  ????" << std::endl;
}
AForm::AForm(std::string const _name, const int _gradeToSign , const int _gradeToExec) : name(_name),
 isSigned(false), gradeToSign(_gradeToSign), gradeToExec(_gradeToExec)
{
    if (_gradeToExec < 1  || _gradeToSign < 1)
        throw AForm::GradeTooHighException();
    if (_gradeToExec > 150  || _gradeToSign > 150)
        throw AForm::GradeTooLowException();


}
AForm::AForm(const AForm &to_copy) : name(to_copy.name), isSigned(to_copy.isSigned),
    gradeToSign(to_copy.gradeToSign), gradeToExec(to_copy.gradeToExec)
{
    std::cout << "Bureaucrat copy Constructor Called  " << std::endl;
}
AForm& AForm::operator=(const AForm &original)
{
    if(this != &original)
    {
        *this = original;
    }
    //std::cout << "AForm operator Called" << std::endl;
    return *this;
}
AForm::~AForm()
{
    //std::cout << "AForm destructor called" << std::endl;
}
void AForm::beSigned(const Bureaucrat& obj)
{
    if (this->isSigned == false)
    {
        if (obj.getGrade() > this->gradeToSign)
            throw AForm::GradeTooLowException();
        //if (obj.getGrade() > 1)
        //   throw AForm::GradeTooHighException();
        this->isSigned = true;
    }
    else 
        std::cout << this->getName() << " is already signed" << std::endl;
}

const char * AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}


const char * AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

const char * AForm::FormNotSigned::what() const throw()
{
    return " is not signed ";
}

std::string AForm::getName()const { return this->name;}
bool AForm::getSigned() const {return this->isSigned;}
int  AForm::getGradeToSign() const { return this->gradeToSign;}
int  AForm::getGradeToExec() const {return this->gradeToExec;}


void AForm::execute(Bureaucrat const & executor)  const 
{
    std::cout << executor.getName() << std::endl; 
}

std::ostream &operator<<(std::ostream &os, const AForm &obj)
{
    os << obj.getName() <<":AForm  isSigned: " 
        << obj.getSigned() << " gradeToSign= " << obj.getGradeToSign()
        <<" gradeToExecute= " << obj.getGradeToExec();

    return os;
}