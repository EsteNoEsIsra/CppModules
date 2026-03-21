#pragma once                  

#include "AForm.h"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm
{
    private:
        std::string target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string &_target);
        RobotomyRequestForm(const RobotomyRequestForm &to_copy);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &original);
        ~RobotomyRequestForm();

        std::string getTarget() const ;
        
        virtual void execute(Bureaucrat const & executor) const;

   

};



