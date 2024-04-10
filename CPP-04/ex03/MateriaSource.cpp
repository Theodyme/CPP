#include "MateriaSource.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

MateriaSource::MateriaSource()
{
	std::cout << CY << "A Materia Source " << WH << "has been created.\n";
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource&src)
{
	std::cout << CY << "A Materia Source " << WH << "has been created. (copy)\n";
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = (src._inventory[i])->clone();
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

MateriaSource::~MateriaSource()
{
	std::cout << CY << "A Materia Source " << WH << "has been destroyed.\n";
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
}
/*
** --------------------------------- OVERLOAD ---------------------------------
*/

MateriaSource	&MateriaSource::operator=(MateriaSource const &rhs)
{
	if (this == &rhs)
		return (*this);
	for (int i = 0; i < 4; i++)
	{
		if ((this->_inventory)[i])
			delete (this->_inventory)[i];
		if ((rhs._inventory)[i])
			(this->_inventory)[i] = (rhs._inventory)[i];
	}
	return (*this);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void MateriaSource::learnMateria(AMateria* m)
{
	int i = 0;

	while (this->_inventory[i] && i <= 4)
		i++;
	if (i == 4)
		std::cout << "The" << CY << " Materia Source " << WH << "cannot learn new materia.\n";
	else
	{
		std::cout << "The" << CY << " Materia Source " << WH << "learned " << GR << m->getType() << WH << ".\n";
		this->_inventory[i] = m;
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	int i = 0;

	while (this->_inventory[i] && i <= 4 && this->_inventory[i]->getType() != type)
		i++;
	if (i == 4 || !(this->_inventory)[i])
	{
		std::cout << "Searched" << GR << " Materia " << WH << "doesn't exist.\n";
		return (NULL);
	}
	std::cout << GR << this->_inventory[i]->getType() << " materia " << WH << "created from the source.\n";
	return ((this->_inventory)[i]->clone());
}

/* ************************************************************************** */
