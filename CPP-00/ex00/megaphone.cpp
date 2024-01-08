#include <iostream>

char    *toUpper(char *string)
{
    for (int i = 0; string[i]; i++)
    {
        string[i] = toupper(string[i]);
    }
    return string;
}

int     main(int ac, char **av)
{
    if (ac < 2)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    else
    {
        for(int i = 1; av[i]; i++)
            std::cout << toUpper(av[i]) << " ";
    }
    std::cout << "\n";
    return 0;
}