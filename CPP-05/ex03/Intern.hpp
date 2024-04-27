#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "colors.hpp"
# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class AForm;

class Bureaucrat;

class Intern
{
	private:
	public:
	// CONSTRUCTEURS
		Intern();
		Intern(const Intern&src);
	// DESTRUCTEURS
		~Intern();
	// OPERATOR OVERLOAD
		Intern &operator=(const Intern&rhs);
	// METHODS
		AForm *makeForm(std::string name, std::string target);
};

# endif
