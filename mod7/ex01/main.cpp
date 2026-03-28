#include "iter.h"

template<typename T>
void printT(T &n)
{
    std::cout << n << std::endl;
}

template<typename T>
void printT(const T &n)
{
    std::cout << n << std::endl;
}

void dupvalue(int &n)
{
    n = n * 2;
}


int main( void ) 
{
    int arrint[] = {1,2,3,4,5};
    std::cout << "normal int " << std::endl;
    iter(arrint, 5, printT<int>);

    iter(arrint, 5, dupvalue);
    std::cout << "Dup int " << std::endl;
    iter(arrint, 5, printT<int>);


    std::cout << "normal string  " << std::endl;
    std::string arrStr [] = {"Pez","Leon","Jo"};

    iter(arrStr, 3 , printT<std::string>);


    std::cout << "const  int " << std::endl;
    const int c_arrInt [] = {21, 42 , 6};
    iter(c_arrInt, 3 , printT<int>);

    return 0;
}