/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:18:49 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/28 13:09:06 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AMateria.hpp"
#include "../include/MateriaSource.hpp"
#include "../include/Ice.hpp"
#include "../include/Cure.hpp"
#include "../include/Character.hpp"

int	main()
{
	{
		IMateriaSource *	source = new MateriaSource();

		source->learnMateria(new Cure());
		source->learnMateria(new Ice());

		ICharacter *	pablo = new Character("Pablo");
		ICharacter *	bob = new Character("Bob");

		AMateria *	temp;
		temp = source->createMateria("ice");
		pablo->equip(temp);
		temp = source->createMateria("cure");
		pablo->equip(temp);

		pablo->use(0, *bob);
		pablo->use(1, *bob);

		delete pablo;
		delete bob;
		delete source;
	}

	std::cout << "----- ----- ----- ----- ----- ----- ----- ----- -----" << std::endl;

	{
		AMateria *	ice = new Ice();
		AMateria *	cure = new Cure();
		
		std::cout << "Created " << ice->getType() << " and " << cure->getType() << std::endl;
		
		delete ice;
		delete cure;
	}

	std::cout << "----- ----- ----- ----- ----- ----- ----- ----- -----" << std::endl;

	{
		IMateriaSource *	src = new MateriaSource();

		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Cure());

		AMateria *		temp;
		ICharacter *	pablo = new Character("Pablo");
		ICharacter *	giuseppe = new Character("Giuseppe");

		temp = src->createMateria("ice");
		pablo->equip(temp);
		temp = src->createMateria("ice");
		pablo->equip(temp);
		temp = src->createMateria("cure");
		pablo->equip(temp);
		temp = src->createMateria("cure");
		pablo->equip(temp);
		temp = src->createMateria("ice");
		pablo->equip(temp);

		pablo->use(0, *giuseppe);
		pablo->use(1, *giuseppe);
		pablo->use(2, *giuseppe);
		pablo->use(3, *giuseppe);
		pablo->use(4, *giuseppe);
		
		for (int i = 0; i <= 4; i++)
			pablo->unequip(i);

		delete pablo;
		delete giuseppe;
		delete src;
	}

	std::cout << "----- ----- ----- ----- ----- ----- ----- ----- -----" << std::endl;
	
	return (0);
}
