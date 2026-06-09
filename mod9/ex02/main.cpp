// deque  y vector
#include "PmergeMe.h"

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

int main(int ar, char **av)
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
    PmergeMe pme(ar);
    std::cout << "---------------- unsorted-------------------" <<std::endl;   
    pme.printContainer_vec(pme.getVecContainer());

    clock_t init_time_vec = clock();
    pme.makeFordJonson(av,ar);

    // pme.printContainer_deq(pme.getDeqContainer());
    

    


    std::cout << "---------------- sorted-------------------" <<std::endl;


    clock_t final_time_vec = clock();
    pme.printContainer_vec(pme.getVecContainer());
    //tiempo
    double sec = double(final_time_vec - init_time_vec) / CLOCKS_PER_SEC;
   // double microsec = sec * 1000000.0;
    std::cout << "Sort of " << (ar - 1) << " elements in " << std::fixed << std::setprecision(5) <<  sec << " us"<<std::endl;
    return 0;
}
 