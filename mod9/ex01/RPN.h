#ifndef RPN_H
#define RPN_H

#pragma once
#include <iostream>
#include <stack>
#include <string>
#include <exception>


class RPN
{
    private:
        std::stack<double> stack_c;

        RPN();
    public:
        
        RPN(const RPN &to_copy);
        RPN &operator=(const RPN &original);
        ~RPN();

        RPN(std::string &input);

        double calculateRPN(const std::string &input);
   

    class NotEnoughElements : public std::exception
    {
        virtual const char* what() const throw();
    };
    class DivOnCero : public std::exception
    {
        virtual const char* what() const throw();
    };
    class InvalidArguments : public std::exception
    {
        virtual const char* what() const throw();
    };

};

#endif