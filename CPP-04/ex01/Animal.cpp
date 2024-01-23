#include "Animal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Animal::Animal() : _type("Unknown scary beast")
{
	std::cout << "An " BL << this->_type << WH << " awakens from the concrete jungle.\n";
}

Animal::Animal(const Animal&src)
{
	std::cout << "An " BL << this->_type << WH << " awakens from the concrete jungle. (copy)\n";
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Animal::~Animal()
{
	std::cout << "The " BL << this->_type << WH << " returns to its lair.\n";
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Animal	&Animal::operator=(Animal const &rhs)
{
	if (this == &rhs)
		return (*this);
	setType(rhs.getType());
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	Animal::makeSound() const
{
	std::cout << "A " BL << "terrifying noise" << WH << " you can't recognize echoes in the streets.\n";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	Animal::getType() const
{
	return this->_type;
}

void Animal::setType(std::string type)
{
	this->_type = type;
}

/* ************************************************************************** */
