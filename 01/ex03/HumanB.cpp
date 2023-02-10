/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:15:19 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/10 09:46:22 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

//Constructor for human B.
HumanB::HumanB(std::string name)
{
	HumanB::name = name;	
}

// //Function assigns a weapon to human B.
// void	HumanB::setWeaponREF(Weapon & weapon)
// {
// 	this->weapon = weapon;
// }

//Function declares a weapon to assign to human B.
void	HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
	// this->setWeaponREF(weapon);
}

//Function makes human B perform an attack.
void	HumanB::attack(void)
{
	if (!HumanB::weapon)
		std::cout << this->name << " can't attack!" << std::endl;
	else
		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}
