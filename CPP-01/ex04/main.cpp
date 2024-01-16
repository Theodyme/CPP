#include <iostream>
#include <fstream>
#include <string>
#include "Sed.hpp"

int main(int ac, char **av)
{    
    if (ac != 4)
    {
        std::cout << "Wrong number of arguments.\n";
        return 1;
    }
    Sed sed(av[1]);
    sed.open_replace(av[2], av[3]);
    return 0;
}