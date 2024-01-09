#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(int ac, char **av)
{
	PhoneBook	phonebook;
	std::string	input;

	(void)av;
	if (ac > 1)
		return 1;
	std::cout << "> Welcome to Triton™ Phonebook! How may I help you?\n";
	while(input != "EXIT")
	{
		std::cout << "> ";
		if (!std::getline(std::cin, input))
		{
			std::cout << "Oops. Something went wrong.\n";
			break;
		}
		if (input == "ADD")
			phonebook.add();
		if (input == "SEARCH")
			phonebook.search();
	}
	std::cout << "Goodbye, have a nice day! ~\n";
	return 0;
}
