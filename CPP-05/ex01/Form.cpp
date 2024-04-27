#include "Form.hpp"

/*                                CONSTRUCTEURS                               */

Form::Form() : _name("A random boring form"), _is_signed(false), _x_requisite(0), _s_requisite(0)
{
	std::cout << *this << " constructor called.\n";
}

Form::Form(std::string name, unsigned int x_requisite, unsigned int s_requisite) : _name(name), _is_signed(false), _x_requisite(x_requisite), _s_requisite(s_requisite)
{
	try
	{
		if (x_requisite < 1 || s_requisite < 1)
			throw Form::GradeTooHighException();
		else if (x_requisite > 150 || s_requisite > 150)
			throw Form::GradeTooLowException();
		std::cout << *this << " constructor called.\n";
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

/*                                DESTRUCTEURS                                */

Form::~Form()
{
	std::cout << BL << this->_name << WH << " form destructor called.\n";
}

/*                              OPERATOR OVERLOAD                             */

Form &Form::operator=(const Form&rhs)
{
	if (this == &rhs)
		return *this;
	this->_is_signed = rhs.isSigned();
	return *this;
}

std::ostream& operator<<(std::ostream& o, const Form&form)
{
	o << "[" << BL << form.getName() << WH << " form: ";
	if (form.isSigned())
		o << BL << "signed, ";
	else
		o << BL << "unsigned, ";
	o << form.getSRequisite() << WH << " required to sign, ";
	o << BL << form.getXRequisite() << WH << " required to execute.]";
	return o;
}

/*                                   GETTERS                                  */

std::string const Form::getName() const
{
	return this->_name;
}

bool Form::isSigned() const
{
	return this->_is_signed;
}

unsigned int Form::getXRequisite() const
{
	return this->_x_requisite;
}

unsigned int Form::getSRequisite() const
{
	return this->_s_requisite;
}

/*                                   SETTERS                                  */

void	Form::beSigned(Bureaucrat &employee)
{
	try
	{
		if (employee.getGrade() > this->getSRequisite())
		{
			throw Form::GradeTooLowException();
		}
		else {
			if (this->_is_signed)
				std::cout << "This [" << BL << this->_name << WH << " form] is already signed!\n";
			else
			{
				std::cout << "[" << BL << this->_name << " form" << WH << "] has been signed by " << employee << ".\n";
				this->_is_signed = true;
			}
		}
	}
	catch(const std::exception& e)
	{
		std::cout << employee << "'s grade is too low to sign [" << BL << this->_name << WH << " form]! (grade " << BL << this->getSRequisite() << WH << " needed)\n";
	}
}

/*                                   METHODS                                  */

/*                                 EXCEPTIONS                                 */

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade too low!";
}
