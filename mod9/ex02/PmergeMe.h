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
#include <algorithm>


class PmergeMe
{
    private:
        std::vector<int> _v_con;
        std::deque<int> _de_con;

        bool hasleftover;
        int leftover;
        
        std::vector<std::pair<int, int> >pairlist;

        std::vector<int> mainChain;
        std::vector<int> pend;

        PmergeMe();
    public:
        
        PmergeMe(const PmergeMe &to_copy);
        PmergeMe &operator=(const PmergeMe& original);
        ~PmergeMe();

        PmergeMe(int ar);

        void setVecContainer(int n);
        void setDeqContainer(int n);

        std::vector<int>& getVecContainer();
        std::deque<int>& getDeqContainer();

        void printContainer_vec(std::vector<int> vec);
        void printContainer_deq(std::deque<int> deq);

        void makePairs(char** argv, int ar);
        void buildMain();
        void insertPend();
        void mergeInsertFJ(std::vector<std::pair<int, int> >&pairs);
        void makeFordJonson(char** argv, int ar);
};

#endif