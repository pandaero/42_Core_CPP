/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 23:00:01 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/15 23:01:27 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Harl.hpp"

int	main(void)
{
	Harl	dude;

	dude.complain("DEBUG");
	std::cout << "----- ----- ----- ----- -----\n";
	dude.complain("INFO");
	std::cout << "----- ----- ----- ----- -----\n";
	dude.complain("WARNING");
	std::cout << "----- ----- ----- ----- -----\n";
	dude.complain("ERROR");
	std::cout << "----- ----- ----- ----- -----\n";
	dude.complain("something else entirely");
	return (0);
}
