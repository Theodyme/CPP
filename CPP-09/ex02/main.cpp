#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	if (ac == 1)
		return 0;
	std::vector<int> stack;
	char *suffix;
	for (int i = 0; av[i]; i++)
	{
		stack.push_back(strtol(av[i], &suffix, 10));
		if (suffix)
		{
			std::cerr << "Error: invalid argument\n";
			return 1;
		}
	}
	return 0;
}
