#include "Base.h"
#include "A.h"
#include "B.h"
#include "C.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base * generate(void)
{
    int i = rand() % 3;
    if (i == 0)
        return new A;
    if (i == 1)
        return new B;
    return new C;    
}


void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
		std::cout << "ptr A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "ptr B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "ptr C" << std::endl;

}
void identify(Base& p)
{
    try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "ref A" << std::endl;
	}
	catch (std::exception &e) {}
	try
	{
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "ref B" << std::endl;
	}
	catch (std::exception &e) {}
	try
	{
		C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "ref C" << std::endl;
	}
	catch (std::exception &e) {}

}

int main()
{
    srand(time(0));

    std::cout << "TEST TO PASS" << std::endl;
	Base *ptr = generate();
	Base &ref = *ptr;

	identify(ptr);
	identify(ref);

	delete ptr;
    
    std::cout << std::endl;

    std::cout << "TEST TO FAIL" << std::endl;
    Base* p = new C(); 

    try {
        A& a = dynamic_cast<A&>(*p); 
        (void)a;
        std::cout << "type: A" << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error: is not Type A" << std::endl;
    }


    if (dynamic_cast<A*>(p) == NULL)
    {
        std::cout << "not A "<< dynamic_cast<A*>(p) << std::endl;
    }

	return 0;
}