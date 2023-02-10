/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:15:19 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/10 10:55:18 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

//Constructor for human B. Assigns name.
HumanB::HumanB(std::string name): name(name)
{

}

//Function assigns a weapon to human B.
void	HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}

//Function makes human B perform an attack.
void	HumanB::attack(void)
{
		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}
