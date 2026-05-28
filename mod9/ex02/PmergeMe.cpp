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


PmergeMe::PmergeMe(char** argv, int ar)
{
    
    // for (int i = 1; i < ar ; i++ )
    // {
    //     int val = std::atoi(argv[i]);  
    //     setDeqContainer(val);
    //     setVecContainer(val);
    // }

    makePairs(argv, ar);
}

void PmergeMe::makePairs(char** argv, int ar)
{
    if ((ar -1) % 2 == 0)

    for (int i = 1; i < ar ; i += 2)
    {
        int val = std::atoi(argv[i]);
        int val2 = std::atoi(argv[i+1]);
        if (i + 1 < ar)
            pairlist.push_back(std::make_pair(val,val2));
    }
    //arreglar
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
void PmergeMe::printContainer_vec(std::vector<int> vec)
{
    std::vector<int>::iterator it = vec.begin();
    std::cout << "Vector: " ;
    for (; it != vec.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

}

void PmergeMe::printContainer_deq(std::deque<int> deq)
{
     std::deque<int>::iterator it = deq.begin();
    std::cout << "Deque: " ;
    for (; it != deq.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
PmergeMe::~PmergeMe()
{}
