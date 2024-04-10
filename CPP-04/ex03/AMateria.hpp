#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>
# include "colors.hpp"
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		const std::string	_type;
	public:
		AMateria();
		AMateria(std::string const & type);
		AMateria(const AMateria&src);
		virtual ~AMateria();
		// virtual AMateria & operator=(AMateria const & ref);
		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif