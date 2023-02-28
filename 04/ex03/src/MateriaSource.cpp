/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 20:20:04 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/28 03:04:44 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/MateriaSource.hpp"

//PUBLIC
//Default constructor.
MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		bin[i] = NULL;
}

//Copy constructor.
MateriaSource::MateriaSource(const MateriaSource & other)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		bin[i] = other.bin[i];
}

//Default deconstructor.
MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource deconstructor called" << std::endl;

	int	i = 0;
	while (i < 4)
	{
		if (bin[i])
			delete bin[i];
		i++;
	}	
}

//Copy assignment operator.
MateriaSource &	MateriaSource::operator=(const MateriaSource & other)
{
	std::cout << "MateriaSource copy assignment operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
			bin[i] = other.bin[i];
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria * materia)
{
	int i = 0;
	
	while (i < 4)
	{
		if (!bin[i])
		{
			// std::cout << "Learned type: " << materia->getType() << std::endl;
			bin[i] = materia->clone();
			delete materia;
			break;
		}
		i++;
	}
}

AMateria *	MateriaSource::createMateria(const std::string & type)
{
	int	i = 0;
	
	// std::cout << "Type to create: " << type << std::endl;
	while (i < 4)
	{
		// std::cout << "Type found: " << bin[i]->getType() << std::endl;
		if (bin[i]->getType() == type)
		{
			// std::cout << "Created " << type << std::endl;
			return (bin[i]->clone());
		}
		i++;
	}
	return (NULL);
}