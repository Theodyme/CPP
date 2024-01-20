#pragma once

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
	int					_fixed_val;
	static const int	_size = 8;
public:
	Fixed();
	Fixed(const int nbr);
	Fixed(const float nbr);
	Fixed(Fixed const &src);
	~Fixed();
	Fixed&	operator=(const Fixed& rhs);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
};

std::ostream& operator<<(std::ostream& o, const Fixed& data);

#endif
