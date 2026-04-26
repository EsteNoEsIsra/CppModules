#include "RPN.h"

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
    /*
   
*/
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


static bool isCorrectString(const std::string &in)
{
    if (!std::isdigit(in[0]))
        return false;
    for (size_t i = 1; i < in.size(); i++)
    {
        if (i % 2 != 0)
        {
            if (!std::isdigit(in[i]))
                return false;
        }
        else if (i % 2 == 0)
        {
            if (!isOperation(in[i]))
                return false;
        }
    }           
    return true;
}

double RPN::calculateRPN(const std::string &input)
{
    double result = 0;
    double num;
    if (input.size() < 3)
        throw RPN::NotEoughElements();
    if (!isCorrectString(input))
        throw RPN::NonDigit();

    for (size_t i = 0; i < input.size(); i++)
    {
        if (std::isdigit(input[i]))
        {
            num = input[i] - '0';
            this->stack_c.push(num);
        }
        else if (isOperation(input[i]) && stack_c.size() > 1)
        {
            double res = doOperation(input[i]);
            this->stack_c.push(res);
        }
        else
        {
            std::cout << "debug No deberia llegar aqui"<< std::endl;
        }
    }
    if (stack_c.size() == 1)
    {
        result = stack_c.top();
         std::cout << "result: "<< result<< std::endl; 
    }  
    else
        std::cout << "result: "<< result<< std::endl;
        
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