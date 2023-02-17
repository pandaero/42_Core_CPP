/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 10:57:40 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/17 09:27:13 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/DiamondTrap.hpp"
#include <iostream>

// PUBLIC
//Default constructor
DiamondTrap::DiamondTrap(void): ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap Default constructor called" << std::endl;
}

//Copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap & other): ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	ClapTrap::name = other.name;
	ClapTrap::hitpoints = other.hitpoints;
	ClapTrap::energypts = other.energypts;
	ClapTrap::attackdmg = other.attackdmg;
	std::cout << "DiamondTrap Copy constructor called" << std::endl;
}

//Default destructor
DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap Destructor called" << std::endl;
}

//Copy assignment operator
DiamondTrap &	DiamondTrap::operator=(const DiamondTrap & other)
{
	std::cout << "DiamondTrap Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		ClapTrap::name = other.name;
		ClapTrap::hitpoints = other.hitpoints;
		ClapTrap::energypts = other.energypts;
		ClapTrap::attackdmg = other.attackdmg;
	}
	return (*this);
}

//Name-initiating constructor
DiamondTrap::DiamondTrap(const std::string name): ClapTrap(name)
{
	DiamondTrap::name = name;
	ClapTrap::name = name + "_clap_name";
	std::cout << "DiamondTrap Name-input constructor called" << std::endl;
}

//Function displays the names of the diamond Trap.
void	DiamondTrap::whoAmI(void)
{
	std::cout << "I am: " << DiamondTrap::name << " AKA: " << ClapTrap::name << std::endl;
}
