#include "Cure.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cure::Cure() : AMateria("cure"), _type("cure")
{
	std::cout << RE << this->getType() << WH << " materia constructor called.\n";
}

Cure::Cure(const Cure&src) : AMateria(src), _type(src._type)
{
	std::cout << RE << this->getType() << WH << " materia copy constructor called.\n";
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cure::~Cure()
{
	std::cout << RE << this->getType() << WH << " materia destructor called.\n";
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Cure::use(ICharacter& target)
{
	std::cout << "* " << RE << "heals " << PU << target.getName() << WH << "'s wounds *\n";
}

Cure* Cure::clone() const
{
	Cure *cl = new Cure;
	return (cl);
}

Cure & Cure::operator=(Cure const & rhs)
{
	// (void)rhs;
	if (this == &rhs)
		return (*this);
	this->_type = rhs.getType();
	return (*this);
}

/* ************************************************************************** */
