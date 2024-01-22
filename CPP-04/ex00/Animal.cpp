#include "Animal.hpp"
/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Animal::Animal()
{
	this->_type = "Unknown scary beast";
}

Animal::Animal(const Animal&src)
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Animal::~Animal()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Animal	&Animal::operator=(Animal const &rhs)
{
	return *this;
}

std::ostream &operator<<(std::ostream &o, Animal const &instance)
{
	//o << instance.value;
	//return (o);
}
/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
