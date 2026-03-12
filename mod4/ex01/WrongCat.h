#ifndef WRONGCAT_H
#define WRONGCAT_H

#include "WrongAnimal.h" 
class WrongCat : public WrongAnimal
{
    private:

    public:
        WrongCat();
        WrongCat(const WrongCat &to_copy);
        WrongCat &operator=(const WrongCat &original);
        ~WrongCat();

        WrongCat(const std::string  &_type);
        void makeSound() const;
};

#endif