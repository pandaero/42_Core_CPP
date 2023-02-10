/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 20:41:40 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/10 10:40:23 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>

//Default constructor for weapon.
Weapon::Weapon(void)
{
	
}

//Constructor for weapon, assigns weapon type.
Weapon::Weapon(std::string type): type(type)
{

}

//Function retrieves the weapon type as a reference.
std::string	Weapon::getType(void)
{
	std::string &	typeref = Weapon::type;

	return (typeref);
}

//Function sets the weapon type.
void	Weapon::setType(std::string type)
{
	this->type = type;
}
