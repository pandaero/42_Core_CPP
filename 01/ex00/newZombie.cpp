/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:14:09 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/08 18:23:10 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

//Function creates a new Zombie, names it, and returns it.
Zombie *	newZombie(std::string name)
{
	Zombie *	zom = new Zombie();

	zom->nameZombie(name);
	return (zom);
}
