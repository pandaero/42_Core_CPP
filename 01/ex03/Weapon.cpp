/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 20:41:40 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/09 21:09:46 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

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
