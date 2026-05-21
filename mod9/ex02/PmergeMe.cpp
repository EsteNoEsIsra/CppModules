#include "PmergeMe.h"

PmergeMe::PmergeMe(): _v_con(0), _de_con(0){}

PmergeMe::PmergeMe(const PmergeMe &to_copy){ *this = to_copy;}
PmergeMe& PmergeMe::operator=(const PmergeMe& original)
{
    if (this != &original)
    {
        this->_de_con = original._de_con;
        this->_v_con = original._v_con;
    }
    return *this;
}

PmergeMe::~PmergeMe()
{}

PmergeMe::PmergeMe(char** argv, int ar)
{
    
    for (int i = 1; i < ar ; i++)
    {
        
    }
    
}


void PmergeMe::setVecContainer(int n)
{
    this->_v_con.push_back(n);
}
void PmergeMe::setDeqContainer(int n)
{
    this->_de_con.push_back(n);
}
std::vector<int>& PmergeMe::getVecContainer()
{
    return this->_v_con;
}
std::deque<int>& PmergeMe::getDeqContainer()
{
    return this->_de_con;
}