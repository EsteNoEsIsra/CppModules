#ifndef MUTANTSTACK_H
#define MUTANTSTACK_H


# include <stack>
# include <iostream>

#pragma once
template <typename T>

class MutantStack : public std::stack<T>
{
    public:
        MutantStack();
        MutantStack(MutantStack const &to_copy);
        MutantStack &operator=(MutantStack const &original);
        ~MutantStack();


        typedef typename std::stack<T>::container_type::iterator iterator;

        typedef typename std::stack<T>::container_type::const_iterator const_iterator;

        typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
        
        typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

        iterator begin();
        iterator end();

        const_iterator begin() const;
        const_iterator end() const;

        reverse_iterator rbegin();
        reverse_iterator rend();

        const_reverse_iterator rbegin() const;
        const_reverse_iterator rend() const;

    private:

};

#include "MutantStack.tpp"

#endif