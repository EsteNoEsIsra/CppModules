#ifndef PMERGEME_H
#define PMERGEME_H
#include <iostream>
#include <vector>
#include <deque>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <iomanip>


class PmergeMe
{
    private:
        std::vector<int> _v_con;
        std::deque<int> _de_con;

        std::vector<std::pair<int, int>> pairlist;
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &to_copy);
        PmergeMe &operator=(const PmergeMe& original);
        ~PmergeMe();

        PmergeMe(char** argv, int ar);

        void setVecContainer(int n);
        void setDeqContainer(int n);

        std::vector<int>& getVecContainer();
        std::deque<int>& getDeqContainer();

        void printContainer_vec(std::vector<int> vec);
        void printContainer_deq(std::deque<int> deq);

        void makePairs(char** argv, int ar);

};

#endif