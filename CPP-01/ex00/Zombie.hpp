#pragma once
#include <iostream>

class Zombie
{
	private:
		std::string	name;

	public:
		void		announce(void);
};

void	randomChump(std::string name);
Zombie*	newZombie(std::string name);
