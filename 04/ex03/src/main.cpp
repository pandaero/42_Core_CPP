/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:18:49 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/28 01:27:12 by pandalaf         ###   ########.fr       */
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
	return (0);
}
