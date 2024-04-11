#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat *stan = new Bureaucrat("Stan", 65);

	stan->decrementGrade();
	std::cout << *stan << "\n";
	stan->incrementGrade();
	std::cout << *stan << "\n";
	stan->setGrade(150);
	std::cout << *stan << "\n";
	try {	stan->decrementGrade();	}
	catch (Bureaucrat::GradeTooLowException &e)
	{	std::cerr << "Catch! " << e.what() << "\n";	}
	delete stan;
	return 0;
}
