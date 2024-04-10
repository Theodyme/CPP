#include "AMateria.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AMateria::AMateria() : _type("Abstract")
{
	std::cout << GR << this->_type << WH << " materia constructor called.\n";
}

AMateria::AMateria(std::string const & type) : _type(type)
{
	std::cout << "Abstract " << GR << this->_type << WH << " materia constructor called.\n";
}

AMateria::AMateria(const AMateria&src) : _type(src._type)
{
	std::cout << GR << this->_type << WH << " materia copy constructor called.\n";
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AMateria::~AMateria()
{
	std::cout << GR << this->_type << WH << " materia destructor called.\n";
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void AMateria::use(ICharacter& target)
{
	std::cout << GR << this->getType() << WH << " materia used on " << PU << target.getName() << WH;
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	const & AMateria::getType() const
{
	return this->_type;
}

// AMateria & AMateria::operator=(AMateria const & rhs)
// {
// 	this->_type = rhs.getType();
// 	return (*this);
// }
/* ************************************************************************** */
