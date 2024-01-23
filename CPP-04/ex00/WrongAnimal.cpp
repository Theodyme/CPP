#include "WrongAnimal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongAnimal::WrongAnimal() : _type("Bugged monstruosity")
{
	std::cout << "An " RE << this->_type << WH << " tears your screen open.\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal&src)
{
	std::cout << "An " RE << this->_type << WH << " tears your screen open. (copy)\n";
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WrongAnimal::~WrongAnimal()
{
	std::cout << "The " RE << this->_type << WH << " disappears in the black pixels.\n";
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WrongAnimal	&WrongAnimal::operator=(WrongAnimal const &rhs)
{
	if (this == &rhs)
		return (*this);
	setType(rhs.getType());
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void		WrongAnimal::makeSound() const
{
	std::cout << "A " RE << "glitched noise" << WH << " scratch your ears.\n";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	WrongAnimal::getType() const
{
	return this->_type;
}

void 		WrongAnimal::setType(std::string type)
{
	this->_type = type;
}

/* ************************************************************************** */
