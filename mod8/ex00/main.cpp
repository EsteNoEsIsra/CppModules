#include "easyfind.h"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

#define NUMBER_SIZE 10

int main( void )
{
    /////////////////////////////////Vector
    std::vector<int> v_container;
    for (int i = 0; i < NUMBER_SIZE ; i++)
    {
        v_container.push_back(i*2);
    }
    std::cout << "vector container : " ;
    for ( unsigned long int  i = 0; i < v_container.size(); i++)
        std::cout << v_container[i] <<" " ;
    std::cout << " " << std::endl;
    try
    {
        std::cout <<  *easyfind(v_container,2) << " --> Number found" <<std::endl;
    }
    catch(std::exception& e)
    {
        std::cerr << "Error: " <<e.what() << std::endl;
    }

    /////////////////////////////////list
    std::list<int> l_container;
    for (int i = 0; i < NUMBER_SIZE ; i++)
    {
        l_container.push_back(i);
    }
       std::cout << "List container : " ;
    for ( std::list<int>::iterator it = l_container.begin(); it != l_container.end(); ++it)
        std::cout << *it <<" " ;
    std::cout << " " << std::endl;
    try
    {
        std::cout <<  *easyfind(l_container,2) << " --> Number found" <<std::endl;
    }
    catch(std::exception& e)
    {
        std::cerr << "Error: " <<e.what() << std::endl;
    }
    
    /////////////////////////////////list
    std::deque<int> d_container;
    for (int i = 0; i < NUMBER_SIZE ; i++)
    {
        d_container.push_back(i*5);
    }
       std::cout << "Deque container : " ;
    for ( unsigned long int  i = 0; i < v_container.size(); i++)
        std::cout << d_container[i] <<" " ;
    std::cout << " " << std::endl;
    try
    {
        std::cout <<  *easyfind(d_container,87) << " --> Number found" <<std::endl;
    }
    catch(std::exception& e)
    {
        std::cerr << "Error: " <<e.what() << std::endl;
    }
    return 0 ;
}
