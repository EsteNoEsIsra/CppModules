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
    this->v_container.push_back(nbr);
}
void Span::addMultipleNumbers(int max)
{
    srand(time(0));
    for (int i = 0; i < max; i++)
    {
        int a = rand() % 1000000;
        addNumber(a);    
    }
}

unsigned int Span::shortestSpan()
{

    return 0;
}

unsigned int Span::longestSpan()
{
    if (v_container.size() < 2)
        throw NoAddingOutofClass();


  
    
    std::cout << "sin ordenar: ";
    for (unsigned long i = 0; i < v_container.size(); i++)
    {
        std::cout << v_container[i]<< " ";
    }
    std::cout << std::endl;
    std::sort(v_container.begin(), v_container.end());
    
    
    std::cout << "ordenado: ";
    for (unsigned long i = 0; i < v_container.size(); i++)
    {
        std::cout << v_container[i]<< " ";
    }
    std::cout << std::endl;

    std::cout << "LOOOONNNNG: '" << v_container[v_container.size()-1] - v_container[0]   <<"'" << std::endl ;

    return (*v_container.end() - *v_container.begin());
}