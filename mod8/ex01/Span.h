#ifndef SPAN_H
# define SPAN_H

# include <vector>
# include <ostream>
# include <iostream>
# include <exception>
# include <cstdlib>
# include <ctime>
# include <algorithm>
 
# pragma once

class Span
{
    private:
        std::vector<int> v_container;
        unsigned int N;

        Span();
    public:
     
        Span(const Span &to_copy);
        Span&operator=(const Span &original);
        ~Span();

        Span(unsigned int _n);

        void addNumber(int nbr);
        void addNumber(std::vector<int>::iterator _begin, std::vector<int>::iterator _end);

        void addMultipleNumbers(int max);

        unsigned int shortestSpan();
        unsigned int longestSpan();

        const std::vector<int> getContainer() const ;

        

    class Fullcontainer : public std::exception
    {
        virtual const char *what() const throw()
        {
            return "The container is full";
        }
    };

      class EmptyContainer : public std::exception
    {
        virtual const char *what() const throw()
        {
            return "Cannot operate a empty container";
        }
    };
      class NotEnoughElements : public std::exception
    {
        virtual const char *what() const throw()
        {
            return "Not Enough Elements to operate";
        }
    };

};

    std::ostream &operator<<(std::ostream &os, const Span &og);

#endif