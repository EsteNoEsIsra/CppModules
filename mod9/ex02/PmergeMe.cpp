#include "PmergeMe.h"

static std::vector<size_t> buildJacobsthalOrder(size_t count)
{
    std::vector<size_t> order;
    if (count == 0)
        return order;

    std::vector<size_t> jacobsthal;
    jacobsthal.push_back(1);
    jacobsthal.push_back(1);
    while (jacobsthal[jacobsthal.size() - 1] < count)
    {
        size_t next = jacobsthal[jacobsthal.size() - 1]  + 2 * jacobsthal[jacobsthal.size() - 2];
        jacobsthal.push_back(next);
    }

    std::vector<bool> used(count, false);
    size_t previous = 0;
    for (size_t i = 2; i < jacobsthal.size(); ++i)
    {
        size_t end = jacobsthal[i];
        if (end > count)
            end = count;

        for (size_t current = end; current > previous; --current)
        {
            size_t index = current - 1;
            if (!used[index])
            {
                order.push_back(index);
                used[index] = true;
            }
        }
        previous = jacobsthal[i];
    }
    for (size_t i = 0; i < count; ++i)
    {
        if (!used[i])
            order.push_back(i);
    }
    return order;
}

static std::deque<size_t> buildJacobsthalOrderdeque(size_t count)
{
    std::deque<size_t> order;
    if (count == 0)
        return order;

    std::deque<size_t> jacobsthal;
    jacobsthal.push_back(1);
    jacobsthal.push_back(1);
    while (jacobsthal[jacobsthal.size() - 1] < count)
    {
        size_t next = jacobsthal[jacobsthal.size() - 1]  + 2 * jacobsthal[jacobsthal.size() - 2];
        jacobsthal.push_back(next);
    }

    std::deque<bool> used(count, false);
    size_t previous = 0;
    for (size_t i = 2; i < jacobsthal.size(); ++i)
    {
        size_t end = jacobsthal[i];
        if (end > count)
            end = count;

        for (size_t current = end; current > previous; --current)
        {
            size_t index = current - 1;
            if (!used[index])
            {
                order.push_back(index);
                used[index] = true;
            }
        }
        previous = jacobsthal[i];
    }
    for (size_t i = 0; i < count; ++i)
    {
        if (!used[i])
            order.push_back(i);
    }
    return order;
}

static void fordJohnsonSort(std::vector<int> &container)
{
    if (container.size() < 2)
        return;

    typedef typename std::vector<int>::value_type value_type;
    std::vector<value_type> majors;
    std::vector<value_type> minors;
    value_type leftover = value_type();
    bool hasLeftover = false;

    typename std::vector<int>::const_iterator it = container.begin();
    while (it != container.end())
    {
        value_type first = *it;
        ++it;
        if (it == container.end())
        {
            leftover = first;
            hasLeftover = true;
            break;
        }

        value_type second = *it;
        ++it;
        if (first < second)
            std::swap(first, second);

        majors.push_back(first);
        minors.push_back(second);
    }

    fordJohnsonSort(majors);

    container.clear();
    container.insert(container.end(), majors.begin(), majors.end());

    std::vector<size_t> order = buildJacobsthalOrder(minors.size());
    for (size_t i = 0; i < order.size(); ++i)
    {
        value_type value = minors[order[i]];
        typename std::vector<int>::iterator pos = std::lower_bound(container.begin(), container.end(), value);
        container.insert(pos, value);
    }

    if (hasLeftover)
    {
        typename std::vector<int>::iterator pos = std::lower_bound(container.begin(), container.end(), leftover);
        container.insert(pos, leftover);
    }
}


static void fordJohnsonSort_deq(std::deque<int> &container)
{
    if (container.size() < 2)
        return;

    typedef typename std::deque<int>::value_type value_type;
    std::deque<value_type> majors;
    std::deque<value_type> minors;
    value_type leftover = value_type();
    bool hasLeftover = false;

    typename std::deque<int>::const_iterator it = container.begin();
    while (it != container.end())
    {
        value_type first = *it;
        ++it;
        if (it == container.end())
        {
            leftover = first;
            hasLeftover = true;
            break;
        }

        value_type second = *it;
        ++it;
        if (first < second)
            std::swap(first, second);

        majors.push_back(first);
        minors.push_back(second);
    }

    fordJohnsonSort_deq(majors);

    container.clear();
    container.insert(container.end(), majors.begin(), majors.end());

    std::deque<size_t> order = buildJacobsthalOrderdeque(minors.size());
    for (size_t i = 0; i < order.size(); ++i)
    {
        value_type value = minors[order[i]];
        typename std::deque<int>::iterator pos = std::lower_bound(container.begin(), container.end(), value);
        container.insert(pos, value);
    }

    if (hasLeftover)
    {
        typename std::deque<int>::iterator pos = std::lower_bound(container.begin(), container.end(), leftover);
        container.insert(pos, leftover);
    }
}



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

PmergeMe::PmergeMe(int ar)
{
   
    if (((ar - 1 ) % 2 )== 0)
        hasleftover = false;
    else 
        hasleftover = true;
}

void PmergeMe::makeFordJonson(int container)
{
    if (container == VECTOR)
        fordJohnsonSort(_v_con);
    else if (container == DEQUE)
        fordJohnsonSort_deq(_de_con);
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
    mainChain.clear();
    pend.clear();

    for (size_t i = 0; i < pairlist.size(); i++)
    {
        mainChain.push_back(pairlist[i].first);
        pend.push_back(pairlist[i].second);
    }
   
}   

void PmergeMe::insertPend()
{
    if (pend.empty() || mainChain.empty())
        return;

    for (size_t i = 0; i < pend.size(); ++i)
    {
        std::vector<int>::iterator pos =
            std::lower_bound(mainChain.begin(), mainChain.end(), pend[i]);
        mainChain.insert(pos, pend[i]);
    }

    if (hasleftover)
    {
        std::vector<int>::iterator pos =
            std::lower_bound(mainChain.begin(), mainChain.end(), leftover);
        mainChain.insert(pos, leftover);
    }
}
void PmergeMe::mergeInsertFJ(std::vector<std::pair<int, int> >&pairs)
{
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        for (size_t j = i + 1; j < pairs.size(); ++j)
        {
            if (pairs[j].first < pairs[i].first)
                std::swap(pairs[i], pairs[j]);
        }
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
