#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "colors.hpp"
# include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		const std::string	_name;
		unsigned int _grade;
	public:
	// CONSTRUCTEURS
		Bureaucrat();
		Bureaucrat(std::string name);
		Bureaucrat(std::string name, unsigned int grade);
		Bureaucrat(unsigned int grade);
		Bureaucrat(const Bureaucrat&src);

	// DESTRUCTEURS
		~Bureaucrat();

	// OPERATOR OVERLOAD
		Bureaucrat &operator=(const Bureaucrat&rhs);

	// GETTERS
		std::string const getName() const;
		unsigned int getGrade() const;

	// SETTERS
		void	setGrade(unsigned int grade);

	// METHODS
		void	upgrade();
		void	downgrade();
		void	signForm(Form &form);

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

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

# endif
