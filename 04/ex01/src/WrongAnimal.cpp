/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:58:01 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/22 13:57:05 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongAnimal.hpp"
#include <iostream>

// PUBLIC
//Default constructor
WrongAnimal::WrongAnimal(void)
{
	std::cout << "WrongAnimal constructor called" << std::endl;
}

//Copy constructor
WrongAnimal::WrongAnimal(const WrongAnimal & other): wrongtype(other.wrongtype)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

//Default destructor
WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

//Copy assignment operator overload
WrongAnimal &	WrongAnimal::operator=(const WrongAnimal & other)
{
	std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	if (this != &other)
		wrongtype = other.wrongtype;
	return (*this);
}

//Function gets the type of the animal.
std::string	WrongAnimal::getType(void) const
{
	return (wrongtype);
}

//Function prints message according to animal sound.
void	WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal sounds." << std::endl;
}
