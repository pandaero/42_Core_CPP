/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 20:50:23 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/10 10:54:58 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

//Constructor for human A. Assigns name and weapon.
HumanA::HumanA(std::string name, Weapon & weapon): name(name), weapon(weapon)
{
	
}

//Function makes human A perform an attack.
void	HumanA::attack(void)
{
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}
