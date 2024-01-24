#include "Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat()
{
	this->_type = "Cat";
	this->_brain = new Brain;
	for (int i = 0; i < 100; i++)
	{
		if (i%2)
			this->_brain->setIdea(i, "Mreow, where's my milk?");
		else
			this->_brain->setIdea(i, "Zzzzzzz");
	}
	std::cout << "It's actually a cute little " GR << this->_type << WH << " !\n";
}

Cat::Cat(const Cat&src)
{
	this->_type = src._type;
	this->_brain = new Brain();
	for (int i = 0; i < 100; i++)
	{
		this->_brain->setIdea(i, src._brain->getIdea(i));
	}
	std::cout << "It's actually a cute little " GR << this->_type << WH << " ! (copy)\n";
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat()
{
	std::cout << "The tiny adorable " GR << this->_type << WH << " returns to its couch.\n";
	delete this->_brain;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cat	&Cat::operator=(Cat const &rhs)
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

void	Cat::makeSound() const
{
	std::cout << "A small and warming \"" GR << "Meooow" << WH << "\" soothes your problems away.\n";
}

Brain	*Cat::getBrain() const
{
	return this->_brain;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
