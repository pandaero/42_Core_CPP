/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:05:24 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/22 15:14:53 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Brain.hpp"
#include <iostream>

// PUBLIC
//Default constructor
Brain::Brain()
{
	std::cout << "Brain constructor called" << std::endl;
}

//Copy constructor
Brain::Brain(const Brain & other)
{
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i<100; i++)
		ideas[i] = other.ideas[i];
}

//Default destructor
Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

//Copy assignment operator overload
Brain &	Brain::operator=(const Brain & other)
{
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i<100; i++)
			ideas[i] = other.ideas[i];
	}
	return (*this);
}
