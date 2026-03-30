

#include "easyfind.h"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

#define NUMBER_SIZE 10

int main( void )
{
    std::vector<int> v_container;
    for (int i = 0; i < NUMBER_SIZE ; i++)
    {
        v_container.push_back(i*2);
    }
    try
    {
        std::cout <<  *easyfind(v_container,2) << " --> Number found" <<std::endl;
    }
    catch(std::exception& e)
    {
        std::cerr << "Error: " <<e.what() << std::endl;
    }
    
    

    

    return 0 ;
}