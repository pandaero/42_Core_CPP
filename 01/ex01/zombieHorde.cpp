/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:42:30 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/08 18:58:40 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//Function creates a number of zombies with the same name. Returns pointer to first.
Zombie *	zombieHorde(int n, std::string name)
{
	Zombie *	zom = new Zombie[n];
	int			i = 0;

	while (i < n)
	{
		zom[i].nameZombie(name);
		i++;
	}
	return (zom);
}
