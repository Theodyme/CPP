#include "ScavTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->setHitpts(100);
	this->setEnergy(50);
	this->setDamage(20);
	std::cout << "ScavTrap " << this->_name << " has been created.\n";
}

ScavTrap::ScavTrap(const ScavTrap&src) : ClapTrap(src._name)
{
	*this = src;
	std::cout << "ScavTrap " <<  this->_name << " has been created. (copy)\n";
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->_name << " has been destroyed.\n";
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	ScavTrap::guardGate()
{
	std::cout << this->_name << " is now in Gate keeper mode.\n";
}

/* ************************************************************************** */
