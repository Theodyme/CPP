#include "Zombie.hpp"

int main()
{
    std::string name1;
    std::string name2;

    std::cout << "> Welcome to CPP-01, ex00. Let's rise a zombie on the heap.\n";
    std::cout << "> Please give it a name: ";
    std::cin >> name1;
    std::cout << "\n";

    Zombie *zombie = newZombie(name1);
    zombie->announce();
    std::cout << "\n";

    std::cout << "> Seems like this little one is awake! Let's rise another zombie on the stack.\n";
    std::cout << "> Please give it a name too: ";
    std::cin >> name2;
    std::cout << "\n";

    randomChump(name2);
    std::cout << "\n";

    std::cout << "> Woops. It didn't live long. How about our friend " << name1 << ", are you ok ?\n";
    std::cout << "\n";
    delete zombie;
    std::cout << "\n";
    std::cout << "> Oh well. Must work on our necromancy lessons.\n";
    return 0;
}