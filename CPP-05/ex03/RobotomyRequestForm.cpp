#include "RobotomyRequestForm.hpp"
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("Unknown")
{
	std::cout << "A " << CY << "Robotomy Request Form" << WH << " was created.\n";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "A " << CY << "Robotomy Request Form" << WH << " was created. [target: " << GR << this->_target << WH << "]\n";
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &src) : AForm("RobotomyRequestForm", 72, 45), _target(src.getTarget())
{
	std::cout << "A " << CY << "Robotomy Request Form" << WH << " was created. (copy) [target: " << GR << this->_target << WH << "]\n";
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "A " << CY << "Robotomy Request Form" << WH << " was destroyed.\n";
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm&rhs)
{
	(void)rhs;
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat &executor) const
{
	try
	{
		if (executor.getGrade() > this->getXRequisite())
			throw AForm::GradeTooLowException();
		else if (this->isSigned() == false)
			throw AForm::FormNotSigned();
		else
		{
			std::srand(std::time(0));
			int random = std::rand() % 2;
			if (random == 0)
				std::cout << executor << ": " << GR << this->getTarget() << WH << " was successfully robotomized.\n";
			else
				std::cout << executor << ": " << GR << this->getTarget() << WH << "'s robotomy process failed.\n";
		}

	}
	catch(const std::exception& e)
	{
		std::cout << executor << " couldn't execute form. (grade " << BL << this->getXRequisite() << WH << " needed)\n";
	}
}

std::string RobotomyRequestForm::getTarget(void) const
{
	return this->_target;
}