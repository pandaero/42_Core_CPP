/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:48:17 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/14 20:56:31 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"
#include <iostream>
#include <cmath>

//Static variable initialisation
const int	Fixed::fractionalBits = 8;

// PUBLIC
// CANONICAL ORTHODOX CONSTRUCTORS, DESTRUCTOR, and OPERATOR
//Default constructor
Fixed::Fixed(void): value(0)
{

}

//Copy constructor
Fixed::Fixed(const Fixed & fixed)
{
	*this = fixed;
}

//Default destructor
Fixed::~Fixed(void)
{
	
}

//Copy assignment operator overload
Fixed &	Fixed::operator=(const Fixed & other)
{
	if (this != &other)
		this->value = other.getRawBits();
	return (*this);
}

// CUSTOM CONSTRUCTORS
//Constructor using integer input.
Fixed::Fixed(const int value)
{
	Fixed::value = value << Fixed::fractionalBits;
}

//Constructor using floating-point input.
Fixed::Fixed(const float value)
{
	int	fractional;
	Fixed::value = ((int) floor(value)) << Fixed::fractionalBits;

	if (value > 0)
		fractional = (value - (long) value) * 256;
	else if (value < 0)
		fractional = -(value - (long) value) * 256;
	else
		fractional = 0;
	
	if (fractional > 255)
		Fixed::value += 0;
	else
		Fixed::value += fractional;
}

// CUSTOM OPERATOR OVERLOADS
// MEMBER
//Greater than comparison operator.
bool	Fixed::operator>(const Fixed & other)
{
	return (this->value > other.value);
}

//Less than comparison operator.
bool	Fixed::operator<(const Fixed & other)
{
	return (this->value < other.value);
}

//Greater than or equal to comparison operator.
bool	Fixed::operator>=(const Fixed & other)
{
	return (this->value >= other.value);
}

//Less than or equal to comparison operator.
bool	Fixed::operator<=(const Fixed & other)
{
	return (this->value <= other.value);
}

//Equality comparison operator.
bool	Fixed::operator==(const Fixed & other)
{
	return (this->value == other.value);
}

//Inequality comparison operator.
bool	Fixed::operator!=(const Fixed & other)
{
	return (this->value != other.value);
}

//Addition operator.
Fixed	Fixed::operator+(const Fixed & other)
{
	int	integer1 = value >> fractionalBits;
	int	integer2 = other.getRawBits() >> fractionalBits;

	int	mask = fractionalBits * 32 - 1;
	int	fractional1 = value & mask;
	int	fractional2 = other.getRawBits() & mask;

	Fixed	ret;
	ret.setRawBits(((integer1 + integer2) << fractionalBits) + \
					((fractional1 + fractional2) & mask) + \
					(((fractional1 + fractional2) >> fractionalBits) << fractionalBits));
	return (ret);
}

//Subtraction operator.
Fixed	Fixed::operator-(const Fixed & other)
{
	Fixed ret;
	ret.setRawBits(value - other.getRawBits());
	return (ret);
}

//Multiplication operator.
Fixed	Fixed::operator*(const Fixed & other)
{
	Fixed	ret(this->toFloat() * other.toFloat());
	return (ret);
}

//Division operator.
Fixed	Fixed::operator/(const Fixed & other)
{
	Fixed	ret(this->toFloat() / other.toFloat());
	return (ret);
}

//Pre-increment operator overload.
Fixed &	Fixed::operator++()
{
	this->value++;
	return (*this);
}

//Post-increment operator overload.
Fixed	Fixed::operator++(int)
{
	Fixed	copy = *this;

	this->value++;
	return (copy);
}

//Pre-decrement operator overload.
Fixed &	Fixed::operator--()
{
	this->value--;
	return (*this);
}

//Post-decrement operator overload.
Fixed	Fixed::operator--(int)
{
	Fixed	copy = *this;

	this->value--;
	return (copy);
}

// GLOBAL
//Operator overload for stream input.
std::ostream &	operator<<(std::ostream & outStream, const Fixed & fixed)
{
	outStream << fixed.toFloat();
	return (outStream);
}

// MEMBER FUNCTIONS
//Function returns an integer from the stored fixed point value.
int	Fixed::toInt(void) const
{
	int	conversion = this->value >> Fixed::fractionalBits;
	return (conversion);
}

//Function returns a floating point number from the stored fixed point value.
float	Fixed::toFloat(void) const
{
	float	integer, fractional;
	int		sign, mask = Fixed::fractionalBits * 32 - 1;

	sign = 
	integer = this->value >> Fixed::fractionalBits;
		fractional = (float) (this->value & mask) / 256;
	if (this->toInt() > 0)
		return (integer + fractional);
	else if (this->toInt() < 0)
		return (integer - fractional + 1);
	else
		return (fractional);
}

//Function returns the value of the raw bits contained in the number.
int		Fixed::getRawBits(void) const
{
	return (this->value);
}

//Function sets the value of number by passing raw bits.
void	Fixed::setRawBits(const int raw)
{
	this->value = raw;
}
