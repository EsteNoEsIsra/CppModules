#include "ShrubberyCreationForm.h"
#include "Bureaucrat.h"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm",145 ,137) , target("default")
{
    std::cout << "Constructor Default" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &_target) : AForm("ShrubberyCreationForm",145 ,137) , target(_target)
{
    
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &to_copy) : AForm(to_copy), target(to_copy.target)
{
}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &original)
{
    if (this != &original)
    {
        this->target = original.target;
    }
    return *this;
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
 //   std::cout << "Destructor Default" << std::endl;
}

std::string ShrubberyCreationForm::getTarget() const { return this->target;}


void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() >  this->getGradeToExec())
        throw AForm::GradeTooLowException();
    else if (this->getSigned() == false)
        throw AForm::FormNotSigned();
    else 
    {
        std::string fname = this->getTarget() + "_shrubbery";
        std::ofstream fileout(fname.c_str());
        for(int i = 0; i < 3; i++)
        {
        fileout <<        
            "       _-_ " << std::endl << 
            "    /~~   ~~\\ " << std::endl << 
            " /~~         ~~\\ " << std::endl << 
            "{    im a tree   } " << std::endl << 
            " \\  _-     -_  / " << std::endl << 
            "   ~  \\\\ //  ~ " << std::endl << 
            "_- -   | | _- _ " << std::endl << 
            "  _ -  | |   -_ " << std::endl << 
            "      // \\\\ " << std::endl << 

            std::endl;
        }
        fileout.close();
    }

}
