/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:05:24 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/22 15:14:53 by pandalaf         ###   ########.fr       */
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
	brain = new Brain();
}

//Copy constructor
Cat::Cat(const Cat & other)
{
	std::cout << "Cat copy constructor called" << std::endl;
	type = other.type;
	brain = new Brain();
}

//Default destructor
Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete brain;
}

//Copy assignment operator overload
Cat &	Cat::operator=(const Cat & other)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &other)
	{
		type = other.type;
		brain = other.brain;
	}
	return (*this);
}
