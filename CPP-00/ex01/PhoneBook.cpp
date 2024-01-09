#include <iostream>
#include "PhoneBook.hpp"

void	PhoneBook::add()
{
	std::string input = "";

	if (this->idx == 0)
		std::cout << "Sure we can! ~\n";
	else if (this->idx == 8)
	{
		std::cout << "It seems like your contats are full. Adding a new one will overwrite " << this->contacts[8 - this->idx].get_firstname() << ".\n";
		std::cout << "Would you still like to continue? YES/NO\n";
		if (!std::getline(std::cin, input))
			return;
		else if (input == "NO")
			return;
		this->idx = 0;
		// input = "";
	}
	std::cout << "Please type in their infos as required.\nFirst name:";
	std::getline(std::cin, input);
	this->contacts[idx].set_firstname(input);
	// input = "";

	std::cout << "Last name:";
	std::getline(std::cin, input);
	this->contacts[idx].set_lastname(input);
	// input = "";

	std::cout << "Nickname:";
	std::getline(std::cin, input);
	this->contacts[idx].set_nickname(input);
	// input = "";

	std::cout << "Number:";
	std::getline(std::cin, input);
	this->contacts[idx].set_number(input);
	// input = "";

	std::cout << "Darkest secret:";
	std::getline(std::cin, input);
	this->contacts[idx].set_secret(input);
	// input = "";

	std::cout << this->contacts[idx].get_firstname() << " was successfully added to your contacts!\n";
	this->idx++;
	return ;
}

void	PhoneBook::display()
{

}

void	PhoneBook::search()
{
	std::string arg;

	this->idx = 0;
}
