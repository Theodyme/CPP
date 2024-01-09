#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact	contacts[8];
		int		idx;
	public:
		PhoneBook() : idx(0) {};
		void	add();
		void	search();
		void	display();
		void	show_contact(int idx);
		int		get_size();
};
