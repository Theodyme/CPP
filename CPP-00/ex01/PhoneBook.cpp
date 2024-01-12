#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <string>
#include "Colors.h"
#include "PhoneBook.hpp"

void	PhoneBook::add()
{
	std::string input = "";

	if (this->cnt == 8)
	{
		std::cout  << BL << "⬥ " << PU << "It seems like your contacts are full. Adding a new one will overwrite " << this->contacts[idx].get_firstname() << ".\n" << WH;
		std::cout  << BL << "⬥ " << PU << "Would you still like to continue? " << GR << "YES/NO\n" << BL << "⬦ " << WH;
		if (!std::getline(std::cin, input))
			exit(0);
		else if (input != "YES")
			return;
		input = "";
	}
	else if (this->idx == 0)
		std::cout << GR << "⬥ Sure we can~!\n" << WH;
	std::cout << "\n";
	std::cout << BL << "⬥ " << PU << "Please type in their infos as required.\n	First name: " << WH;
	if (!std::getline(std::cin, input))
		exit(0);
	while (input == "")
	{
		std::cout << BL << "⬥ A first name is mandatory!\n" << PU << "	Please enter a first name: " << WH;
		if (!std::getline(std::cin, input))
			exit(0);
	}
	this->contacts[idx].set_firstname(input);
	input = "";

	std::cout << PU << "	Last name: " << WH;
	if (!std::getline(std::cin, input))
		exit(0);
	this->contacts[idx].set_lastname(input);
	input = "";

	std::cout << PU << "	Nickname: " << WH;
	if (!std::getline(std::cin, input))
		exit(0);
	this->contacts[idx].set_nickname(input);
	input = "";

	std::cout << PU << "	Number: " << WH;
	if (!std::getline(std::cin, input))
		exit(0);
	this->contacts[idx].set_number(input);
	input = "";

	std::cout << PU << "	Darkest secret: " << WH;
	if (!std::getline(std::cin, input))
		exit(0);
	this->contacts[idx].set_secret(input);
	input = "";

	if (this->cnt < 8)
		this->cnt++;
	std::cout << BL << "⬥ " << GR << this->contacts[idx].get_firstname() << PU << " was successfully added to your contacts!\n" << WH;
	std::cout << "\n";
	this->idx = (this->idx + 1) % 8;
	return ;
}

void	PhoneBook::show_contact(int idx)
{
	std::cout << BL << "⬥ " << PU << "Contact infos:\n" << WH;
	std::cout << GR << "────────╥ First name: " << PU << this->contacts[idx].get_firstname() << "\n" << WH;
	std::cout << GR << "	╟ Last name: " << PU << this->contacts[idx].get_lastname() << "\n" << WH;
	std::cout << GR << "	╟ Nick name: " << PU << this->contacts[idx].get_nickname() << "\n" << WH;
	std::cout << GR << "	╟ Phone number: " << PU << this->contacts[idx].get_number() << "\n" << WH;
	std::cout << GR << "	╙ Darkest secret: " << PU << this->contacts[idx].get_secret() << "\n" << WH;
}

void	PhoneBook::display()
{
	int i;

	std::cout << GR << "	╒══════════╤══════════╤══════════╤══════════╕\n";
	std::cout << "	│" << BL << std::setw(10) << std::left << "index" << GR;
	std::cout << "│" << BL << std::setw(10) << std::left << "first name" << GR;
	std::cout << "│" << BL << std::setw(10) << std::left << "last name" << GR;
	std::cout << "│" << BL << std::setw(10) << std::left << "nickname" << GR << "│\n";
	std::cout << "	╞══════════╪══════════╪══════════╪══════════╡\n";

	for(i = 0; i < this->cnt; i++)
	{
		std::cout << "	│" << WH << std::setw(10) << std::right << i;
		std::cout << GR << "│" << WH << std::setw(10) << std::right << this->contacts[i].get_firstname().substr(0, 10);
		std::cout << GR << "│" << WH << std::setw(10) << std::right << this->contacts[i].get_lastname().substr(0, 10);
		std::cout << GR << "│" << WH << std::setw(10) << std::right << this->contacts[i].get_nickname().substr(0, 10) << GR << "│\n";
	}
	std::cout << "	╰──────────┴──────────┴──────────┴──────────╯\n" << WH ;
	return;
}

void	PhoneBook::search()
{
	std::string input;

	std::cout << "\n";
	if (this->cnt == 0)
	{
		std::cout  << BL << "⬥ " << PU << "⬥ Oops! It seems like your phonebook is empty.\n" << WH;
		return;
	}
	else
		this->display();

	std::cout << BL << "⬥ " << PU << "Please enter the index of the contact you're looking for.\n⬦ " << WH;
	if (!std::getline(std::cin, input))
		exit(0);
	while ((input.size() != 1) || (input[0] - '0') >= this->cnt)
	{
		std::cout  << BL << "⬥ " << PU << "Invalid input. (" << (input[0] - '0') << ") Please enter a number up to " << (this->cnt - 1) << "\n⬦ " << WH;
		if (!std::getline(std::cin, input))
			exit(0);
	}
	this->show_contact(input[0] - '0');
	std::cout << "\n";
	return;
}
