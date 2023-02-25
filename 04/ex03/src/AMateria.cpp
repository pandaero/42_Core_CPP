/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:51:25 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/25 20:04:07 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AMateria.hpp"
#include "../include/ICharacter.hpp"

//PUBLIC
//Default deconstructor
AMateria::~AMateria()
{

}

//Copy assignment operator overload
AMateria &	AMateria::operator=(const AMateria & other)
{

}

//Type-initiating constructor
AMateria::AMateria(std::string const & type)
{

}

//Type getter
std::string const &	AMateria::getType() const
{

}

//Self-duplication function
AMateria *	AMateria::clone() const
{

}

//Function uses a Materia on a Character through the interface class.
void	AMateria::use(ICharacter & target)
{
	
}

//PROTECTED
//Default constructor
AMateria::AMateria()
{

}

//Copy constructor
AMateria::AMateria(const AMateria & other)
{

}
