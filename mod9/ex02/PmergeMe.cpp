#include "PmergeMe.h"

PmergeMe::PmergeMe(): hasleftover(false), leftover(0){}

PmergeMe::PmergeMe(const PmergeMe &to_copy){ *this = to_copy;}
PmergeMe& PmergeMe::operator=(const PmergeMe& original)
{
    if (this != &original)
    {
        this->_de_con = original._de_con;
        this->_v_con = original._v_con;
        this->hasleftover = original.hasleftover;
        this->leftover = original.leftover;
        this->pairlist = original.pairlist;
        this->mainChain = original.mainChain;
        this->pend = original.pend;
    }
    return *this;
}

PmergeMe::PmergeMe(char** argv, int ar)
{
   
    if (((ar - 1 ) % 2 )== 0)
        hasleftover = false;
    else 
        hasleftover = true;
    
    makePairs(argv, ar);
    buildMain();
    
    mergeInsertFJ(pairlist);
    std::sort(mainChain.begin(),mainChain.end());
    insertPend();
    printContainer_vec(mainChain);
}

void PmergeMe::makePairs(char** argv, int ar)
{
    int i = 1;
    while ((i + 1) < ar)
    {
        int a = std::atoi(argv[i]);
        int b = std::atoi(argv[i + 1]);

        if (a < b)
            std::swap(a, b);
        pairlist.push_back(std::make_pair(a, b));

        i += 2;
    }
    if (i < ar)
        leftover = std::atoi(argv[i]);
}

void PmergeMe::buildMain()
{
    
    for (size_t i = 0; i < pairlist.size(); i++)
    {
        mainChain.push_back(pairlist[i].first);
        pend.push_back(pairlist[i].second);
    }
   
}   

void PmergeMe::insertPend()
{
    std::vector<int>::iterator pos;
    mainChain.insert(mainChain.begin(), pend[0]);
    for (size_t i = 1; i < pend.size(); i++)
    {
        pos = std::lower_bound(mainChain.begin(), mainChain.end(), pend[i]);
        mainChain.insert(pos, pend[i]);
    }
    if (hasleftover)
    {
        pos = std::lower_bound(mainChain.begin(), mainChain.end(), leftover);
        mainChain.insert(pos, leftover);
    }
}
void PmergeMe::mergeInsertFJ(std::vector<std::pair<int, int> >&pair)
{

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
