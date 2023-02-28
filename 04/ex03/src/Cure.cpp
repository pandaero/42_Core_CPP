/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:10:09 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/27 11:43:53 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cure.hpp"

//PUBLIC
//Default constructor.
Cure::Cure(): AMateria("cure")
{

}

//Copy constructor.
Cure::Cure(const Cure & other): AMateria(other.type)
{

}

//Default deconstructor.
Cure::~Cure()
{

}

//Copy assignment operator overload.
Cure &	Cure::operator=(const Cure & other)
{
	if (this != &other)
		type = other.type;
	return (*this);
}

//Duplication function.
AMateria *	Cure::clone() const
{
	Cure *	cure = new Cure(*this);
	
	return (cure);
}

//Function to use the material.
void	Cure::use(ICharacter & target)
{
	std::cout << "* heals " << target.getName() << "\'s wounds *" << std::endl;
}
