#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "colors.hpp"

class Bureaucrat
{
	private:
		const std::string	_name;
		unsigned int _grade;
	public:
	// CONSTRUCTEURS
		Bureaucrat();
		Bureaucrat(std::string name);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(int grade);
		Bureaucrat(const Bureaucrat&src);

	// DESTRUCTEURS
		~Bureaucrat();

	// OPERATOR OVERLOAD
		Bureaucrat &operator=(const Bureaucrat&rhs);

	// GETTERS
		std::string const getName() const;
		size_t getGrade() const;

	// SETTERS
		void	setGrade(int grade);

	// METHODS
		void	upgrade();
		void	downgrade();

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
