/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:51:25 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/28 01:25:08 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AMateria.hpp"

//PUBLIC
//Default constructor
AMateria::AMateria(): type("unknown")
{
	std::cout << "AMateria default constructor called" << std::endl;
}

//Copy constructor
AMateria::AMateria(const AMateria & other): type(other.type)
{
	std::cout << "AMateria copy constructor called" << std::endl;
}

//Default deconstructor.
AMateria::~AMateria()
{
	std::cout << "AMateria deconstructor called" << std::endl;
}

//Copy assignment operator overload.
AMateria &	AMateria::operator=(const AMateria & other)
{
	std::cout << "AMateria copy assignment operator called" << std::endl;
	if (this != &other)
		type = other.type;
	return (*this);
}

//Type-initiating constructor.
AMateria::AMateria(const std::string & type): type(type)
{
	std::cout << "AMateria type-initiating constructor called" << std::endl;
}

//Getter for type attribute.
const std::string &	AMateria::getType() const
{
	return (type);
}

//Function uses a Materia on a Character through the interface class.
void	AMateria::use(ICharacter & target)
{
	std::cout << "* unknown effect on " << target.getName() << " *" << std::endl;
}
