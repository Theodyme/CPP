#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class Bureaucrat
{
	private:
		const std::string	_name;
		size_t _grade;
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
		std::string const &getName() const;
		size_t getGrade() const;

	// SETTERS
		void	setGrade(int i);
	
	// METHODS
		void	incrementGrade();
		void	decrementGrade();
	
	// EXCEPTIONS
	class GradeTooHighException : public std::exception
	{
		public:

	};

	class GradeTooLowException : public std::exception
	{
		public:

	};

};

	std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

# endif