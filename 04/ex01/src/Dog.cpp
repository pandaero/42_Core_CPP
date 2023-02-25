/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:05:24 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/22 15:15:43 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"
#include <iostream>

// PUBLIC
//Default constructor
Dog::Dog()
{
	std::cout << "Dog constructor called" << std::endl;
	type = "Dog";
	brain = new Brain();
}

//Copy constructor
Dog::Dog(const Dog & other)
{
	std::cout << "Dog copy constructor called" << std::endl;
	type = other.type;
	brain = new Brain();
}

//Default destructor
Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete brain;
}

//Copy assignment operator overload
Dog &	Dog::operator=(const Dog & other)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &other)
	{
		type = other.type;
		brain = other.brain;
	}
	return (*this);
}