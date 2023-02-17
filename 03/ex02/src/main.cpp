/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:44:25 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/17 09:09:11 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FragTrap.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "----- ----- ----- ----- ----- -----" << std::endl;
	FragTrap	Bro("Bro");
	Bro.highFivesGuys();
	std::cout << "----- ----- ----- ----- ----- -----" << std::endl;
	FragTrap	Sally;
	Sally = Bro;
	Sally.attack("Joe");
	Sally.beRepaired(12);
	Sally.takeDamage(5);
	Sally.highFivesGuys();
	std::cout << "----- ----- ----- ----- ----- -----" << std::endl;
	ClapTrap	Louis("Louis");
	Louis.takeDamage(10);
	Louis.beRepaired(5);
	Louis.attack("Sally");
	std::cout << "----- ----- ----- ----- ----- -----" << std::endl;
	ScavTrap	Fred("Fred");
	Fred.guardGate();
	std::cout << "----- ----- ----- ----- ----- -----" << std::endl;
	return (0);
}
