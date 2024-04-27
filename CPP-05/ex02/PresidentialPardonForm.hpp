
#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		const std::string _target;
		PresidentialPardonForm();
	public:
	// CONSTRUCTEURS
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm &src);
	// DESTRUCTEURS
		~PresidentialPardonForm();
	// OPERATOR OVERLOAD
		PresidentialPardonForm &operator=(const PresidentialPardonForm&rhs);
	// METHODES
		void execute(Bureaucrat &executor) const;
	// GETTERS
		std::string getTarget(void) const;
};

#endif