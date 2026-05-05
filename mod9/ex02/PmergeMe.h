#pragma once

#include <iostream>


class PmergeMe
{
    private:

    public:
        PmergeMe();
        PmergeMe(const PmergeMe &to_copy);
        PmergeMe &operator=(const PmergeMe& original);
        ~PmergeMe();
};