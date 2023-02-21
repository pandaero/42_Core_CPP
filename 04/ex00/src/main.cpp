/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:12:32 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/21 20:33:52 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"
#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "----- ----- ----- ----- ----- ----- ----- ----- ----- -----" << std::endl;
	
	Animal	one;
	Animal	two(one);
	Animal	three;

	three = one;
	
	one.makeSound();
	two.makeSound();
	three.makeSound();

	std::cout << "----- ----- ----- ----- ----- ----- ----- ----- ----- -----" << std::endl;

	Dog		done;
	Dog		dtwo(done);
	Dog		dthree;

	dthree = done;

	done.makeSound();
	dtwo.makeSound();
	dthree.makeSound();

	std::cout << "----- ----- ----- ----- ----- ----- ----- ----- ----- -----" << std::endl;

	Cat		cone;
	Cat		ctwo(cone);
	Cat		cthree;

	cthree = cone;

	cone.makeSound();
	ctwo.makeSound();
	cthree.makeSound();

	std::cout << "----- ----- ----- ----- ----- ----- ----- ----- ----- -----" << std::endl;
	
	return (0);
}
