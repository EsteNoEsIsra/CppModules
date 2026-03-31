#include "Span.h"

Span::Span() : v_container(0), N(0){}

Span::Span(const Span &to_copy) : v_container(to_copy.v_container), N(to_copy.N){}

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

void Span::shortestSpan()
{

}

void Span::longestSpan()
{
    std::sort(v_container.begin(), v_container.end());
}