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

    std::string filename(av[1]);
    std::string needle(av[2]);
    std::string replace(av[3]);

    Sed sed(filename);
    sed.open_replace(needle, replace);
    return 0;
}