#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
	private:
		std::string	_type;
	public:
		Ice();
		~Ice();
		Ice(const Ice&src);
		Ice & operator=(Ice const & rhs);
		void use(ICharacter& target);
		Ice* clone() const;
};

#endif