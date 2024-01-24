#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>
# include "colors.hpp"

class WrongAnimal
{
	protected:
		std::string _type;
	public:
		WrongAnimal();
		WrongAnimal(WrongAnimal const &src);
		~WrongAnimal();
		WrongAnimal &operator=(WrongAnimal const &rhs);

		std::string	getType() const;
		void 		setType(std::string type);

		void		makeSound() const;
};

#endif /* ************************************************************* WRONGANIMAL_HPP */
