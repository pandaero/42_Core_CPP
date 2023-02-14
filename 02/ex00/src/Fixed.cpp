/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 00:07:57 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/14 01:03:43 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/Fixed.hpp"
#include <iostream>

//Static variable initialisation
const int	Fixed::fractionalBits = 8;

// PUBLIC
//Default constructor
Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	Fixed::value = 0;
}

//Copy constructor
Fixed::Fixed(const Fixed & fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	Fixed::value = fixed.getRawBits();
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

//Function returns the value of the raw bits contained in the number.
int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	int	rawBits = this->value;
	return (rawBits);
}

//Function sets the value of number by passing raw bits.
void	Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
}
