#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
#   define RED      "\033[31m"
#   define RESET    "\033[0m"

# include <iostream>
# include <string>
# include <exception>



class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    public:

    Bureaucrat();
    Bureaucrat(std::string const _name, int _grade);
    Bureaucrat(const Bureaucrat &to_copy);
    Bureaucrat &operator=(const Bureaucrat &original);
    ~Bureaucrat();    

    int getGrade()const ;
    std::string getName()const;

    void incrementGrade();
    void decrementGrade();

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

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj);

#endif