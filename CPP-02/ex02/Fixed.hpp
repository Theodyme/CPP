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
	Fixed	operator+(const Fixed& rhs) const;
	Fixed	operator-(const Fixed& rhs) const;
	Fixed	operator/(const Fixed& rhs) const;
	Fixed	operator*(const Fixed& rhs) const;

	bool	operator>(const Fixed& rhs) const;
	bool	operator<(const Fixed& rhs) const;
	bool	operator>=(const Fixed& rhs) const;
	bool	operator<=(const Fixed& rhs) const;
	bool	operator==(const Fixed& rhs) const;
	bool	operator!=(const Fixed& rhs) const;

	Fixed	operator++(int);
	Fixed	operator--(int);
	Fixed&	operator++();
	Fixed&	operator--();




	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
	static Fixed min(Fixed& a, Fixed& b);
	static Fixed min(const Fixed& a, const Fixed& b);
	static Fixed max(Fixed& a, Fixed& b);
	static Fixed max(const Fixed& a, const Fixed& b);

};

std::ostream& operator<<(std::ostream& o, const Fixed& data);

#endif
