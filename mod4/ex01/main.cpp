#include "Dog.h"
#include "Cat.h"
#include "Animal.h"
#include "WrongAnimal.h"
#include "WrongCat.h"
#include "Brain.h"

int main( void )
{
	
	std::cout << "***test***" << std::endl;
	const int max_l = 4;

	Animal *ani[max_l];
	

	std::cout << "---------create----------" << std::endl;
	for (size_t i = 0; i < max_l; i++)
	{
		if (i % 2 == 0)
			ani[i] = new Dog();
		else
			ani[i] = new Cat(); 
	}
	
	std::cout << "---------makesound----------" << std::endl;
	for (size_t i = 0; i < max_l; i++)
	{
		ani[i]->makeSound();
	}
	
	std::cout << "---------copy----------" << std::endl;
	Cat cat1;
	Cat cat2 = cat1;

	std::cout << "---------destroy----------" << std::endl;
	for (size_t i = 0; i < max_l; i++)
	{
		delete ani[i];
	}
	


	std::cout << "***end of test***" << std::endl;

	//



	std::cout << "***Deep copy***" << std::endl;
	Dog dog1;

	dog1.getBrain()->setIdea(0,"im hungry");

    Dog dog2 = dog1;
	dog1.getBrain()->setIdea(0,"im sleepy");

    std::cout << dog1.getBrain()->getIdea(0) << std::endl;
    std::cout << dog2.getBrain()->getIdea(0) << std::endl;
	

    return 0;
}