/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 10:57:40 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/16 11:30:01 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/DiamondTrap.hpp"
#include <iostream>

void	DiamondTrap::whoAmI(void)
{
	std::cout << "I am: " << DiamondTrap::name << " AKA: " << ClapTrap::name << std::endl;
}
