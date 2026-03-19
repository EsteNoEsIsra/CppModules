#include "Bureaucrat.h"
#include "Form.h"
int main(void)
{
    
    std::cout << "\n===== TEST 1 =====" << std::endl;
    try
    {
        
        Bureaucrat b("Mariano", 2);
        Form f("mates", 21 , 32);
        std::cout << b << std::endl;
        std::cout << f << std::endl;
        b.signForm(f);
        std::cout << f << std::endl;
    }
    catch(std::exception &e)
    {
        std::cerr << RED << "Error: " << e.what() << RESET <<std::endl;
    }
    
    std::cout << "\n===== TEST 1.5 =====" << std::endl;
    try
    {
        
        Bureaucrat b("Mariano", 2);
        Form f("mates", 21 , 32);
        std::cout << b << std::endl;
        std::cout << f << std::endl;
        b.signForm(f);
        b.signForm(f);
        std::cout << f << std::endl;
    }
    catch(std::exception &e)
    {
        std::cerr << RED << "Error: " << e.what() << RESET <<std::endl;
    }
    

    // Falla 
    std::cout << "\n===== TEST 2 =====" << std::endl;
    try
    {
        Bureaucrat b2("Mariano2", 100);
        Form f2("gym", 50, 10);

        std::cout << b2 << std::endl;
        std::cout << f2 << std::endl;

        b2.signForm(f2);
    }
    catch (std::exception &e)
    {
        std::cerr << RED << "Error: " << e.what() << RESET <<std::endl;
    }

    // error  
    std::cout << "\n===== TEST 3 =====" << std::endl;
    try
    {
        Form f3("InvalidHigh", 0, 10);
    }
    catch (std::exception &e)
    {
        std::cerr << RED << "Error: " << e.what() << RESET <<std::endl;
    }

    std::cout << "\n===== TEST 4 =====" << std::endl;
    try
    {
        Form f4("InvalidLow", 200, 10);
    }
    catch (std::exception &e)
    {
        std::cerr << RED << "Error: " << e.what() << RESET <<std::endl;
    }

    // Error 
    std::cout << "\n===== TEST 5 =====" << std::endl;
    try
    {
        Bureaucrat b3("ErrorGuy", 0);
    }
    catch (std::exception &e)
    {
       std::cerr << RED << "Error: " << e.what() << RESET <<std::endl;
    }

    return 0;
}