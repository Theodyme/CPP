#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat	bureaucrat1("Emma", 2);
	Bureaucrat	bureaucrat2("Arthur", 150);
	Bureaucrat	bureaucrat3("Antoine", 151);
	Bureaucrat	bureaucrat4("Tokyo", 0);
	Bureaucrat	bureaucrat5(bureaucrat1);
	
	std::cout << "Voici notre première bureaucrate: ";
	std::cout << bureaucrat1 << std::endl;
	std::cout << "Essayons de lui donner une promotion.\n";
	bureaucrat1.upgrade();
	std::cout << bureaucrat1 << std::endl;
	std::cout << "Parfait.\nCECI EST UNE DEEP COPIE !! : " << bureaucrat5 << std::endl;
	//Error
	std::cout << "Essayons d'offrir une autre promotion à notre " << bureaucrat1 << " :\n";
	bureaucrat1.upgrade();
	std::cout << bureaucrat1 << std::endl;

	std::cout << bureaucrat2 << std::endl;
	//Error
	bureaucrat2.downgrade();
	std::cout << bureaucrat2 << std::endl;
	
	return (0);
}

// int	main()
// {
// 	Bureaucrat *stan = new Bureaucrat("Stan", 65);

// 	stan->decrementGrade();
// 	std::cout << *stan << "\n";
// 	stan->incrementGrade();
// 	std::cout << *stan << "\n";
// 	stan->setGrade(150);
// 	std::cout << *stan << "\n";
// 	try {	stan->decrementGrade();	}
// 	catch (Bureaucrat::GradeTooLowException &e)
// 	{	std::cerr << "Catch! " << e.what() << "\n";	}
// 	delete stan;
// 	return 0;
// }
