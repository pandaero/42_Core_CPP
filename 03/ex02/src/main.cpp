/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:44:25 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/16 10:52:20 by pandalaf         ###   ########.fr       */
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
	Sally.highFivesGuys();
	std::cout << "----- ----- ----- ----- ----- -----" << std::endl;
	return (0);
}
