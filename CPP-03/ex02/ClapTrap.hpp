#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
	protected:
		std::string	_name;
		unsigned int			_hitpts;
		unsigned int			_energy;
		unsigned int			_attack_dmg;
	public:
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const &src);
		~ClapTrap();
		ClapTrap &operator=(ClapTrap const &rhs);

		std::string	getName();
		unsigned int	getHitpts();
		unsigned int	getEnergy();
		unsigned int	getDamage();

		void	setHitpts(unsigned int amount);
		void	setEnergy(unsigned int amount);
		void	setDamage(unsigned int amount);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif /* ************************************************************* CLAPTRAP_HPP */
