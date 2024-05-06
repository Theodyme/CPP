#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	if (ac != 2)
		std::cerr << "Error: wrong number of argument" << std::endl;
	BitcoinExchange pouet;
	pouet.file_handler(av[1]);
	return 0;
}