/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:05:24 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/27 18:16:15 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"
#include <iostream>

// PUBLIC
//Default constructor
Cat::Cat()
{
	std::cout << "Cat constructor called" << std::endl;
	type = "Cat";
}

//Copy constructor
Cat::Cat(const Cat & other)
{
	std::cout << "Cat copy constructor called" << std::endl;
	type = other.type;
}

//Default destructor
Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

//Copy assignment operator overload
Cat &	Cat::operator=(const Cat & other)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &other)
		type = other.type;
	return (*this);
}

//Function prints message for animal sound.
void	Cat::makeSound(void) const
{
	std::cout << "Meows: Meow!" << std::endl;
}
