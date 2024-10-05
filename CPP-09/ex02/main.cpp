#include "PmergeMe.hpp"


template <typename C>
void fill(char **av, C &container)
{
	char *suffix;
	for (int i = 1; av[i]; i++)
	{
		container.push_back(strtol(av[i], &suffix, 10));
		std::cout << container[i - 1] << ", ";
		if (*suffix != '\0')
		{
			std::cerr << "Error: invalid argument\n";
			break ;
		}
		std::cout << std::endl;
	}
}

template <typename T>
void divideVector(std::vector<T> &vector)
{
	std::vector<std::pair<T, T>>	divided;

	for (int i = 0; vector[i]; i = i + 2)
	{
		if ((i + 1) <= vector.size())
		{
			divided.insert(std::pair<T, T>(vector[i], vector[i + 1]);)
		}
		else
		

	}
}


int	main(int ac, char **av)
{
	// pas d'argument a parser
	if (ac == 1)
		return 0;

	// remplit une stack de vecteurs et verifie si les arguments sont tous valides
	std::vector<int> vector;
	std::deque<int> deque;
	fill(av, vector);
	fill(av, deque);




	// recursion

	// retour
	return 0;
}