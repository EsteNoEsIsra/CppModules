#ifndef ARRAY_H
#define ARRAY_H

#pragma once
#include <iostream>
#include <exception>

template <typename T>
class Array
{
    private:
        T *arrData;
        unsigned int arrSize
    public:
        Array();
        Array(const Array *to_copy);
        Array &operator=(const Array &original);
        ~Array();

        Array(unsigned int n);

        
        T &operator[](unsigned int n);
        const T &operator[](unsigned int n) const;

    class LimitsExceptions : public std::Exception 
    {
        public: 
            virtual const char * what() const throw();
    }
};

#endif