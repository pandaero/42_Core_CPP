/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:55:05 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/08 18:58:32 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//Program creates hordes of Zombies.
int main(void)
{
	Zombie *	firstwave = zombieHorde(5, "Fred");
	Zombie *	secondwave = zombieHorde(3, "Sally");

	firstwave[2].announce();
	secondwave[0].announce();
	secondwave[1].announce();
	secondwave[2].announce();
	delete[] firstwave;
	delete[] secondwave;
	return (0);
}
