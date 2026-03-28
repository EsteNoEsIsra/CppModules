#pragma once 

#include <iostream>

template<typename T>
void iter(T *array , int len,  void (*func)(T&))
{
    
    for (int i = 0; i < len; i++)
    {
        func(array[i]);
    }
    
}

template<typename T>
void iter(const T *array , int len,  void (*func)(const T&))
{
    for (int i = 0; i < len; i++)
    {
        func(array[i]);
    }
    
}