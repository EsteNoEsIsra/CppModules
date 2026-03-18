#ifndef FORM_H
# define FORM_H
# include <iostream>
# include <string>

class Bureaucrat;

class Form
{
    private:
        const std::string name;
        bool isSigned;
        const int gradeToSign;
        const int gradeToExec;
    public:

    Form();
    Form(std::string const _name, const int _gradeToSign, const int _gradeToExec);
    Form(const Form &to_copy);
    Form &operator=(const Form &original);
    ~Form();    

    void beSigned(const Bureaucrat &obj);
    std::string getName()const;
    bool getSigned() const ;
    int getGradeToSign() const ;
    int getGradeToExec() const ;
    // int getGrade()const ;
    // std::string getName()const;

    // void incrementGrade();
    // void decrementGrade();

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

std::ostream &operator<<(std::ostream &os, const Form &obj);

#endif