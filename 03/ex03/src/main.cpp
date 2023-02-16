/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:44:25 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/16 15:08:23 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/DiamondTrap.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "----- ----- ----- ----- ----- -----" << std::endl;
	DiamondTrap Tiffany("Tiffany");
	Tiffany.whoAmI();
	std::cout << "----- ----- ----- ----- ----- -----" << std::endl;
	DiamondTrap	James;
	James = Tiffany;
	std::cout << "----- ----- ----- ----- ----- -----" << std::endl;
	return (0);
}
