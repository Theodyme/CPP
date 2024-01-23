#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
	public:
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const &src);
		~ScavTrap();
		ScavTrap &operator=(ScavTrap const &rhs);

		void	guardGate();
};



#endif /* ************************************************************* SCAVTRAP_HPP */
