#include "Dog.h"
#include "Cat.h"
#include "Animal.h"
#include "WrongAnimal.h"
#include "WrongCat.h"

int main( void )
{
     const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    i->makeSound(); // Cat sound
    j->makeSound(); // Dog sound
    meta->makeSound(); // Animal sound

    delete meta;
    delete j;
    delete i;

        /*
    const Animal* animal = new Animal();
	std::cout << "Hi, I am a " << animal->getType() << " " << std::endl;
	animal->makeSound();
	delete animal;
	std::cout << std::endl;
	
	
	const Animal* dog = new Dog();
	std::cout << "Hi, I am a " << dog->getType() << " " << std::endl;
	dog->makeSound();
	delete dog;
	std::cout << std::endl;
	
	
	const Animal* cat = new Cat();
	std::cout << "Hi, I am a " << cat->getType() << " " << std::endl;
	cat->makeSound();
	delete cat;
	std::cout << std::endl;


	const WrongAnimal* wrong_animal = new WrongAnimal();
	std::cout << "Hi, I am a " << wrong_animal->getType() << " " << std::endl;
	wrong_animal->makeSound();
	delete wrong_animal;
	std::cout << std::endl;


	const WrongAnimal* wrong_cat = new WrongCat();
	std::cout << "Hi, I am a " << wrong_cat->getType() << " " << std::endl;
	wrong_cat->makeSound();
	delete wrong_cat;
	std::cout << std::endl;
    */
    return 0;
}