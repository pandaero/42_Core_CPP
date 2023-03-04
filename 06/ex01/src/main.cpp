/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:22:39 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/04 19:59:24 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Serializer.hpp"

#include <iostream>
#include <iomanip>

int	main()
{
	Data *	strct = new Data();

	std::cout << "----- ----- ----- ----- ----- ----- -----" << std::endl;

	std::cout << "Creating packet:" << std::endl;
	std::cout << "a: \'c\'\nb: 3" << std::endl;

	strct->a = 'c';
	strct->b = 3;

	Serializer	here;

	std::cout << "Serialising packet..." << std::endl;

	uintptr_t raw = here.serialize(strct);

	delete strct;

	std::cout << "Deserialising packet..." << std::endl;

	Data * rcv = here.deserialize(raw);

	std::cout << "Received contents:" << std::endl;
	std::cout << "a: " << "\'" << rcv->a << "\'" << std::endl;
	std::cout << "b: " << rcv->b << std::endl;
	
	std::cout << "----- ----- ----- ----- ----- ----- -----" << std::endl;
	
	return (0);
}