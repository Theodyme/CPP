#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <fstream>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		const std::string _target;
		ShrubberyCreationForm();
	public:
	// CONSTRUCTEURS
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm &src);
	// DESTRUCTEURS
		~ShrubberyCreationForm();
	// OPERATOR OVERLOAD
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm&rhs);
	// METHODES
		void execute(Bureaucrat &executor) const;
	// GETTERS
		std::string getTarget(void) const;
};

#endif