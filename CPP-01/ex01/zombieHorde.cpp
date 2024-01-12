#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie	*horde = new Zombie[N];

	for(int i = 0; i < N; i++)
	{
		horde[i].setName(name);
	}
    std::cout << "> Oh oh, seems like we created a horde of " << name << ". You sure you wanted to do that?\n";
	return horde;
}