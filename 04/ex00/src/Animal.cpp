/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:58:01 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/27 18:14:44 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"
#include <iostream>

// PUBLIC
//Default constructor.
Animal::Animal()
{
	std::cout << "Animal constructor called" << std::endl;
}

//Copy constructor.
Animal::Animal(const Animal & other): type(other.type)
{
	std::cout << "Animal copy constructor called" << std::endl;
}

//Default destructor.
Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

//Copy assignment operator overload.
Animal &	Animal::operator=(const Animal & other)
{
	std::cout << "Animal copy assignment operator called" << std::endl;
	if (this != &other)
		type = other.type;
	return (*this);
}

//Function gets the type of the animal.
std::string	Animal::getType() const
{
	return (type);
}

//Function prints message for animal sound.
void	Animal::makeSound() const
{
	std::cout << "Animal sounds." << std::endl;
}
