#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("Unknown")
{
	std::cout << "A " << GR << "Shrubbery Creation Form" << WH << " was created.\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "A " << GR << "Shrubbery Creation Form" << WH << " was created. [target: " << GR << this->_target << WH << "]\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &src) : AForm("ShrubberyCreationForm", 145, 137), _target(src.getTarget())
{
	std::cout << "A " << GR << "Shrubbery Creation Form" << WH << " was created. (copy) [target: " << GR << this->_target << WH << "]\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "A " << GR << "Shrubbery Creation Form" << WH << " was destroyed.\n";
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm&rhs)
{
	(void)rhs;
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat &executor) const
{
	std::ofstream o;

	try
	{
		if (executor.getGrade() > this->getXRequisite())
			throw AForm::GradeTooLowException();
		else if (this->isSigned() == false)
			throw AForm::FormNotSigned();
		else
		{
			o.open((this->getTarget() + "_shrubbery").c_str());
			if (o.fail() == false)
			{
				o << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣾⣿⣿⣿⣦⡀⠀⠀⠀⠀⠀\n";
				o << "⠀⠀⠀⢀⣀⣀⡀⠀⢀⣤⣶⠞⠀⠀⠀⢀⣴⣾⣿⣿⣿⣿⣿⣿⣿⣶⣄⠀⠀⠀\n";
				o << "⠀⠀⠀⠉⣛⣿⣿⣿⣿⣿⣷⣶⣶⣦⣄⠘⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀\n";
				o << "⠀⠀⣠⣾⣿⣿⣿⣿⣿⣿⣿⣿⣟⠛⠻⠷⠀⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃⠀⠀\n";
				o << "⠀⣸⠿⠛⣹⣿⣿⣿⣿⣿⠿⢿⣿⣷⠀⠀⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀\n";
				o << "⠀⠁⠀⢰⣿⠟⠁⠀⣿⣿⡀⠀⠈⢻⡇⠀⠸⣿⣿⣿⣿⣿⣿⣿⣿⡿⠁⠀⠀⠀\n";
				o << "⠀⠀⠀⠸⡏⠀⠀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠀⠈⠙⠛⢻⣿⡟⠛⠉⠀⠀⠀⠀⠀\n";
				o << "⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣷⠀⠀⠠⣄⠀⣠⡄⠀⠀⣸⣿⡇⠀⠀⠀⠀⠀⠀⠀\n";
				o << "⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⠀⠻⣷⣿⣿⣿⣶⠟⠀⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀\n";
				o << "⠀⠀⠀⠀⠀⠀⢀⣤⣿⣿⣿⣀⣀⠈⣿⣿⣿⣁⣤⣄⣿⣿⣷⣤⡀⠀⠀⠀⠀⠀\n";
				o << "⠀⠀⠀⠀⠀⣠⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣀⠀⠀⠀⠀\n";
				o << "⠀⠀⠀⠀⠸⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠷⠀⠀⠀\n";
				std::cout << executor << " executed the form.\n";
			}
			else
				std::cout << executor << "couldn't execute form: can't open file.\n";
		}

	}
	catch(const std::exception& e)
	{
		std::cout << executor << " couldn't execute form.\n";
	}
}

std::string ShrubberyCreationForm::getTarget(void) const
{
	return this->_target;
}
