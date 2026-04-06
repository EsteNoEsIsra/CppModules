#include "RPN.h"

RPN::RPN(){}//privado :D 

RPN::RPN(const RPN &to_copy){ *this = to_copy;}

RPN &RPN::operator=(const RPN &original)
{
    if (this != &original)
    {   
        stack_c = original.stack_c;
    }
    return *this;
}

RPN::~RPN(){}

RPN::RPN(std::string &input){}

double calculateRPN(const std::string &input)
{
 //   return result;
}