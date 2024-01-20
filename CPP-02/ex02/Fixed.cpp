#include "Fixed.hpp"
#include <cmath>

/* -------------------------------- CONSTRUCTORS ----------------------------- */

Fixed::Fixed() : _fixed_val(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int nbr)
{
	// std::cout << "Int constructor called" << std::endl;
	this->_fixed_val = nbr << Fixed::_size;
}

Fixed::Fixed(const float nbr)
{
	// std::cout << "Float constructor called" << std::endl;
	this->_fixed_val = roundf(nbr * (1 << Fixed::_size));
}

Fixed::Fixed(Fixed const &src)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

/* --------------------------------- DESTRUCTOR ------------------------------ */

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

/* --------------------------------- OPERATOR -------------------------------- */

Fixed&	Fixed::operator=(const Fixed& rhs)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	this->_fixed_val = rhs.getRawBits();
	return (*this);
}

Fixed	Fixed::operator+(const Fixed& rhs) const
{
	Fixed result;
	result._fixed_val = this->_fixed_val + rhs._fixed_val;
	return result;
}

Fixed	Fixed::operator-(const Fixed& rhs) const
{
	Fixed result;
	result._fixed_val = this->_fixed_val - rhs._fixed_val;
	return result;
}

Fixed	Fixed::operator/(const Fixed& rhs) const
{
	Fixed result;
	result.setRawBits(this->getRawBits() / (rhs.getRawBits() >> Fixed::_size));
	// result._fixed_val = this->_fixed_val / rhs._fixed_val;
	return result;
}

Fixed	Fixed::operator*(const Fixed& rhs) const
{
	Fixed result;
	result.setRawBits(this->getRawBits() * (rhs.getRawBits() >> Fixed::_size));
	// result._fixed_val = this->_fixed_val * rhs._fixed_val;
	return result;
}

bool	Fixed::operator>(const Fixed& rhs) const
{
	return (this->_fixed_val > rhs._fixed_val);
}

bool	Fixed::operator<(const Fixed& rhs) const
{
	return (this->_fixed_val < rhs._fixed_val);
}

bool	Fixed::operator>=(const Fixed& rhs) const
{
	return (this->_fixed_val >= rhs._fixed_val);
}

bool	Fixed::operator<=(const Fixed& rhs) const
{
	return (this->_fixed_val <= rhs._fixed_val);

}

bool	Fixed::operator==(const Fixed& rhs) const
{
	return (this->_fixed_val == rhs._fixed_val);

}

bool	Fixed::operator!=(const Fixed& rhs) const
{
	return (this->_fixed_val != rhs._fixed_val);

}

Fixed	Fixed::operator++(int)
{
	Fixed old = *this;
	this->_fixed_val++;
	return (old);
	// this->_fixed_val++;
	// return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed old = *this;
	this->_fixed_val--;
	return (old);
}

Fixed&	Fixed::operator++()
{
	// Fixed old = *this;
	// this->_fixed_val++;
	// return (old);
	this->_fixed_val++;
	return (*this);
}

Fixed&	Fixed::operator--()
{
	this->_fixed_val--;
	return (*this);
}

std::ostream& operator<<(std::ostream& o, const Fixed& data)
{
	o << data.toFloat();
	return (o);
}


/* ----------------------------- MEMBERS FUNCTIONS --------------------------- */


int		Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixed_val);
}

void	Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
	this->_fixed_val = raw;
}
float	Fixed::toFloat(void) const
{
	return ((float)(this->_fixed_val) / (1 << Fixed::_size));
}

int		Fixed::toInt(void) const
{
	return (this->_fixed_val >> Fixed::_size);
}

Fixed Fixed::min(Fixed& a, Fixed& b)
{
	return (a > b) ? b : a ;
}

Fixed Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a > b) ? b : a ;
}

Fixed Fixed::max(Fixed& a, Fixed& b)
{
	return (a < b) ? b : a ;
}

Fixed Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a < b) ? b : a ;
}
