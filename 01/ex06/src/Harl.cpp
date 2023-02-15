/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 22:51:54 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/15 19:24:10 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Harl.hpp"

// PUBLIC
void	Harl::complain(std::string level)
{
	levels	compare;

	if (level == "DEBUG")
		compare = DEBUG;
	else if (level == "INFO")
		compare = INFO;
	else if (level == "WARNING")
		compare = WARNING;
	else if (level == "ERROR")
		compare = ERROR;
	else
		return;

	switch (compare)
	{
		case 0:
			this->debug();
			//fall through
		case 1:
			this->info();
			//fall through
		case 2:
			this->warning();
			//fall through
		case 3:
			this->error();
			break;
	}
}

// PRIVATE
void	Harl::debug(void)
{
	std::cout << "[DEBUG]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n";
}

void	Harl::info(void)
{
	std::cout << "[INFO]\nI cannot believe adding extra bacon costs more money. You didn\'t put enough bacon in my burger! If you did, I wouldn\'t be asking for more!\n";
}

void	Harl::warning(void)
{
	std::cout << "[WARNING]\nI think I deserve to have some extra bacon for free. I\'ve been coming for years whereas you started working here since last month.\n";
}

void	Harl::error(void)
{
	std::cout << "[ERROR]\nThis is unacceptable! I want to speak to the manager now.\n";
}
