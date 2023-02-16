/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 10:38:11 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/16 20:01:41 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FragTrap.hpp"
#include <iostream>

// PUBLIC
//Default constructor
FragTrap::FragTrap(void): ClapTrap()
{
	std::cout << "FragTrap Default constructor called" << std::endl;
}

//Copy constructor
FragTrap::FragTrap(const FragTrap & other): ClapTrap(other)
{
	std::cout << "FragTrap Copy constructor called" << std::endl;
}

//Default destructor
FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap Destructor called" << std::endl;
}

//Copy assignment operator
FragTrap &	FragTrap::operator=(const FragTrap & other)
{
	std::cout << "FragTrap Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		ClapTrap::name = other.name;
		ClapTrap::hitpoints = other.FragTrap::hitpoints;
		ClapTrap::energypts = other.FragTrap::energypts;
		ClapTrap::attackdmg = other.FragTrap::attackdmg;
	}
	return (*this);
}

//Name-initiating constructor
FragTrap::FragTrap(const std::string name): ClapTrap(name)
{
	std::cout << "FragTrap Name-input constructor called" << std::endl;
}

//Function requests high fives.
void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << ClapTrap::name << " starts offering high-fives all around!" << std::endl;
}
