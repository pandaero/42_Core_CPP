/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 20:41:40 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/09 22:23:34 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

//Function retrieves the weapon type as a reference.
std::string	Weapon::getType(void)
{
	std::string &	typeref = Weapon::type;
	
	return (typeref);
}

//Operator for equality comparison.
bool	Weapon::operator!(void)
{
	if (this->getType() == "")
		return (true);
	else
		return (false);
}

//Function sets the weapon type.
void	Weapon::setType(std::string type)
{
	this->type = type;
}
