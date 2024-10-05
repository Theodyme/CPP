#include "PmergeMe.hpp"


template <typename C>
void print(C &container, std::string type)
{
	if (type == "VECTOR")
		std::cout << "vector: [";
	else
		std::cout << "deque: [";
	for (int i = 0; container[i]; i++)
		std::cout << container[i] << ", ";
	std::cout << "]" << std::endl;
}

template <typename C>
int fill(char **av, C &container)
{
	char *suffix;
	for (int i = 1; av[i]; i++)
	{
		long value = strtol(av[i], &suffix, 10);
		if (*suffix != '\0' || value < 0)
		{
			std::cerr << "Error: invalid argument\n";
			return 1;
		}
		container.push_back(value);
	}
	return 0;
}

template <typename T>
std::vector<T> sortVector(std::vector<T> &vector)
{
	if (vector.size <= 1)
		return vector;

	std::vector<std::pair<T, T> >	divided;

	for (int i = 0; vector[i]; i += 2)
	{
		if ((i + 1) < vector.size())
			divided.insert(std::pair<T, T>(vector[i], vector[i + 1]));
		else
			divided.insert(std::pair<T, T>(vector[i], T()));
	}

	// tri pour recuperer chaque element + plus par paire

	// recursion dans le sort des elements les + grands
	// sortVector();

	//

}


int	main(int ac, char **av)
{
	// pas d'argument a parser
	if (ac == 1)
		return 0;

	// remplit une stack de vecteurs et verifie si les arguments sont tous valides
	std::vector<int> vector;
	std::deque<int> deque;
	if (fill(av, vector) == 1)
		return 1;
	if (fill(av, deque) == 1)
		return 1;

	print(vector, "VECTOR");
	print(deque, "DEQUE");

	divideVector(vector);
	// recursion

	// retour
	return 0;
}
