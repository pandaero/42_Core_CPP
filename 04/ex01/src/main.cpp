/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:12:32 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/22 16:32:03 by pandalaf         ###   ########.fr       */
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
		Animal	array[4];

		Dog		doggo;
		Dog		doggy;
		Cat		catto;
		Cat		catty;

		array[0] = doggo;
		array[1] = doggy;
		array[2] = catto;
		array[3] = catty;

		array[0].makeSound();
		array[1].makeSound();
		array[2].makeSound();
		array[3].makeSound();
	}

	std::cout << "----- ----- ----- ----- ----- ----- ----- ----- ----- -----" << std::endl;



	std::cout << "----- ----- ----- ----- ----- ----- ----- ----- ----- -----" << std::endl;

	{

		Brain	brain;
		Brain	two(brain);
		Brain	three;

		three = brain;

	}
	std::cout << "----- ----- ----- ----- ----- ----- ----- ----- ----- -----" << std::endl;
	
	// for (int i = 0; i < 4; i++)
	// {
	// 	delete &array[i];
	// }

	std::cout << "----- ----- ----- ----- ----- ----- ----- ----- ----- -----" << std::endl;
	
	{
		const Animal *	j = new Dog();
		const Animal *	i = new Cat();

		j->makeSound();
		i->makeSound();
		
		delete	j;
		// delete	i;
	}
	
	std::cout << "----- ----- ----- ----- ----- ----- ----- ----- ----- -----" << std::endl;
	return (0);
}
