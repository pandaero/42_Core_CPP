/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 19:09:27 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/04 19:59:57 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Serializer.hpp"

//PUBLIC
//Default constructor
Serializer::Serializer()
{

}

//Default deconstructor
Serializer::~Serializer()
{

}

uintptr_t	Serializer::serialize(Data * ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *	Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
