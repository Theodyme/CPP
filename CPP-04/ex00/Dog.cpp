

#include "Dog.hpp"
/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog()
{
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
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog	&Dog::operator=(Dog const &rhs)
{
	return *this;
}

std::ostream &operator<<(std::ostream &o, Dog const &instance)
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
