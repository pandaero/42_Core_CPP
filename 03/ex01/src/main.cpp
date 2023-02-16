/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:44:25 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/16 10:30:35 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "----- ----- ----- ----- ----- -----" << std::endl;
	ScavTrap	Joe("Joe");
	Joe.attack("Mary");
	Joe.guardGate();
	std::cout << "----- ----- ----- ----- ----- -----" << std::endl;
	ScavTrap	Fred;
	Fred = Joe;
	Fred.guardGate();
	// Fred.beRepaired(50);
	// Fred.takeDamage(75);
	std::cout << "----- ----- ----- ----- ----- -----" << std::endl;
	return (0);
}
