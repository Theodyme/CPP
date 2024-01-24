#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>
# include "colors.hpp"

class Animal
{
	protected:
		std::string _type;
	public:
		Animal();
		Animal(Animal const &src);
		virtual ~Animal();
		Animal &operator=(Animal const &rhs);

		std::string	getType() const;
		void		setType(std::string type);

		virtual void	makeSound() const = 0;
};


#endif /* ************************************************************* ANIMAL_HPP */
