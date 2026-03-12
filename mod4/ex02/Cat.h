#ifndef CAT_H
#define CAT_H

#include "AAnimal.h" 
#include "Brain.h" 

class Cat : public AAnimal
{
    private:
        Brain *brain;
    public:
        Cat();
        Cat(const Cat &to_copy);
        Cat &operator=(const Cat &original);
        ~Cat();

        Cat(const std::string &_type);
        void makeSound() const;
        Brain *getBrain() const;
};

#endif