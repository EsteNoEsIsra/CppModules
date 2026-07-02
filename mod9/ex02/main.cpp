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
    for (int i = 1; i < ar; ++i)
    {
        int value = std::atoi(av[i]);
        pme.setVecContainer(value);
        pme.setDeqContainer(value);
    }

    std::cout << "---------------- unsorted vector-------------------" <<std::endl;   
    pme.printContainer_vec(pme.getVecContainer());
    clock_t init_time_vec = clock();
    pme.makeFordJonson(pme.VECTOR);
    clock_t final_time_vec = clock();
    std::cout << "---------------- sorted vector-------------------" <<std::endl;
    pme.printContainer_vec(pme.getVecContainer());
    
    std::cout << "---------------- unsorted deque-------------------" <<std::endl;   
    pme.printContainer_deq(pme.getDeqContainer());
    clock_t init_time_deq = clock();
    pme.makeFordJonson(pme.DEQUE);
    clock_t final_time_deq = clock();  

    std::cout << "---------------- sorted deque-------------------" <<std::endl;
    pme.printContainer_deq(pme.getDeqContainer());
    //tiempo
    double sec_vec = double(final_time_vec - init_time_vec) / CLOCKS_PER_SEC;
    std::cout << "***VECTOR*** \n  Sort of " << (ar - 1) << " elements in " << std::fixed << std::setprecision(5) <<  sec_vec << " us"<<std::endl;

    double sec_deq = double(final_time_deq - init_time_deq) / CLOCKS_PER_SEC;
    std::cout << "***DEQUE*** \n Sort of " << (ar - 1) << " elements in " << std::fixed << std::setprecision(5) <<  sec_deq << " us"<<std::endl;


    return 0;
}
 