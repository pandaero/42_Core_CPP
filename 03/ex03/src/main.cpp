/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:44:25 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/17 09:28:40 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/DiamondTrap.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "----- ----- ----- ----- ----- -----" << std::endl;
	DiamondTrap Tiffany("Tiffany");
	Tiffany.attack("Mike");
	Tiffany.beRepaired(30);
	Tiffany.takeDamage(50);
	Tiffany.guardGate();
	Tiffany.whoAmI();
	std::cout << "----- ----- ----- ----- ----- -----" << std::endl;
	return (0);
}
