#include "ScalarConverter.h"

int main( int ar, char **av)
{
    if (ar == 2)
    {
        std::string str(av[1]);
        ScalarConverter::convert(str);
    }
    else 
        std::cout << "Must have 1 arg" << std::endl;
    
    return 0;
}