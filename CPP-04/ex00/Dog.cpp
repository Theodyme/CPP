#include "Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog() : Animal()
{
	this->_type = "Dog";
	std::cout << "It's actually a fierce, friendly " GR << this->_type << WH << " !\n";
}

Dog::Dog(const Dog&src)
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog()
{
	std::cout << "The affectionate " GR << this->_type << WH << " returns to its kennel.\n";
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog	&Dog::operator=(Dog const &rhs)
{
	this->_type = rhs._type;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	Dog::makeSound() const
{
	std::cout << "A loving and playful \"" GR << "Woof" << WH << "\" warms your heart.\n";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
