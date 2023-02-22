/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:12:32 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/22 14:10:15 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"
#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"
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
	
	const Animal *	meta = new Animal();
	const Animal *	j = new Dog();
	const Animal *	i = new Cat();

	std::cout << "j: " << j->getType() << std::endl;
	std::cout << "i: " << i->getType() << std::endl;
	j->makeSound();
	i->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	std::cout << "----- ----- ----- ----- ----- ----- ----- ----- ----- -----" << std::endl;

	const WrongAnimal *	wmeta = new WrongAnimal();
	const WrongAnimal *	wi = new WrongCat();

	std::cout << "i: " << wi->getType() << std::endl;
	wi->makeSound();
	wmeta->makeSound();

	delete wmeta;
	delete wi;

	std::cout << "----- ----- ----- ----- ----- ----- ----- ----- ----- -----" << std::endl;
	return (0);
}
