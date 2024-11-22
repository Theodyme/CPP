#include "PmergeMe.hpp"

int		main(int ac, char **av)
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


	std::cout << "//////// VECTOR //////////" << std::endl;

	std::cout << std::endl;
	std::cout << "Before: ";
	printList(vector);

	std::clock_t startV = std::clock();
	std::vector<int> sortedVector = sortVector(vector);
	std::clock_t endV = std::clock();

	std::cout << "After: ";
	printList(sortedVector);
	std::cout << std::endl;

	double timeV = 1000000.0 * (endV - startV) / CLOCKS_PER_SEC;

	std::cout << "Time to process a range of " << vector.size() << " elements with std::vector: " << timeV << " us" << std::endl;

	std::cout << std::endl;
	std::cout << "//////// DEQUE //////////" << std::endl;

	std::cout << std::endl;
	std::cout << "Before: ";
	printList(deque);

	std::clock_t startD = std::clock();
	std::deque<int> sortedDeque = sortDeque(deque);
	std::clock_t endD = std::clock();	

	std::cout << "After: ";
	printList(sortedDeque);
	std::cout << std::endl;

	double timeD = 1000000.0 * (endD - startD) / CLOCKS_PER_SEC;

	std::cout << "Time to process a range of " << deque.size() << " elements with std::deque: " << timeD << " us" << std::endl;


	return 0;
}
