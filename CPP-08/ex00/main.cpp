#include "easyfind.hpp"
#include "easyfind.tpp"

int main ()
{
	try
	{
		std::vector<char> chay;
		chay.push_back('a');
		chay.push_back('c');
		chay.push_back('d');
		chay.push_back('b');



		std::vector<int> ihay;
		ihay.push_back(1);
		ihay.push_back(4);
		ihay.push_back(2);
		ihay.push_back(3);

		std::cout << "Looking for: 1. Should find position: 0.\n";
		easyfind(ihay, 1);
		std::cout << "Looking for: 2. Should find position: 2.\n";
		easyfind(ihay, 2);
		std::cout << "Looking for: 97 in a char container. Should find position: 0.\n";
		easyfind(chay, 97);
		std::cout << "Looking for: 7. Should find position: out of bounds.\n";
		easyfind(ihay, 7);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
