/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 20:40:26 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/09 21:11:11 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"

//Program creates humans who attack.
int	main(void)
{
	Weapon	sword;
	sword.setType("Sword");
	HumanA	peter("Peter", sword);

	peter.attack();
	return (0);
}
