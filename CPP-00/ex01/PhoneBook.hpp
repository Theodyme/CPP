#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact	contacts[8];
		int		idx;
		int		cnt;
	public:
		PhoneBook();
		void	add();
		void	search();
		void	display();
		void	show_contact(int idx);
};
