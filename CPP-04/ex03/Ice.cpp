#include "Ice.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Ice::Ice() : AMateria("ice"), _type("ice")
{
	std::cout << BL << this->getType() << WH << " materia constructor called.\n";
}

Ice::Ice(const Ice&src) : AMateria(src), _type(src._type)
{
	std::cout << BL << this->getType() << WH << " materia copy constructor called.\n";
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Ice::~Ice()
{
	std::cout << BL << this->getType() << WH << " materia destructor called.\n";
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an " << BL << "ice " << WH << "bolt at " << PU << target.getName() << WH << "* \n";
}

Ice* Ice::clone() const
{
	Ice *cl = new Ice;
	return (cl);
}


Ice & Ice::operator=(Ice const & rhs)
{
	// (void)rhs;
	if (this == &rhs)
		return (*this);
	this->_type = rhs.getType();
	return (*this);
}

/* ************************************************************************** */
