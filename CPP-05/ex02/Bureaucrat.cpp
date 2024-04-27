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

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _name(name)
{
	try
	{
		if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		this->_grade = grade;
		std::cout << RE << *this << WH << " constructor called.\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << "Couldn't construct Bureaucrate : " << e.what() << '\n';
	}
}

Bureaucrat::Bureaucrat(unsigned int grade) : _name("John Doe")
{
	try
	{
		if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		this->_grade = grade;
		std::cout << RE << *this << WH << " constructor called.\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << "Couldn't construct Bureaucrate : " << e.what() << '\n';
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat&src) : _name(src.getName())
{
	this->setGrade(src.getGrade());
}

/*                                DESTRUCTEURS                                */

Bureaucrat::~Bureaucrat()
{
	std::cout << RE << this->_name << WH << " destructor called.\n";
}

/*                              OPERATOR OVERLOAD                             */

Bureaucrat &Bureaucrat::operator=(const Bureaucrat&rhs)
{
	if (this == &rhs)
		return *this;
	this->_grade = rhs.getGrade();
	return *this;
}

std::ostream& operator<<(std::ostream& o, const Bureaucrat&person)
{
	o << RE << person.getName() << ", bureaucrat grade " << person.getGrade()<< WH;
	return o;
}

/*                                   GETTERS                                  */

std::string const Bureaucrat::getName() const
{
	return this->_name;
}

unsigned int Bureaucrat::getGrade() const
{
	return this->_grade;
}

/*                                   SETTERS                                  */

void	Bureaucrat::setGrade(unsigned int grade)
{
	try
	{
		if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else
			this->_grade = grade;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

/*                                   METHODS                                  */

void	Bureaucrat::upgrade()
{
	this->setGrade(this->getGrade() - 1);
}

void	Bureaucrat::downgrade()
{
	this->setGrade(this->getGrade() + 1);
}

void	Bureaucrat::signAForm(AForm &AForm)
{
	AForm.beSigned(*this);
}

void	Bureaucrat::executeForm(AForm &AForm)
{
	AForm.execute(*this);
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
