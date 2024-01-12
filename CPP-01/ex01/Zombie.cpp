#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "A Zombie woke up from the dead.\n";
}

Zombie::~Zombie()
{
	std::cout << this->name << " just died... for now.\n";
}

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ...\n";
	return;
}

void	Zombie::setName(std::string name)
{
	this->name = name;
}