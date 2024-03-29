#pragma once

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
	int					_value;
	static const int	_size = 8;
public:
	Fixed();
	Fixed(Fixed const &src);
	~Fixed();
	Fixed&	operator=(const Fixed& rhs);

	int		getRawBits(void) const;

	void	setRawBits(int const raw);
};
#endif
