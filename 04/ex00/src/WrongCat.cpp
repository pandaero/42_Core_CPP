/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:05:24 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/21 20:27:31 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongCat.hpp"
#include <iostream>

// PUBLIC
//Default constructor
WrongCat::WrongCat()
{
	std::cout << "WrongCat constructor called" << std::endl;
	wrongtype = "WrongCat";
}

//Copy constructor
WrongCat::WrongCat(const WrongCat & other)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	wrongtype = other.wrongtype;
}

//Default destructor
WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

//Copy assignment operator overload
WrongCat &	WrongCat::operator=(const WrongCat & other)
{
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	if (this != &other)
		wrongtype = other.wrongtype;
	return (*this);
}

//Function prints message according to animal sound.
void	WrongCat::makeSound(void) const
{
	std::cout << "Wrong Meows: WrongMeow!" << std::endl;
}
