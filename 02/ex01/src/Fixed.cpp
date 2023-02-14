/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 07:48:17 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/14 13:18:33 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"
#include <iostream>
#include <cmath>

//Static variable initialisation
const int	Fixed::fractionalBits = 8;

// PUBLIC
//Default constructor
Fixed::Fixed(void): value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

//Copy constructor
Fixed::Fixed(const Fixed & fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

//Default destructor
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

//Copy assignment operator overload
Fixed &	Fixed::operator=(const Fixed & other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->value = other.getRawBits();
	return (*this);
}

//Constructor using integer input.
Fixed::Fixed(const int value)
{
	std::cout << "Integer constructor called" << std::endl;
	Fixed::value = value << Fixed::fractionalBits;
}

//Constructor using floating-point input.
Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
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

// Example fractional values:	
//   0 = 00 =   0/256 = 0
//   1 = 01 =   1/256 = 0.00390625
// 255 = FF = 255/256 = 0.99609375

//Operator overload for stream input.
std::ostream &	operator<<(std::ostream & outStream, const Fixed & fixed)
{
	outStream << fixed.toFloat();
	return (outStream);
}

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
	int		mask = Fixed::fractionalBits * 32 - 1;

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
