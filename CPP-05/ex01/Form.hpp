#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"
# include "colors.hpp"

class Form
{
	private:
		const std::string	_name;
		bool _is_signed;
		const unsigned int	_x_requisite;
		const unsigned int	_s_requisite;
	public:
	// CONSTRUCTEURS
		Form();
		Form(const Form&src);
	// DESTRUCTEURS
		~Form();

	// OPERATOR OVERLOAD
		Form &operator=(const Form&rhs);

	// GETTERS
		std::string const getName() const;
		bool isSigned() const;
		unsigned int getXRequisite() const;
		unsigned int getSRequisite() const;

	// SETTERS
		void	beSigned();
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw();

	};

};

std::ostream& operator<<(std::ostream& os, const Form& form);

# endif
