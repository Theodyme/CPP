#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact	contacts[8];
		int		idx;
	public:
		void	add();
		void	search();
		void	display();
};
