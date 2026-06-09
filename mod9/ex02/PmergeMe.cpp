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

PmergeMe::PmergeMe(int ar)
{
   
    if (((ar - 1 ) % 2 )== 0)
        hasleftover = false;
    else 
        hasleftover = true;

    
}

void PmergeMe::makeFordJonson(char** argv, int ar)
{
    makePairs(argv, ar);
    mergeInsertFJ(pairlist); // primero ordenar los pares recursivamente
    buildMain();             // luego construir mainChain con el orden correcto
    insertPend();
    // std::sort(mainChain.begin(),mainChain.end());
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

static std::vector<int> jhOrder(int n)
{
    // Genera los números de Jacobsthal hasta superar n
    std::vector<int> jac;
    jac.push_back(0);
    jac.push_back(1);
    while (true)
    {
        int next = jac[jac.size() - 1] + 2 * jac[jac.size() - 2];
        if (next > n)
            break;
        jac.push_back(next);
    }

    // Construir el orden de inserción usando Jacobsthal
    std::vector<int> order;
    std::vector<bool> inserted(n + 1, false);

    for (size_t k = 2; k < jac.size(); k++)
    {
        // Insertar desde jac[k] hasta jac[k-1]+1, de mayor a menor
        for (int idx = jac[k]; idx > jac[k - 1]; idx--)
        {
            if (idx <= n)
            {
                order.push_back(idx - 1); // índice base 0
                inserted[idx - 1] = true;
            }
        }
    }
    // Los que sobren (si los hubiera)
    for (int i = 0; i < n; i++)
        if (!inserted[i])
            order.push_back(i);

    return order;
}

void PmergeMe::insertPend()
{
    if (pend.empty())
        return;

    // pend[0] siempre va al inicio (su par mayor es el menor de mainChain)
    mainChain.insert(mainChain.begin(), pend[0]);

    if (pend.size() == 1)
    {
        if (hasleftover)
        {
            std::vector<int>::iterator pos =
                std::lower_bound(mainChain.begin(), mainChain.end(), leftover);
            mainChain.insert(pos, leftover);
        }
        return;
    }

    std::vector<int> order = jhOrder(pend.size());

    for (size_t i = 0; i < order.size(); i++)
    {
        int idx = order[i];
        if (idx == 0)  // ya insertado
            continue;

        int val = pend[idx];

        // El límite del binary search es la posición del par mayor en mainChain
        // pairlist[idx].first es el mayor que corresponde a pend[idx]
        std::vector<int>::iterator bound =
            std::find(mainChain.begin(), mainChain.end(), pairlist[idx].first);

        std::vector<int>::iterator pos =
            std::lower_bound(mainChain.begin(), bound, val);
        mainChain.insert(pos, val);
    }
    if (hasleftover)
    {
        std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), leftover);
        mainChain.insert(pos, leftover);
    }
}
void PmergeMe::mergeInsertFJ(std::vector<std::pair<int, int> >&pairs)
{
    if (pairs.size() <= 1)
        return;
    // Extraer solo los mayores para ordenarlos recursivamente
    std::vector<std::pair<int, int> > subPairs;
    for (size_t i = 0; i + 1 < pairs.size(); i += 2)
    {
        int a = pairs[i].first;
        int b = pairs[i + 1].first; 
        if (a < b)
            std::swap(pairs[i], pairs[i + 1]);
        subPairs.push_back(std::make_pair(pairs[i].first, pairs[i + 1].first));
    }
    mergeInsertFJ(subPairs);
    // Reordenar pairlist según el orden resultante de los mayores
    std::vector<std::pair<int, int> > sorted;
    for (size_t i = 0; i < subPairs.size(); i++)
    {
        for (size_t j = 0; j < pairs.size(); j++)
        {
            if (pairs[j].first == subPairs[i].first)
            {
                sorted.push_back(pairs[j]);
                pairs.erase(pairs.begin() + j);
                break;
            }
        }
    }
    pairs = sorted;
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
