#include "Bureaucrat.h"

int main(void)
{
    try
    {
        Bureaucrat b("Mariano", 5);
        std::cout << b << std::endl;
        
    }
    catch(std::exception &e)
    {
        std::cerr << RED << "Error: " << e.what() << RESET <<std::endl;
    }

    try
    {
        Bureaucrat b("Juan", 151);
        std::cout << b << std::endl;
        
    }
    catch(std::exception &e)
    {
        std::cerr << RED << "Error: " << e.what() << RESET <<std::endl;
    }


    try
    {
        Bureaucrat b("Juan", -1);
        std::cout << b << std::endl;
        
    }
    catch(std::exception &e)
    {
        std::cerr << RED << "Error: " << e.what() << RESET <<std::endl;
    }
    
    return 0;
}