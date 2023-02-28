/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:51:25 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/27 12:38:30 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Character.hpp"

//PUBLIC
//Default constructor.
Character::Character()
{
	std::cout << "Character default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

//Copy constructor.
Character::Character(const Character & other)
{
	std::cout << "Character copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		inventory[i] = other.inventory[i];
	name = other.name;
}

//Default deconstructor.
Character::~Character()
{
	std::cout << "Character default deconstructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i])
			delete inventory[i];
	}
}

//Copy assignment operator overload.
Character &	Character::operator=(const Character & other)
{
	std::cout << "Character copy assignment operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
			inventory[i] = other.inventory[i];
		name = other.name;
	}
	return (*this);
}

//Name-initiating constructor.
Character::Character(std::string name): name(name)
{
	std::cout << "Character name-initiating constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

//Getter for name attribute.
const std::string &	Character::getName() const
{
	return (name);
}

//Function makes Character equip Materia.
void	Character::equip(AMateria * materia)
{
	int	i = 0;

	if (materia == NULL)
		return;
	while (i < 4)
	{
		if (!inventory[i])
		{
			inventory[i] = materia->clone();
			delete materia;
			break;
		}
		if (inventory[i] && i == 3)
			delete materia;
		i++;
	}
}

//Function makes Character unequip Materia.
void	Character::unequip(int index)
{
	if (index > 3)
		return;
	if (!inventory[index])
		inventory[index] = NULL;
}

//Function uses a Materia on a Character through the interface class.
void	Character::use(int index, ICharacter & target)
{
	if (index > 3)
		return;
	if (inventory[index])
		inventory[index]->use(target);
}

