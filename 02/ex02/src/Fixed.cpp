/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:48:17 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/15 11:14:07 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"
#include <iostream>
#include <bitset>
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
	int	numbmask = 0x7FFFFFFF;
	int	sign;

	(value >= 0) ? sign = 0 : sign = 1;
	Fixed::value = sign * 0x80000000;

	if (value < 0)
		Fixed::value += (((int) -value) & numbmask) << fractionalBits;
	else if (value > 0)
		Fixed::value += ((int) value) << fractionalBits;
	else
	{
		Fixed::value = 0;
		return;
	}
	
	if (value > 0)
		fractional = (value - floor(value)) * 256;
	else if (value < 0)
		fractional =  (-value - floor(-value)) * 256;
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
	Fixed	ret(this->toFloat() + other.toFloat());
	return (ret);
}

//Subtraction operator.
Fixed	Fixed::operator-(const Fixed & other)
{
	Fixed	ret(this->toFloat() - other.toFloat());
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
	int	sign = (value & 0x80000000) >> 31;

	sign ? value-- : value++;
	return (*this);
}

//Post-increment operator overload.
Fixed	Fixed::operator++(int)
{
	Fixed	copy = *this;
	int	sign = (value & 0x80000000) >> 31;

	sign ? value-- : value++;
	return (copy);
}

//Pre-decrement operator overload.
Fixed &	Fixed::operator--()
{
	int	sign = (value & 0x80000000) >> 31;
	
	sign ? value++ : value--;
	return (*this);
}

//Post-decrement operator overload.
Fixed	Fixed::operator--(int)
{
	Fixed	copy = *this;
	int	sign = (value & 0x80000000) >> 31;

	sign ? value++ : value--;
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
	int	signmask = 0x80000000;
	int	uintmask = 0x7FFFFF00;
	int	fracmask = 0xFF;

	int	integer;
	int	sign = (value & signmask) >> 31;
	int	whole = (value & uintmask) >> fractionalBits;
	sign ? integer = -1 * whole : integer = whole;

	int	fract = (value & fracmask);
	if (fract >= 128)
		integer++;
	return (integer);
}

//Function returns a floating point number from the stored fixed point value.
float	Fixed::toFloat(void) const
{
	int		negative = (value & 0x80000000) >> 31;
	int		uintmask = 0x7FFFFF00;
	int		fracmask = 0xFF;
	float	entire, fractional;

	int uinteger = ((value & uintmask) >> 8);
	negative ? entire = (float) -1 * uinteger : entire = (float) uinteger;

	fractional = ((float) (value & fracmask)) / ((float) 0x100);
	negative ? entire -= fractional : entire += fractional;
	return (entire);
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

//Function returns the smaller of two fixed-point numbers.
Fixed &	Fixed::min(Fixed & num1, Fixed & num2)
{
	if (num1.toFloat() > num2.toFloat())
		return num2;
	else
		return num1;
}

//Function returns the smaller of two fixed-point numbers.
const Fixed &	Fixed::min(const Fixed & num1, const Fixed & num2)
{
	if (num1.toFloat() > num2.toFloat())
		return num2;
	else
		return num1;
}

//Function returns the larger of two fixed-point numbers.
Fixed &	Fixed::max(Fixed & num1, Fixed & num2)
{
	if (num1.toFloat() > num2.toFloat())
		return num1;
	else
		return num2;
}

//Function returns the larger of two fixed-point numbers.
const Fixed &	Fixed::max(const Fixed & num1, const Fixed & num2)
{
	if (num1.toFloat() > num2.toFloat())
		return num1;
	else
		return num2;
}
