// deque  y vector
#include "PmergeMe.h"
#include <iostream>
#include <cctype>
#include <cstdlib>
#include <limits>

int checkDigits(char *c)
{
    if (!*c)
        return 0;
    while (*c)
    {
        if (!std::isdigit(*c))
            return 0;
        c++;
    }
    return 1;
}

int checkArgs(char **arg)
{
    int i = 1;
    long long max_v; 
    while (arg[i])
    {
        if (!checkDigits(arg[i]))
            return 0;
        max_v = std::atol(arg[i]);
        if (max_v >= std::numeric_limits<int>::max())
            return 0;
        i++;
    }
    return 1;
}

int main(int ar, char *av[])
{
    if (ar == 1)
    {
        std::cout << "Error: No arguments" << std::endl;
        return 1;
    }
    if (!checkArgs(av))
    {
        std::cout << "Error: invalid input" << std::endl;
        return 1;
    }
    std::cout << "llega bien" << std::endl;
    //  ya no se que paso 
    
    return 0;
}
