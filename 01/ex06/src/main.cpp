/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 23:00:01 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/15 23:09:34 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Harl.hpp"

int	main(int argc, char ** argv)
{
	Harl	dude;

	if (argc == 2)
	{
		std::string	input = argv[1];
		dude.complain(input);
	}
	else
		std::cout << "Invalid number of arguments" << std::endl;
	return (0);
}
