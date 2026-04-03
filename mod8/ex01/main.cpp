#include "Span.h"


#define NUMBER_SIZE 10

int main( void )
{

    try
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        //sp.addMultipleNumbers(4);
        //sp.addMultipleNumbers(5);

        std::cout << "Container: "<< sp ;
        std::cout << std::endl;


        std::cout << "Shortest: " << sp.shortestSpan() << std::endl;

        std::cout << "Longest: " << sp.longestSpan() << std::endl;    

    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: "<< e.what() << std::endl;
    }
    

    
    return 0 ;
}
