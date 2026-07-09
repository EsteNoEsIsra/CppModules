#include "RPN.h"
#include <cctype>
#include <cstdlib>
#include <sstream>

RPN::RPN(){}

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

RPN RPN::getInstance()
{
    static RPN instance;
    return instance;
}

static bool isOperation(int c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return true;
    return false;
}

static double check_divsion(double a, double b)
{
    if (b == 0)
       throw RPN::DivOnCero();
    return (a / b);
}

double RPN::doOperation(int c)
{
    double b = stack_c.top();
    stack_c.pop();
    double a = stack_c.top();
    stack_c.pop();

    double aux = 0;
    switch (c)
    {
        case '+':
            return(a + b);
           break;
        case '-':
            return(a - b);
            break;
        case '*':
            return(a * b);
            break;
        case '/':
            aux = check_divsion(a , b);
            return (aux);
            break;
        default:
            return -1;
    }
}


static bool isNumberToken(const std::string &token)
{
    if (token.empty())
        return false;
    for (size_t i = 0; i < token.size(); i++)
    {
        if (!std::isdigit(static_cast<unsigned char>(token[i])))
            return false;
    }
    return true;
}

double RPN::calculateRPN(const std::string &input)
{
    double result = 0;
    std::istringstream iss(input);
    std::string token;

    while (!stack_c.empty())
        stack_c.pop();

    while (iss >> token)
    {
        if (isNumberToken(token))
        {
            this->stack_c.push(std::atof(token.c_str()));
        }
        else if (token.size() == 1 && isOperation(token[0]))
        {
            if (stack_c.size() < 2)
                throw RPN::NotEoughElements();
            double res = doOperation(token[0]);
            this->stack_c.push(res);
        }
        else
        {
            throw RPN::NonDigit();
        }
    }

    if (stack_c.size() != 1)
        throw RPN::NotEoughElements();

    result = stack_c.top();
    std::cout << "result: " << result << std::endl;
    return result;
}

const char *RPN::NonDigit::what() const throw()
{
    return "Error";
}

const char *RPN::NotEoughElements::what() const throw()
{
    return "Error not enough elements";
}

const char *RPN::DivOnCero::what() const throw()
{
    return "Error: You cant divide 0";
}