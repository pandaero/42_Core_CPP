/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:14:15 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/08 18:29:02 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

//Function creates a Zombie with a name and it announces itself.
void	randomChump(std::string name)
{
	Zombie *	zom;

	zom = newZombie(name);
	zom->announce();
	delete (zom);
}
