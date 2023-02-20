/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:44:25 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/17 08:56:44 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "----- ----- ----- ----- ----- -----" << std::endl;
	ScavTrap	Joe("Joe");
	Joe.takeDamage(30);
	Joe.beRepaired(20);
	Joe.attack("Mary");
	Joe.ClapTrap::attack("Mary");
	Joe.guardGate();
	std::cout << "----- ----- ----- ----- ----- -----" << std::endl;
	ScavTrap	Fred;
	Fred = Joe;
	Fred.guardGate();
	// Fred.beRepaired(50);
	// Fred.takeDamage(75);
	std::cout << "----- ----- ----- ----- ----- -----" << std::endl;
	ClapTrap	Louis("Louis");
	Louis.takeDamage(10);
	Louis.beRepaired(5);
	Louis.attack("Sally");
	std::cout << "----- ----- ----- ----- ----- -----" << std::endl;
	return (0);
}
