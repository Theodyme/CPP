#include "Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat() : Animal()
{
	this->_type = "Cat";
	std::cout << "It's actually a cute little " GR << this->_type << WH << " !\n";
}

Cat::Cat(const Cat&src)
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat()
{
	std::cout << "The tiny adorable " GR << this->_type << WH << " returns to its couch.\n";
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cat	&Cat::operator=(Cat const &rhs)
{
	if (this == &rhs)
		return (*this);
	setType(rhs.getType());
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	Cat::makeSound() const
{
	std::cout << "A small and warming \"" GR << "Meooow" << WH << "\" soothes your problems away.\n";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
