#include <iostream>
#include "Contact.hpp"
#include "Colors.h"
#include "PhoneBook.hpp"

int main(int ac, char **av)
{
	PhoneBook	phonebook;
	std::string	input;

	(void)av;
	if (ac > 1)
		return 1;
	std::cout << BL << "⬥ Welcome to " << GR << "Triton™ Phonebook" << BL << ", the only phone assistant you'll ever need! How may I help you?\n" << WH;
	while(input != "EXIT")
	{
		std::cout << BL << "⬥ Command informations:\n";
		std::cout << GR << "	〉 ADD: " << WH << "add a contact.\n" << WH;
		std::cout << GR << "	〉 SEARCH: " << WH << "search for a contact and display their infos.\n" << WH;
		std::cout << GR << "	〉 EXIT: " << WH << "exit your phonebook.\n" << WH;
		std::cout << BL << "⬦ " << WH;
		if (!std::getline(std::cin, input))
		{
			std::cout << BL << "⬥ Oops. Something went wrong. Bye!\n" << WH;
			break;
		}
		if (input == "ADD")
			phonebook.add();
		if (input == "SEARCH")
			phonebook.search();
	}
	std::cout << BL << "⬥ Goodbye, have a nice day~!\n" << WH;
	return 0;
}
