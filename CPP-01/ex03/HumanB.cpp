#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{

}

HumanB::~HumanB()
{

}

void    HumanB::attack()
{
	if (this->_weapon == NULL)
		std::cout << this->_name << " attacks with their bare hands\n";
	else
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << "\n";
}

void    HumanB::setWeapon(Weapon &weapon)
{
    this->_weapon = &weapon;
}
