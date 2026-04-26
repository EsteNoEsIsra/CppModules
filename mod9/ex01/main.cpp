#include "RPN.h"

int main(int argc, char **argv)
{
    try
    {
        if (argc != 2)
        {
            std::cout << "Error: Invalid number of arguments "<<std::endl; 
            return 1;
        }
        std::string input_s(argv[1]);
        input_s.erase(std::remove(input_s.begin(),input_s.end(), ' '),input_s.end());
        RPN rpn = RPN::getInstance();
        rpn.calculateRPN(input_s);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
