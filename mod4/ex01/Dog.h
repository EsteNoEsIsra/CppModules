#ifndef DOG_H
#define DOG_H

#include "Animal.h" 
#include "Brain.h" 
class Dog : public Animal
{
    private:
        Brain *brain;
    public:
        Dog();
        Dog(const Dog &to_copy);
        Dog &operator=(const Dog &original);
        ~Dog();

        Dog(const std::string &_type);
        void makeSound() const;
};

#endif