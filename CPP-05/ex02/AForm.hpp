#ifndef AForm_HPP
# define AForm_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"
# include "colors.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool _is_signed;
		const unsigned int	_x_requisite;
		const unsigned int	_s_requisite;
	public:
	// CONSTRUCTEURS
		AForm();
		AForm(std::string name, unsigned int x_requisite, unsigned int s_requisite);
		AForm(const AForm&src);
	// DESTRUCTEURS
		virtual ~AForm();

	// OPERATOR OVERLOAD
		AForm &operator=(const AForm&rhs);

	// GETTERS
		std::string const getName() const;
		bool isSigned() const;
		unsigned int getXRequisite() const;
		unsigned int getSRequisite() const;

	// SETTERS
		void	beSigned(Bureaucrat &employee);

		virtual void execute(Bureaucrat &executor) const = 0;

	// EXCEPTIONS
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

	class FormNotSigned : public std::exception
	{
		public:
			virtual const char* what() const throw();

	};

};

std::ostream& operator<<(std::ostream& os, const AForm& AForm);

# endif
