#include "Form.h"
#include "Bureaucrat.h"

Form::Form() : name("default"), isSigned(false), gradeToSign(0), gradeToExec(0)
{
    std::cout << "Bureaucrat Default Constructor Called  ????" << std::endl;
}
Form::Form(std::string const _name, const int _gradeToSign , const int _gradeToExec) : name(_name),
 isSigned(false), gradeToSign(_gradeToSign), gradeToExec(_gradeToExec)
{
    if (_gradeToExec < 1  || _gradeToSign < 1)
        throw Form::GradeTooHighException();
    if (_gradeToExec > 150  || _gradeToSign > 150)
        throw Form::GradeTooLowException();


}
Form::Form(const Form &to_copy) : name(to_copy.name), isSigned(to_copy.isSigned),
    gradeToSign(to_copy.gradeToSign), gradeToExec(to_copy.gradeToExec)
{
    std::cout << "Bureaucrat copy Constructor Called  " << std::endl;
}
Form& Form::operator=(const Form &original)
{
    if(this != &original)
    {
        *this = original;
    }
    //std::cout << "Form operator Called" << std::endl;
    return *this;
}
Form::~Form()
{
    //std::cout << "Form destructor called" << std::endl;
}
void Form::beSigned(const Bureaucrat& obj)
{
    if (obj.getGrade() < 1)
        throw Form::GradeTooLowException();
    if (obj.getGrade() > 150)
        throw Form::GradeTooHighException();
    this->isSigned = true;
}

const char * Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high maximun 1 ****";
}


const char * Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low minimun 150 ****";
}


std::string Form::getName()const { return this->name;}
bool Form::getSigned() const {return this->isSigned;}
int  Form::getGradeToSign() const { return this->gradeToSign;}
int  Form::getGradeToExec() const {return this->gradeToExec;}


std::ostream &operator<<(std::ostream &os, const Form &obj)
{
    os << obj.getName() <<", Form , isSigned: " 
        << obj.getSigned() << " gradeToSign " << obj.getGradeToSign()
        <<" gradeToExecute " << obj.getGradeToExec();

    return os;
}