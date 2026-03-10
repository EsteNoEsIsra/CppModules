#ifndef DOG_H
#define DOG_H

#include "Animal.h" 
class Dog : public Animal
{
    private:

    public:
        Dog();
        Dog(const Dog &to_copy);
        Dog &operator=(const Dog &original);
        ~Dog();
};

#endif