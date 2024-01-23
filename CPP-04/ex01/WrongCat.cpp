#include "WrongCat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongCat::WrongCat() : WrongAnimal()
{
	this->_type = "WrongCat";
	std::cout << "A " YE << this->_type << WH << " appears vaguely in the distance.\n";
}

WrongCat::WrongCat(const WrongCat&src)
{
	std::cout << "A " YE << this->_type << WH << " appears vaguely in the distance. (copy)\n";
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WrongCat::~WrongCat()
{
	std::cout << "The " YE << this->_type << WH << " vanishes in a wave.\n";
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WrongCat	&WrongCat::operator=(WrongCat const &rhs)
{
	if (this == &rhs)
		return (*this);
	setType(rhs.getType());
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void		WrongCat::makeSound() const
{
	std::cout << "A faint, defective " << YE << "meow" << WH << " deforms space and time.\n";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
