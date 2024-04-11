#include "Bureaucrat.hpp"

/*                                CONSTRUCTEURS                               */

Bureaucrat::Bureaucrat() : _name("John Doe"), _grade(150)
{
	std::cout << RE << *this << WH << " constructor called.\n";
}

Bureaucrat::Bureaucrat(std::string name) : _name(name), _grade(150)
{
	std::cout << RE << *this << WH << " constructor called.\n";
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	this->setGrade(grade);
	std::cout << RE << *this << WH << " constructor called.\n";
}

Bureaucrat::Bureaucrat(int grade) : _name("John Doe"), _grade(grade)
{
	this->setGrade(grade);
	std::cout << RE << *this << WH << " constructor called.\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat&src)
{
	this->setGrade(src.getGrade());
	this->_name = src.getName();
}

/*                                DESTRUCTEURS                                */

Bureaucrat::~Bureaucrat()
{
	std::cout << RE << *this << WH << " destructor called.\n";
}

/*                              OPERATOR OVERLOAD                             */

Bureaucrat &Bureaucrat::operator=(const Bureaucrat&rhs)
{
	if (this == &rhs)
		return *this;
	this->_grade = rhs.getGrade();
	this->_name = rhs.getName();
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat&person)
{
	os << person.getName() << ", bureaucrat grade " << person.getGrade();
	return os;
}

/*                                   GETTERS                                  */

std::string const &Bureaucrat::getName() const
{
	return this->_name;
}

size_t Bureaucrat::getGrade() const
{
	return this->_grade;
}

/*                                   SETTERS                                  */

void	Bureaucrat::setGrade(int i)
{
	if (i < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (i > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = i;
}

/*                                   METHODS                                  */

void	Bureaucrat::incrementGrade()
{
	this->setGrade(this->getGrade() - 1);
}

void	Bureaucrat::decrementGrade()
{
	this->setGrade(this->getGrade() + 1);
}

/*                                 EXCEPTIONS                                 */

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low!";
}
