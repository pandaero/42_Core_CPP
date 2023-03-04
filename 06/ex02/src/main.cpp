/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:22:39 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/04 20:40:34 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Base.hpp"

int	main()
{
	std::cout << "----- ----- ----- -----" << std::endl;
	
	Base *	obj1 = generate();
	usleep(1107000);
	Base *	obj2 = generate();
	usleep(2010500);
	Base *	obj3 = generate();
	
	std::cout << "----- ----- ----- -----" << std::endl;

	identify(obj1);
	identify(obj2);
	identify(obj3);

	std::cout << "----- ----- ----- -----" << std::endl;

	identify(*obj1);
	identify(*obj2);
	identify(*obj3);

	std::cout << "----- ----- ----- -----" << std::endl;

	return (0);
}