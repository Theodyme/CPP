#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	try
	{
		Bureaucrat	bureaucrat1("Pippin", 4);
		Bureaucrat	bureaucrat2("Bubu", 124);
	//	AForm		AForm1("Alpha", 1, 41);

		ShrubberyCreationForm treeForm("some_dude");
		std::cout << treeForm << std::endl;
		std::cout << bureaucrat1 << std::endl;
		std::cout << bureaucrat2 << std::endl;
		// treeForm.beSigned(bureaucrat2);
		bureaucrat2.signAForm(treeForm);
		bureaucrat1.executeForm(treeForm);
		// treeForm.execute(bureaucrat1);
		bureaucrat1.signAForm(treeForm);
		// treeForm.execute(bureaucrat2);
		bureaucrat2.executeForm(treeForm);
		// treeForm.execute(bureaucrat1);
		bureaucrat1.executeForm(treeForm);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	return (0);

}
