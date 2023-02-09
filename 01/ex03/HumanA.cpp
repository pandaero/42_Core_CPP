/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 20:50:23 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/09 21:21:34 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

//Constructor for human A.
HumanA::HumanA(std::string name, Weapon weapon)
{
	HumanA::name = name;	
	HumanA::weapon = weapon;
}

//Function makes human A perform an attack.
void	HumanA::attack(void)
{
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}
