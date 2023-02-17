/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 09:26:12 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/17 09:20:35 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"
#include <iostream>

// PUBLIC
//Default constructor
ScavTrap::ScavTrap(void): ClapTrap()
{
	ClapTrap::hitpoints = 100;
	ClapTrap::energypts = 50;
	ClapTrap::attackdmg = 20;
	std::cout << "ScavTrap Default constructor called" << std::endl;
}

//Copy constructor
ScavTrap::ScavTrap(const ScavTrap & other): ClapTrap(other)
{
	ClapTrap::name = other.name;
	ClapTrap::hitpoints = other.hitpoints;
	ClapTrap::energypts = other.energypts;
	ClapTrap::attackdmg = other.attackdmg;
	std::cout << "ScavTrap Copy constructor called" << std::endl;
}

//Default destructor
ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

//Copy assignment operator
ScavTrap &	ScavTrap::operator=(const ScavTrap & other)
{
	std::cout << "ScavTrap Copy assignment operator called" << std::endl;
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
ScavTrap::ScavTrap(const std::string name): ClapTrap(name)
{
	ClapTrap::name = name;
	ClapTrap::hitpoints = 100;
	ClapTrap::energypts = 50;
	ClapTrap::attackdmg = 20;
	std::cout << "ScavTrap Name-input constructor called" << std::endl;
}

//Function puts the ScavTrap in guard mode.
void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << ClapTrap::name << " is now in gate-guard mode." << std::endl;
}

//Function attacks a target.
void	ScavTrap::attack(const std::string & target)
{
	std::cout << "ScavTrap " << ClapTrap::name << " attacks " << target << " dealing " << ClapTrap::attackdmg << " points of damage!" << std::endl;
}
