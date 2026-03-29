#include <iostream>
#include <string>
#include "Array.h"
#include <cstdlib>
#include <ctime>

#define MAX_VAL 5



int main()
{
    std::cout << "******************INTEGERS*************************" << std::endl;
    std::cout << "---------TEST 1 default ---------" << std::endl;
    Array<int> a;
    std::cout << "size: " << a.size() << std::endl;

    try {
        a[0];
    } catch (std::exception &e) {
        std::cout << "Exception (empty)" << std::endl;
    }


    std::cout << "---------TEST 2 Normal---------" << std::endl;
    Array<int> b(5);
    std::cout << "size: " << b.size() << std::endl;
    for (unsigned int i = 0; i < b.size(); i++)
    {
        b[i] = i * 2;
        std::cout << "content b : "<< b[i] << std::endl;
    }
    
    std::cout << "---------TEST 3 Copy ---------" << std::endl;

    Array<int> c(b);
    for (unsigned int i = 0; i < c.size(); i++)
    {
        std::cout << "content c : "<< c[i] << std::endl;
    }
    b[0] = 42;
    std::cout << "b[0]: " << b[0] << std::endl;
    std::cout << "c[0]: " << c[0] << std::endl; 


    std::cout << "---------TEST 4  = operator ---------" << std::endl;
    Array<int> d;
    d = b;

        for (unsigned int i = 0; i < d.size(); i++)
            std::cout << "d :"<< d[i] << std::endl;


    std::cout << "---------TEST 5 const ---------" << std::endl;
    const Array<int> e(b);

    for (unsigned int i = 0; i < e.size(); i++)
        std::cout << e[i] << std::endl;

    std::cout << "---------TEST 6 execption ---------" << std::endl;
    try
    {
        std::cout << b[100] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Error : " << e.what() << std::endl;
    }
    
    std::cout << "---------TEST 7 ---------" << std::endl;
 

    Array<int> big(100000);
    big[99999] = 424242;
    std::cout << big[99999] << std::endl;

    std::cout << "******************STRINGS*************************" << std::endl;
  

    std::cout << "---------TEST 1 ---------" << std::endl;
    Array<std::string> a_str(MAX_VAL);

    for (int i = 0; i < MAX_VAL; i++)
    {
        a_str[i] = "Hola" ; 
        std::cout << a_str[i] << std::endl;
    }
    std::cout << "---------TEST 2 Copy ---------" << std::endl;
    Array<std::string> b_str(a_str);

    a_str[0] = "MODIFIED";

    std::cout << "a_str[0]: " << a_str[0] << std::endl;
    std::cout << "b_str[0]: " << b_str[0] << std::endl;
   

    std::cout << "---------TEST 3 = operator ---------" << std::endl;
    Array<std::string> c_str;
    c_str = a_str;

    a_str[1] = "CHANGED";

    std::cout << "a_str[1]: " << a_str[1] << std::endl;
    std::cout << "c_str[1]: " << c_str[1] << std::endl;
   
    std::cout << "---------TEST 4 const ---------" << std::endl;
    const Array<std::string> d_str(a_str);

    for (unsigned int i = 0; i < d_str.size(); i++)
        std::cout << d_str[i] << std::endl;
    
    
    std::cout << "---------TEST 5 modify element ---------" << std::endl;
    a_str[2][0] = 'X'; 
    std::cout << "a_str[2]: " << a_str[2] << std::endl;
  

    std::cout << "---------TEST 6 execption ---------" << std::endl;
    
    
    try {
        std::cout << a_str[100] << std::endl;
    } 
    catch (std::exception &e)
    {
        std::cout << "Error : " << e.what() << std::endl;
    }

    
    std::cout << "---------TEST 7 empty ---------" << std::endl;
    Array<std::string> empty;

    try {
        empty[0];
    } 
    catch (std::exception &e)
    {
        std::cout << "Exception (empty)" << std::endl;
    }

    std::cout << "---------TEST 8 ---------" << std::endl;
    
    Array<std::string> complex(3);

    complex[0] = "Its me Mario";
    complex[1] = "Despues voy a ver que se me ha roto  por tocar donde no debia";
    complex[2] = "Tengo hambre";

    Array<std::string> copy(complex);

    complex[1] = "CAMBIADO";

    std::cout << "Original: " << complex[1] << std::endl;
    std::cout << "Copy:     " << copy[1] << std::endl;
    
    return 0;
}










/*
int main()
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}
*/