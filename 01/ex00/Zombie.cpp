/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:14:08 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/08 18:22:53 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

//Constructor for Zombie class.
Zombie::Zombie(void)
{

}

//Deconstructor for Zombie class.
Zombie::~Zombie(void)
{
	std::cout << "Zombie " << this->name << " desctructed." << std::endl;
}

//Function assigns a name to a Zombie.
void	Zombie::nameZombie(std::string name)
{
	this->name = name;
}

//Function announces a Zombie.
void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
