#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("Unknown")
{
	std::cout << "A " << CY << "Presidential Pardon Form" << WH << " was created.\n";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "A " << CY << "Presidential Pardon Form" << WH << " was created. [target: " << GR << this->_target << WH << "]\n";
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &src) : AForm("PresidentialPardonForm", 25, 5), _target(src.getTarget())
{
	std::cout << "A " << CY << "Presidential Pardon Form" << WH << " was created. (copy) [target: " << GR << this->_target << WH << "]\n";
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "A " << CY << "Presidential Pardon Form" << WH << " was destroyed.\n";
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm&rhs)
{
	(void)rhs;
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat &executor) const
{
	try
	{
		if (executor.getGrade() > this->getXRequisite())
			throw AForm::GradeTooLowException();
		else if (this->isSigned() == false)
			throw AForm::FormNotSigned();
		else
			std::cout << GR << this->getTarget() << WH << " has been pardoned by Zaphod Beeblebrox.\n";
	}
	catch(const std::exception& e)
	{
		std::cout << executor << " couldn't execute form.\n";
	}
}

std::string PresidentialPardonForm::getTarget(void) const
{
	return this->_target;
}