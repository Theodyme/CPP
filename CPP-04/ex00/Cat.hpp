#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(Cat const &src);
		~Cat();
		Cat &operator=(Cat const &rhs);
	private:
};

std::ostream &operator<<(std::ostream &o, Cat const &instance);


#endif /* ************************************************************* CAT_HPP */
