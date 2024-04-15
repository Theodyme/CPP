#include "Form.hpp"

/*                                CONSTRUCTEURS                               */

Form::Form() : _name("A random boring form"), _is_signed(false), _x_requisite(0), _s_requisite(0)
{
	std::cout << RE << *this << WH << " constructor called.\n";
}

Form::Form(std::string name, unsigned int x_requisite, unsigned int s_requisite) : _name(name), _is_signed(false)
{
	try
	{
		if (x_requisite < 1 || s_requisite < 1)
			throw Form::GradeTooHighException();
		else if (x_requisite > 150 || s_requisite > 150)
			throw Form::GradeTooLowException();
		this->_x_requisite = x_requisite;
		this->_s_requisite = s_requisite;
		std::cout << RE << *this << WH << " constructor called.\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << "Couldn't construct Form : " << e.what() << '\n';
	}
}

Form::Form(const Form&src) : _name(src.getName()), _x_requisite(src.getXRequisite()), _s_requisite(src.getSRequisite())
{
	this->_is_signed = src.isSigned();
}

/////////// REPRENDRE A PARTIR DE LAAAAAAAAA //////////////

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



/*                                   SETTERS                                  */



/*                                   METHODS                                  */

/*                                 EXCEPTIONS                                 */

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low!";
}
