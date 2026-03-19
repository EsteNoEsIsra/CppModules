#ifndef AFORM_H
# define AFORM_H
# include <iostream>
# include <string>

class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        bool isSigned;
        const int gradeToSign;
        const int gradeToExec;
    public:

    AForm();
    AForm(std::string const _name, const int _gradeToSign, const int _gradeToExec);
    AForm(const AForm &to_copy);
    AForm &operator=(const AForm &original);
    ~AForm();    

    void beSigned(const Bureaucrat &obj);
    std::string getName()const;
    bool getSigned() const ;
    int getGradeToSign() const ;
    int getGradeToExec() const ;
    
    virtual void execute(Bureaucrat const & executor) const = 0;

    class GradeTooHighException : public std::exception
    {
        public:
            virtual const char *what() const throw ();
    };

    class GradeTooLowException : public std::exception
    {
        public:
            virtual const char *what() const throw ();
    };

};

std::ostream &operator<<(std::ostream &os, const AForm &obj);

#endif