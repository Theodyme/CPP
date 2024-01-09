#include <iomanip>
#include <iostream>
#include "PhoneBook.hpp"

int		PhoneBook::get_size()
{
	int i;
	for(i = 0; !(this->contacts[i].get_firstname().empty()); i++);
	// std::cout << i << std::endl;
	return i;
}

void	PhoneBook::add()
{
	std::string input = "";

	if (this->idx == 0)
		std::cout << "Sure we can! ~\n";
	else if (this->get_size() == 8)
	{
		std::cout << "> It seems like your contacts are full. Adding a new one will overwrite " << this->contacts[8 - idx].get_firstname() << ".\n";
		std::cout << "> Would you still like to continue? YES/NO\n";
		if (!std::getline(std::cin, input))
			return;
		else if (input == "NO")
			return;
		if (this->idx == 8)
			this->idx = 0;
		input = "";
	}
	std::cout << "> Please type in their infos as required.\n> First name: ";
	std::getline(std::cin, input);
	this->contacts[idx].set_firstname(input);
	input = "";

	std::cout << "> Last name: ";
	std::getline(std::cin, input);
	this->contacts[idx].set_lastname(input);
	input = "";

	std::cout << "> Nickname: ";
	std::getline(std::cin, input);
	this->contacts[idx].set_nickname(input);
	input = "";

	std::cout << "> Number: ";
	std::getline(std::cin, input);
	this->contacts[idx].set_number(input);
	input = "";

	std::cout << "> Darkest secret: ";
	std::getline(std::cin, input);
	this->contacts[idx].set_secret(input);
	input = "";

	std::cout << "> " << this->contacts[idx].get_firstname() << " was successfully added to your contacts!\n";
	this->idx++;
	return ;
}

void	PhoneBook::show_contact(int idx)
{
	(void)idx;
}

void	PhoneBook::display()
{
	int idx;

	for(idx = 0; idx <= this->get_size(); idx++)
	{
		std::cout << "|" << std::left << std::setw(10) << this->contacts[idx].get_firstname();
		std::cout << "|" << std::left << std::setw(10) << this->contacts[idx].get_lastname();
		std::cout << "|" << std::left << std::setw(10) << this->contacts[idx].get_nickname();
		std::cout << "|" << std::left << std::setw(10) << this->contacts[idx].get_number();
		std::cout << "|" << std::left << std::setw(10) << this->contacts[idx].get_secret() << "|\n";
	}
	return;
}

void	PhoneBook::search()
{
	std::string input;

	if (this->get_size() == 0)
	{
		std::cout << "> Oops! It seems like your phonebook is empty.\n";
		return;
	}
	else
		this->display();

	std::cout << "> Please enter the index of the contact you're looking for.\n";
	if (!std::getline(std::cin, input))
		return;


}
