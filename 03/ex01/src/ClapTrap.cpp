/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:03:52 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/16 10:16:42 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"
#include <iostream>

// PUBLIC
//Default constructor
ClapTrap::ClapTrap(void): hitpoints(10), energypts(10), attackdmg(0)
{
	std::cout << "ClapTrap Default constructor called" << std::endl;
}

//Copy constructor
ClapTrap::ClapTrap(const ClapTrap & claptrap)
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	name = claptrap.name;
	hitpoints = claptrap.hitpoints;
	energypts = claptrap.energypts;
	attackdmg = claptrap.attackdmg;
}

//Default destructor
ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap Destructor called" << std::endl;
}

//Copy assignment operator overload
ClapTrap &	ClapTrap::operator=(const ClapTrap & other)
{
	std::cout << "ClapTrap Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		name = other.name;
		hitpoints = other.hitpoints;
		energypts = other.energypts;
		attackdmg = other.attackdmg;
	}
	return (*this);
}

//Constructor using name input.
ClapTrap::ClapTrap(std::string name): name(name), hitpoints(100), energypts(50), attackdmg(20)
{
	std::cout << "ClapTrap Name-input constructor called" << std::endl;
}

void	ClapTrap::attack(const std::string & target)
{
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackdmg << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << name << " takes " << amount << " damage!" << std::endl;
	hitpoints -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << name << " is repaired by " << amount << " hitpoints." << std::endl;
	hitpoints += amount;
}
