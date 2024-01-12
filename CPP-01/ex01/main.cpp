#include "Zombie.hpp"

int main()
{
    std::string name1;
    std::string name2;
    Zombie *horde;

    std::cout << "> Welcome to CPP-01, ex01. Let's rise a zombie on the heap again.\n";
    std::cout << "> Please give it a name: ";
    std::cin >> name1;
    std::cout << "\n";

    Zombie *zombie = newZombie();
    zombie->setName(name1);
    zombie->announce();
    std::cout << "\n";

    std::cout << "> Seems like it still works! How about we try a few more?\n";
    std::cout << "> Please give them a name too: ";
    std::cin >> name2;
    std::cout << "\n";

    horde = zombieHorde(4, name2);
    for(int i = 0; i < 4; i++)
	{
		horde[i].announce();
	}
    std::cout << "\n";

    delete[] horde;
    std::cout << "> At least, they didn'st last long. " << name1 << ", you still up?\n";
    std::cout << "\n";
    delete zombie;
    std::cout << "\n";
    std::cout << "> Ok. I think we still have some work to do.\n";
    return 0;
}