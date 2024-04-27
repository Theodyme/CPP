
#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <cstdlib>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		const std::string _target;
		RobotomyRequestForm();
	public:
	// CONSTRUCTEURS
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm &src);
	// DESTRUCTEURS
		~RobotomyRequestForm();
	// OPERATOR OVERLOAD
		RobotomyRequestForm &operator=(const RobotomyRequestForm&rhs);
	// METHODES
		void execute(Bureaucrat &executor) const;
	// GETTERS
		std::string getTarget(void) const;
};

#endif