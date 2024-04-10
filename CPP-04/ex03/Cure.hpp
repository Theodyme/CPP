#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
	private:
		std::string	_type;
	public:
		Cure();
		~Cure();
		Cure(const Cure&src);
		Cure & operator=(Cure const & rhs);
		void use(ICharacter& target);
		Cure* clone() const;
};

#endif