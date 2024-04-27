#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat	bureaucrat1("Pippin", 42);
	Bureaucrat	bureaucrat2("Bubu", 124);
	Form		form1("Alpha", 1, 41);
	Form		form2("Beta", 1, 140);
	Form		form3("Charlie", 151, 1);

	std::cout << "\n";
	std::cout << bureaucrat1 << std::endl;
	std::cout << form1 << std::endl;
	bureaucrat1.signForm(form1);
	std::cout << form1 << std::endl;
	std::cout << "\n";
	bureaucrat1.upgrade();
	std::cout << bureaucrat1 << std::endl;
	bureaucrat1.signForm(form1);
	std::cout << form1 << std::endl << form2 << std::endl;
	std::cout << "\n";
	return (0);

}