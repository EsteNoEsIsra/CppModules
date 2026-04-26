#ifndef RPN_H
#define RPN_H

#pragma once

#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <exception>


class RPN
{
    private:
        std::stack<double> stack_c;

        RPN();
        RPN(const RPN &to_copy);
        RPN &operator=(const RPN &original);
        ~RPN();
        double doOperation(int c);
        
    public:
        static RPN* getInstance();  

        
        RPN(std::string &input);

        double calculateRPN(const std::string &input);
   
    class DivOnCero : public std::exception
    {
        virtual const char* what() const throw();
    };
   
    class NotEoughElements : public std::exception
    {
        virtual const char* what() const throw();
    };

    class NonDigit : public std::exception
    {
        virtual const char* what() const throw();
    };


};

#endif