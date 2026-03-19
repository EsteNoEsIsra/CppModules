 #include "Bureaucrat.h"
 #include "Form.h"

Bureaucrat::Bureaucrat(): name("default"), grade(150)
{
    std::cout << "Bureaucrat Default Constructor Called  with a grade 150" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const _name, int _grade) : name(_name)
{
    //std::cout << "Bureaucrat Constructor Called" << std::endl;
    if (_grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (_grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade = _grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &to_copy) : name(to_copy.name), grade(to_copy.grade)
{
    //std::cout << "Bureaucrat Constructor Called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &original)
{
    if(this != &original)
    {        
        this->grade = original.grade;
    }
    //std::cout << "Bureaucrat operator Called" << std::endl;
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    //std::cout << "Bureaucrat Destructor Called" << std::endl;
}

int Bureaucrat::getGrade() const { return this->grade; }
std::string Bureaucrat::getName() const { return this->name; }

void Bureaucrat::incrementGrade()
{
    if ((this->grade -1) < 1)
        throw Bureaucrat::GradeTooHighException();
    else 
        this->grade--;
}   

void Bureaucrat::decrementGrade()
{
    if ((this->grade + 1) > 150)
        throw Bureaucrat::GradeTooLowException();
    else 
        this->grade++;
}

void Bureaucrat::signForm(Form &obj)
{
    if (obj.getSigned() == false)
    {
        try
        {
            obj.beSigned(*this);
            std::cout << this->getName() << " signed "  << obj.getName() << std::endl;
        }
        catch (std::exception &e)
        {
            std::cerr << RED << this->getName() << " couldn't sign " << obj.getName() << " because " << e.what() << RESET << std::endl ; 
        }
    }
    
}


const char * Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high maximun 1";
}


const char * Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low minimun 150";
}


std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj)
{
    os << obj.getName() <<", Bureaucrat grade " << obj.getGrade(); 
    return os;
}