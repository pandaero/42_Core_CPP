/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 20:40:26 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/10 10:40:09 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

/*
//Program creates humans who attack.
int	main(void)
{
	Weapon	sword("Sword");
	HumanA	peter("Peter", sword);
	HumanB	bob("Bob");
	Weapon	weapon();

	peter.attack();
	sword.setType("Longsword");
	bob.setWeapon(sword);
	bob.attack();
	return (0);
}
//*/

//*
//Test Program
int	main(void)
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return 0;
}
//*/
