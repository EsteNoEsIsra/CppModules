#include "Brain.h"

Brain::Brain()
{
	std::cout << "Brain Default Constructor called" << std::endl;
}

Brain::Brain(const Brain &copy)
{
	std::cout << "Brain Copy Constructor called" << std::endl;
	*this = copy;
}

Brain::~Brain()
{
	std::cout << "Brain Destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &original)
{
	std::cout << "Brain Assignation operator called" << std::endl;
	if (this != &original)
	{
		for (int i = 0; i < 100; i++)
		{
			if (original.ideas[i].length() > 0)
				this->ideas[i] = original.ideas[i];
		}
	}	
	return *this;
}

std::string	Brain::getIdea(int i)const
{
	if (i < 100)
		return(this->ideas[i]);
	else
		return ("There is only 100 ideas per brain.");
}


void Brain::setIdea(int i, std::string _idea)  
{
	if (i < 100)
		this->ideas[i] = _idea;
	else
		std::cout << "Only 100 ideas per brain" << std::endl;
}