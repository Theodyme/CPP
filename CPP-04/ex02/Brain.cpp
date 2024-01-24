#include "Brain.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Brain::Brain()
{
	std::cout << CY << "An intelligent life form " << WH << "grew in a head.\n";
}

Brain::Brain(const Brain&src)
{
	std::cout << CY << "An intelligent life form " << WH << "grew in a head. (copy)\n";
	for (int i = 0; i < 100; i++)
	{
		this->_ideas[i] = src._ideas[i];
	}
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Brain::~Brain()
{
	std::cout << CY << "The intelligent life form " << WH << "shrinked back to nothingness.\n";
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Brain	&Brain::operator=(Brain const &rhs)
{
	if (this == &rhs)
		return (*this);
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = rhs._ideas[i];
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	Brain::getIdea(int i) const
{
	return this->_ideas[i];
}

void	Brain::setIdea(int i, std::string idea)
{
	this->_ideas[i] = idea;
}


/* ************************************************************************** */
