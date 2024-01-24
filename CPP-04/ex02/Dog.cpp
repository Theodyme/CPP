#include "Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog()
{
	this->_type = "Dog";
	this->_brain = new Brain;
	for (int i = 0; i < 100; i++)
	{
		if (i%2)
			this->_brain->setIdea(i, "Woof, I want cuddles!!");
		else
			this->_brain->setIdea(i, "Let's play outside !!!!");
	}
	std::cout << "It's actually a fierce, friendly " GR << this->_type << WH << " !\n";
}

Dog::Dog(const Dog&src)
{
	this->_type = src._type;
	this->_brain = new Brain();
	*this = src;
	// for (int i = 0; i < 100; i++)
	// {
	// 	this->_brain->setIdea(i, src._brain->getIdea(i));
	// }
	std::cout << "It's actually a fierce, friendly " GR << this->_type << WH << " ! (copy)\n";
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog()
{
	std::cout << "The affectionate " GR << this->_type << WH << " returns to its kennel.\n";
	delete this->_brain;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog	&Dog::operator=(Dog const &rhs)
{
	if (this == &rhs)
		return (*this);
	this->_type = rhs._type;
	delete this->_brain;
	this->_brain = new Brain;
	for (int i = 0; i < 100; i++)
	{
		this->_brain->setIdea(i, rhs._brain->getIdea(i));
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	Dog::makeSound() const
{
	std::cout << "A loving and playful \"" GR << "Woof" << WH << "\" warms your heart.\n";
}

Brain	*Dog::getBrain() const
{
	return this->_brain;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
