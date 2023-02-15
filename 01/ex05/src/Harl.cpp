/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 22:51:54 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/15 23:01:16 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Harl.hpp"

// PUBLIC
void	Harl::complain(std::string level)
{
	void (Harl::*funcarr[4]) (void) = {&Harl::error, &Harl::warning, &Harl::info, &Harl::debug};
	std::string	strarr[4] = {"ERROR", "WARNING", "INFO", "DEBUG"};

	for (int i = 0; i < 4; i++)
	{
		if (strarr[i] == level)
		{
			(this->*funcarr[i])();
			return;
		}
	}
}

// PRIVATE
void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n";
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn\'t put enough bacon in my burger! If you did, I wouldn\'t be asking for more!\n";
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I\'ve been coming for years whereas you started working here since last month.\n";
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}
