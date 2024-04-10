#include "Character.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Character::Character() : ICharacter(), _name("John doe")
{
	std::cout << PU << this->_name << WH << " constructor called.\n";
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = 0;
}

Character::Character(std::string name) : _name(name)
{
	std::cout << PU << "Character " << this->_name << WH << " constructor called.\n";
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = 0;
}

Character::Character(const Character&src) : ICharacter(), _name(src._name)
{
	std::cout << PU << this->_name << WH << " copy constructor called (from " << PU << src._name << WH << ").\n";
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = (src._inventory[i])->clone();
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Character::~Character()
{
	std::cout << PU << this->_name << WH << " destructor called.\n";
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	Character::equip(AMateria* m)
{
	int i = 0;
	if (!m)
	{
		std::cout << PU << this->_name << " can't equip non-existent materia.\n";
		return ;
	}
	while (i < 4)
	{
		if (!(this->_inventory)[i])
		{
			(this->_inventory)[i] = m;
			std::cout << PU << this->_name << " equipped " << GR << ((this->_inventory)[i])->getType() << WH << ".\n";
			return ;
		}
		i++;
	}
	std::cout << PU << this->_name << "'s inventory is full!\n";
	return ;
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
		std::cout << PU << this->_name << " doesn't have that much space in his inventory.\n";
	else if (!(this->_inventory)[idx])
		std::cout << PU << this->_name << " can't unequip an empty slot!\n";
	else
	{
		std::cout << PU << this->_name << " unequipped " << GR << (this->_inventory[idx])->getType() << WH << " from his inventory.\n";
		(this->_inventory)[idx] = NULL;
	}
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4 || !(this->_inventory)[idx])
	{
		std::cout << PU << this->_name << " doesn't know this materia.\n";
		return ;
	}
	std::cout << PU << this->_name << WH << " ";
	(this->_inventory)[idx]->use(target);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	const & Character::getName() const
{
	return this->_name;
}

/* ************************************************************************** */
