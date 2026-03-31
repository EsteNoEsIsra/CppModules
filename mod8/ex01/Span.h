#ifndef SPAN_H
#define SPAN_H

#include <deque>
#include <list>
#include <vector>
#include <iostream>
#include <exception>
#include <cstdlib>
#include <ctime>
#include <algorithm>

#pragma once

class Span
{
    private:
        std::vector<int> v_container;
        unsigned int N;
    public:
        Span();
        Span(const Span &to_copy);
        Span&operator=(const Span &original);
        ~Span();

        Span(unsigned int _n);

        void addNumber(int nbr);

        void addMultipleNumbers(int max);

        void shortestSpan();
        void longestSpan();

    class NoAddingOutofClass : public std::exception
    {
        virtual const char *what() throw()
        {
            return "You cant add Outside of the class";
        }
    };

};

#endif