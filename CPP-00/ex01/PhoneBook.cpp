#include <iostream>
#include "PhoneBook.hpp"

void	PhoneBook::add()
{
	std::string input = "";
	Contact	contact;

	this->idx = 0;
	std::cout << "Sure we can! ~\n";

	std::cout << "Please type in their info as required.\nFirst name:";
	std::getline(std::cin, input);
	contact.set_firstname(input);
	input = "";

	std::cout << "Last name:";
	std::getline(std::cin, input);
	contact.set_lastname(input);
	input = "";

	std::cout << "Nickname:";
	std::getline(std::cin, input);
	contact.set_nickname(input);
	input = "";

	std::cout << "Number:";
	std::getline(std::cin, input);
	contact.set_number(input);
	input = "";

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
