#include "Span.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Span::Span(): _max(0)
{
}

Span::Span(unsigned int N): _max(N)
{
}

Span::Span(const Span&src)
{
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Span::~Span()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Span	&Span::operator=(Span const &rhs)
{
	(void)rhs;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Span::addNumber(int n)
{
	if (this->_values.size() < this->_max)
		this->_values.push_back(n);
	else
		throw std::logic_error("Max size reached.\n");
}

unsigned int Span::shortestSpan()
{
	if (this->_values.size() <= 1)
		throw std::logic_error("No bounds to be found\n");
	std::vector<int> sorted(this->_values);
	std::sort(sorted.begin(), sorted.end());
	int shortest = sorted.size();
	for (std::vector<int>::iterator it = sorted.begin(); it != sorted.end(); ++it)
	{
		if (shortest > abs(*it - (*it + 1)))
			shortest = abs(*it - (*it + 1));
	}
	return shortest;
}

unsigned int Span::longestSpan()
{
	if (this->_values.size() <= 1)
		throw std::logic_error("No bounds to be found\n");
	std::vector<int>::iterator max = std::max_element(this->_values.begin(), this->_values.end());
	std::vector<int>::iterator min = std::min_element(this->_values.begin(), this->_values.end());
	return (abs(*max - *min));
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
