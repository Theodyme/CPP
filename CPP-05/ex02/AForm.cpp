#include "AForm.hpp"

/*                                CONSTRUCTEURS                               */

AForm::AForm() : _name("A random boring AForm"), _is_signed(false), _x_requisite(150), _s_requisite(150)
{
	std::cout << *this << " constructor called.\n";
}

AForm::AForm(std::string name, unsigned int x_requisite, unsigned int s_requisite) : _name(name), _is_signed(false), _x_requisite(x_requisite), _s_requisite(s_requisite)
{
	try
	{
		if (x_requisite < 1 || s_requisite < 1)
			throw AForm::GradeTooHighException();
		else if (x_requisite > 150 || s_requisite > 150)
			throw AForm::GradeTooLowException();
		std::cout << *this << " constructor called.\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << "Couldn't construct AForm : " << e.what() << '\n';
	}
}

AForm::AForm(const AForm&src) : _name(src.getName()), _x_requisite(src.getXRequisite()), _s_requisite(src.getSRequisite())
{
	this->_is_signed = src.isSigned();
}

/*                                DESTRUCTEURS                                */

AForm::~AForm()
{
	std::cout << BL << this->_name << WH << " AForm destructor called.\n";
}

/*                              OPERATOR OVERLOAD                             */

AForm &AForm::operator=(const AForm&rhs)
{
	if (this == &rhs)
		return *this;
	this->_is_signed = rhs.isSigned();
	return *this;
}

std::ostream& operator<<(std::ostream& o, const AForm&AForm)
{
	o << "[" << BL << AForm.getName() << WH << " AForm: ";
	if (AForm.isSigned())
		o << BL << "signed, ";
	else
		o << BL << "unsigned, ";
	o << AForm.getSRequisite() << WH << " required to sign, ";
	o << BL << AForm.getXRequisite() << WH << " required to execute.]";
	return o;
}

/*                                   GETTERS                                  */

std::string const AForm::getName() const
{
	return this->_name;
}

bool AForm::isSigned() const
{
	return this->_is_signed;
}

unsigned int AForm::getXRequisite() const
{
	return this->_x_requisite;
}

unsigned int AForm::getSRequisite() const
{
	return this->_s_requisite;
}

/*                                   SETTERS                                  */

void	AForm::beSigned(Bureaucrat &employee)
{
	try
	{
		if (employee.getGrade() > this->getSRequisite())
		{
			throw AForm::GradeTooLowException();
		}
		else {
			if (this->_is_signed)
				std::cout << "This [" << BL << this->_name << WH << " AForm] is already signed!\n";
			else
			{
				std::cout << "[" << BL << this->_name << " AForm" << WH << "] has been signed by " << employee << ".\n";
				this->_is_signed = true;
			}
		}
	}
	catch(const std::exception& e)
	{
		std::cout << employee << "'s grade is too low to sign [" << BL << this->_name << WH << " AForm]! (grade " << BL << this->getSRequisite() << WH << " needed)\n";
	}
}

/*                                   METHODS                                  */

/*                                 EXCEPTIONS                                 */

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low!";
}

const char* AForm::FormNotSigned::what() const throw()
{
	return "Form is not signed!";
}
