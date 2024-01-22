#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>

class Dog
{
	public:
		Dog();
		Dog(Dog const &src);
		~Dog();
		Dog &operator=(Dog const &rhs);
	private:
};

std::ostream &operator<<(std::ostream &o, Dog const &instance);


#endif /* ************************************************************* DOG_HPP */
