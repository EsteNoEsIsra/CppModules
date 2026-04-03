#include "Span.h"

Span::Span() : v_container(0), N(0){}

Span::Span(const Span &to_copy) : v_container(to_copy.v_container), N(to_copy.N){}

Span::Span(unsigned int _n) : N(_n)
{

}
Span& Span::operator=(const Span &original)
{
    if (this != &original)
    {   
        this->v_container = original.v_container;
        this->N = original.N;
    }
    return *this;
}

Span::~Span(){}

void Span::addNumber(int nbr)
{
    if (v_container.size() >= N)
    {
        throw Fullcontainer();
    }   
    this->v_container.push_back(nbr);
}

void Span::addNumber(std::vector<int>::iterator _begin, std::vector<int>::iterator _end)
{
    srand(time(0));
    if (std::distance(_begin,_end) + v_container.size() >= N)
        throw Fullcontainer() ;
    else 
    {
        for (std::vector<int>::iterator it = _begin; it != _end; ++it)
        {
            v_container.insert(v_container.end(), 1 , rand() % 100);
        }
    }
    
}

void Span::addMultipleNumbers(int max)
{
    srand(time(0));
    int jump = 0;
    if (max < 10)
        jump = 50;

    for (int i = 0; i < max; i++)
    {
        int a = rand() % max + jump;
        addNumber(a);    
    }
}

unsigned int Span::shortestSpan()
{
    if ( v_container.size() < 2 )
        throw NotEnoughElements();
    unsigned int  min = Span::longestSpan();
    std::sort(v_container.begin(), v_container.end());

    std::vector<int>::iterator it1 = v_container.begin();
    std::vector<int>::iterator it2 = v_container.begin() + 1;
        
    while (it1 != v_container.end())
    {
        if (*it1 != *it2)
        {
            int tmp = std::abs(*it2 - *it1);    
            if( tmp < static_cast<int>(min))
                min = tmp;
        }
        ++it1;
        ++it2;
    }
    return min;
}

const std::vector<int> Span::getContainer() const 
{
    return (v_container);
}

unsigned int Span::longestSpan()
{
    if (v_container.size() < 2)
        throw NotEnoughElements();
      
    std::sort(v_container.begin(), v_container.end());
    int firts = *v_container.begin();
    int last = *(v_container.end()-1);

    return (last - firts);
}



std::ostream &operator<<(std::ostream &os, const Span &og)
{
    std::vector<int> a = og.getContainer();
    for (unsigned long i = 0; i < a.size(); i++)
    {
        os <<  a[i] << " ";
    }
    
    return os;
    
}
