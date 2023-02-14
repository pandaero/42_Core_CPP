/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 08:46:51 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/14 13:11:36 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"
#include <iostream>

int	main(void)
{
	Fixed		a;
	const Fixed	b(10);
	const Fixed	c(42.42f);
	const Fixed	d(b);

	a = Fixed(1234.4321f);

	std::cout << "a is: " << a << std::endl;
	std::cout << "b is: " << b << std::endl;
	std::cout << "c is: " << c << std::endl;
	std::cout << "d is: " << d << std::endl;

	std::cout << "a is: " << a.toInt() << " as integer." << std::endl;
	std::cout << "b is: " << b.toInt() << " as integer." << std::endl;
	std::cout << "c is: " << c.toInt() << " as integer." << std::endl;
	std::cout << "d is: " << d.toInt() << " as integer." << std::endl;
	return (0);
}
