#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
	protected:
		std::string _type;
	public:
		Animal();
		Animal(Animal const &src);
		~Animal();
		Animal &operator=(Animal const &rhs);

		std::string	getType();
		void	makeSound();
};

std::ostream &operator<<(std::ostream &o, Animal const &instance);


#endif /* ************************************************************* ANIMAL_HPP */
