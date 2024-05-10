#include "Intern.hpp"

/*                                CONSTRUCTEURS                               */

Intern::Intern()
{
	std::cout << YE << "An intern" << WH << " has been recruited.\n";
}

Intern::Intern(const Intern&src)
{
	(void)src;
	std::cout << YE << "An intern" << WH << " has been recruited from the same school as the previous one.\n";
}
/*                                DESTRUCTEURS                                */

Intern::~Intern()
{
	std::cout << YE << "An intern" << WH << " has been fired.\n";
}
/*                              OPERATOR OVERLOAD                             */

Intern &Intern::operator=(const Intern&rhs)
{
	(void)rhs;
	return *this;
}

/*                                   METHODS                                  */

static AForm *createPardon(const std::string target)
{
	return new PresidentialPardonForm(target);
}
static AForm *createForest(const std::string target)
{
	return new ShrubberyCreationForm(target);
}
static AForm *createRobot(const std::string target)
{
	return new RobotomyRequestForm(target);
}

const char* Intern::InvalidFormName::what() const throw()
{
	return "Invalid form name!";
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	AForm *(*exec_menu[3])(const std::string target) = {&createForest, &createRobot, &createPardon};
    std::string form_names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    for (int i = 0; i < 3; i++)
    {
        if (!name.compare(form_names[i]))
            return exec_menu[i](target);
    }
	throw Intern::InvalidFormName();
	return 0;
}
