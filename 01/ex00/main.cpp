/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:25:35 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/08 18:28:49 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//Program creates zombies in different ways.
int	main(void)
{
	Zombie *	zom;

	zom = newZombie("Fred");
	zom->announce();
	randomChump("Sally");
	delete zom;
	return (0);
}
