#include "ClapTrap.hpp"
/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ClapTrap::ClapTrap(std::string name) : _name(name), _hitpts(10), _energy(10), _attack_dmg(0)
{
	std::cout << "ClapTrap " << this->_name << " has been created.\n";
}

ClapTrap::ClapTrap(const ClapTrap&src)
{
	*this = src;
	std::cout << "ClapTrap " <<  this->_name << " has been created. (copy)\n";
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " <<  this->_name << " has been destroyed.\n";
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ClapTrap	&ClapTrap::operator=(ClapTrap const &rhs)
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

void ClapTrap::attack(const std::string& target)
{
	if (this->_energy == 0)
		std::cout << "ClapTrap " << this->_name << " has no energy. He can't attack!\n";
	else
	{
		this->_energy--;
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_dmg << " points of damage!\n";
	}
}
void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitpts < amount)
	{
		std::cout << "ClapTrap " << this->_name << " gets hit and lose " << this->_hitpts << " hitpoints. He's at death's door !\n";
		this->_hitpts = 0;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << " gets hit and lose " << amount << " hitpoints.\n";
		this->_hitpts -= amount;
	}
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy == 0)
		std::cout << "ClapTrap " << this->_name << " has no energy. He can't attack!\n";
	else
	{
		this->_hitpts += amount;
		this->_energy--;
		std::cout << "ClapTrap " << this->_name << " repairs and recovers " << amount << " hitpoints.\n";
	}
}

/*
** ------------------------------GETTERS-&-SETTERS -----------------------------
*/

std::string	ClapTrap::getName()
{
	return (this->_name);
}
unsigned int	ClapTrap::getHitpts()
{
	return (this->_hitpts);
}
unsigned int	ClapTrap::getEnergy()
{
	return (this->_energy);
}
unsigned int	ClapTrap::getDamage()
{
	return (this->_attack_dmg);
}
void	ClapTrap::setHitpts(unsigned int amount)
{
	this->_hitpts = amount;
	return ;
}
void	ClapTrap::setEnergy(unsigned int amount)
{
	this->_energy = amount;
	return ;
}
void	ClapTrap::setDamage(unsigned int amount)
{
	this->_attack_dmg = amount;
	return ;
}


/* ************************************************************************** */
