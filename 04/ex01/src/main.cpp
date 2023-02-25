/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:12:32 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/25 16:54:45 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"
#include "../include/Brain.hpp"
#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "----- ----- ----- ----- ----- ----- ----- ----- ----- -----" << std::endl;
	
	{
		const Animal *	array[4];

		for (int i = 0; i < 4; i++)
		{
			if (i % 2 == 0)
				array[i] = new Dog();
			else
				array[i] = new Cat();	
		}

		for (int i = 0; i < 4; i++)
			array[i]->makeSound();

		for (int i = 0; i < 4; i++)
			delete array[i];
	}

	std::cout << "----- ----- ----- ----- ----- ----- ----- ----- ----- -----" << std::endl;

	{
		Brain	brain;
		Brain	two(brain);
		Brain	three;

		three = brain;
	}
	
	std::cout << "----- ----- ----- ----- ----- ----- ----- ----- ----- -----" << std::endl;
	
	{
		const Animal *	j = new Dog();
		const Animal *	i = new Cat();

		j->makeSound();
		i->makeSound();

		delete j;
		delete i;
	}
	
	std::cout << "----- ----- ----- ----- ----- ----- ----- ----- ----- -----" << std::endl;
	return (0);
}
