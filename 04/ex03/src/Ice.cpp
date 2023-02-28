/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:10:09 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/28 01:11:02 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Ice.hpp"

//PUBLIC
//Default constructor.
Ice::Ice(): AMateria("ice")
{

}

//Copy constructor.
Ice::Ice(const Ice & other): AMateria(other.type)
{

}

//Default deconstructor.
Ice::~Ice()
{

}

//Copy assignment operator overload.
Ice &	Ice::operator=(const Ice & other)
{
	if (this != &other)
		type = other.type;
	return (*this);
}

//Duplication function.
AMateria *	Ice::clone() const
{
	Ice *	ice = new Ice(*this);
	
	return (ice);;
}

//Function to use the material.
void	Ice::use(ICharacter & target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
