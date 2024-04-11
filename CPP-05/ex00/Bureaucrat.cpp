#include "Bureaucrat.hpp"

// CONSTRUCTEURS
Bureaucrat::Bureaucrat() : _name("John Doe"), _grade(150)
{

}

Bureaucrat::Bureaucrat(std::string name) : _name(name), _grade(150)
{

}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	this->setGrade(grade);
}

Bureaucrat::Bureaucrat(int grade) : _name("John Doe"), _grade(grade)
{
	this->setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat&src)
{
	this->setGrade(src.getGrade());
	this->_name = src.getName();
}

// DESTRUCTEURS
Bureaucrat::~Bureaucrat()
{
	std::cout << 
}

// OPERATOR OVERLOAD
Bureaucrat &Bureaucrat::operator=(const Bureaucrat&rhs)
{

}

std::ostream& operator<<(std::ostream& os, const Bureaucrat&person)
{
	os << person.getName() << ", bureaucrat grade " << person.getGrade();
	return os;
}

// GETTERS
std::string const &Bureaucrat::getName() const
{
	return this->_name;
}

size_t Bureaucrat::getGrade() const
{
	return this->_grade;
}

// SETTERS
void	Bureaucrat::setGrade(int i)
{
	this->_grade = i;
}

// METHODS
void	Bureaucrat::incrementGrade()
{
	this->setGrade(this->getGrade() - 1);
}

void	Bureaucrat::decrementGrade()
{
	this->setGrade(this->getGrade() + 1);
}