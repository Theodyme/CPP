#include "iter.hpp"

int main( void )
{
	std::string spouet[] = {"hello", "world", "como esta"};
	int ipouet[] = {1, 6, 4, 2};
	char cpouet[] = {'a', 'b', 'c'};

	iter(spouet, 3, printer);
	std::cout << std::endl;
	iter(ipouet, 4, increment);
	std::cout << std::endl;
	iter(cpouet, 3, increment);
	return 0;
}
