#include "FragTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->setHitpts(100);
	this->setEnergy(100);
	this->setDamage(30);
	std::cout << "FragTrap " <<  this->_name << " has been created.\n";
}

FragTrap::FragTrap(const FragTrap&src) : ClapTrap(src._name)
{
	*this = src;
	std::cout << "FragTrap " <<  this->_name << " has been created. (copy)\n";
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->_name << " has been destroyed.\n";
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

FragTrap	&FragTrap::operator=(FragTrap const &rhs)
{
	this->_name = rhs._name;
	this->_hitpts = rhs._hitpts;
	this->_energy = rhs._energy;
	this->_attack_dmg = rhs._attack_dmg;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void FragTrap::highFivesGuys(void)
{
	std::cout << this->_name << " raises his hand and patiently waits for a high five.\n";
}

/* ************************************************************************** */
