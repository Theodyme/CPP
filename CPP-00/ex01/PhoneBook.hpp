#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact	contacts[8];
		int		idx;
		int		cnt;
	public:
		PhoneBook() : idx(0), cnt(0) {};
		void	add();
		void	search();
		void	display();
		void	show_contact(int idx);
};
