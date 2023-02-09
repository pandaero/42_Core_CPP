/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:15:19 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/09 22:22:12 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

//Constructor for human B.
HumanB::HumanB(std::string name)
{
	HumanB::name = name;	
}

//Function assigns a weapon to human B.
void	HumanB::giveWeapon(Weapon weapon)
{
	this->weapon = weapon;
}

//Function makes human B perform an attack.
void	HumanB::attack(void)
{
	Weapon	empty;
	if (!HumanB::weapon)
		std::cout << this->name << " can't attack!" << std::endl;
	else
		std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}
