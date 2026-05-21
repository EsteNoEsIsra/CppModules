#pragma once 
#include <iostream>
#include <vector>
#include <deque>
class PmergeMe
{
    private:
        std::vector<int> _v_con;
        std::deque<int> _de_con;
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

};