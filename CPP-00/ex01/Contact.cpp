#include <iostream>
#include "Contact.hpp"

/* ------------------------------- getters ------------------------------- */


std::string	Contact::get_firstname() const
{
	return this->firstname;
}

std::string	Contact::get_lastname() const
{
	return this->lastname;
}

std::string	Contact::get_nickname() const
{
	return this->nickname;
}

std::string	Contact::get_number() const
{
	return this->number;
}

std::string	Contact::get_secret() const
{
	return this->secret;
}

/* ------------------------------- setters ------------------------------- */


void	Contact::set_firstname(std::string fname)
{
	this->firstname = fname;
	return ;
}

void	Contact::set_lastname(std::string lname)
{
	this->lastname = lname;
	return ;
}

void	Contact::set_nickname(std::string nname)
{
	this->nickname = nname;
	return ;
}

void	Contact::set_number(std::string nbr)
{
	this->number = nbr;
	return ;
}

void	Contact::set_secret(std::string secret)
{
	this->secret = secret;
	return ;
}
