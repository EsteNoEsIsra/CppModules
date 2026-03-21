#include "RobotomyRequestForm.h"
#include "Bureaucrat.h"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm",75 ,45) , target("default")
{
    std::cout << "Constructor Default" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &_target) : 
AForm("RobotomyRequestForm",75 ,45) , target(_target)
{
    // if(obj.getGradeToExec() < 1 || obj.getGradeToSign() < 1)
    //     throw AForm::GradeTooHighException();
    // if(obj.getGradeToExec() > 150 || obj.getGradeToSign() > 150)
    //     throw AForm::GradeTooLowException();
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &to_copy) : AForm(to_copy), target(to_copy.target)
{
}
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &original)
{
    if (this != &original)
    {
        this->target = original.target;
    }
    return *this;
}
RobotomyRequestForm::~RobotomyRequestForm()
{
  //  std::cout << "Destructor Default" << std::endl;
}

std::string RobotomyRequestForm::getTarget() const  { return this->target;}


void RobotomyRequestForm::execute(Bureaucrat const & executor) const 
{
    //std::srand(time(0)); en el main para mejor funcionamineto del random

    if (executor.getGrade() >  this->getGradeToExec())
        throw AForm::GradeTooLowException();
    else if (this->getSigned() == false)
        throw AForm::FormNotSigned();
    
    if  (rand() % 2 == 0)
        std::cout << this->target << " has been robotimized " << std::endl;
    else
        std::cout << this->target << " robotomy failed " << std::endl;
}

