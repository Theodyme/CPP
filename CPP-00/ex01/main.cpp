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
	while(input != "EXIT")
	{
		std::cout << "Welcome to Triton Phonebook! How may I assist you?\n";
		std::getline(std::cin, input);
		if (input == "ADD")
		{
			phonebook.add();
		}
		if (input == "SEARCH")
		{
			phonebook.search();
		}
	}
	std::cout << "Goodbye, have a nice day! ~\n";
	return 0;
}
