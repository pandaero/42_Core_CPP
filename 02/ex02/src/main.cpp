/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:45:57 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/14 20:50:27 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"
#include <iostream>

int	main(void)
{
	Fixed		a(10);

	std::cout << "----- ----- ----- ----- -----\n";
	std::cout << "a is: " << a << std::endl;

	Fixed	b = a++;
	std::cout << "----- ----- ----- ----- -----\n";
	std::cout << "b = a++" << std::endl;

	std::cout << "a is: " << a << std::endl;
	std::cout << "b is: " << b << std::endl;
	std::cout << "a is: " << a.toInt() << " as integer." << std::endl;
	
	std::cout << "----- ----- ----- ----- -----\n";
	++a;
	std::cout << "++a" << std::endl;
	std::cout << "a is: " << a << std::endl;

	std::cout << "----- ----- ----- ----- -----\n";
	b--;
	std::cout << "b--" << std::endl;

	Fixed c = b--;
	std::cout << "c = b--" << std::endl;
	std::cout << "c is: " << c << std::endl;
	std::cout << "b is: " << b << std::endl;

	std::cout << "----- ----- ----- ----- -----\n";
	--b;
	std::cout << "--b" << std::endl;
	std::cout << "b is: " << b << std::endl;
	
	std::cout << "----- ----- ----- ----- -----\n";
	std::cout << "a > b: " << (a > b) << std::endl;
	std::cout << "b > a: " << (b > a) << std::endl;

	std::cout << "----- ----- ----- ----- -----\n";
	std::cout << "a < b: " << (a < b) << std::endl;
	std::cout << "b < a: " << (b < a) << std::endl;

	std::cout << "----- ----- ----- ----- -----\n";
	std::cout << "a >= b: " << (a >= b) << std::endl;
	std::cout << "b >= a: " << (b >= a) << std::endl;

	std::cout << "----- ----- ----- ----- -----\n";
	std::cout << "a <= b: " << (a <= b) << std::endl;
	std::cout << "b <= a: " << (b <= a) << std::endl;

	std::cout << "----- ----- ----- ----- -----\n";
	std::cout << "a == b: " << (a == b) << std::endl;
	std::cout << "b == a: " << (b == a) << std::endl;
	
	std::cout << "----- ----- ----- ----- -----\n";
	std::cout << "a != b: " << (a != b) << std::endl;
	std::cout << "b != a: " << (b != a) << std::endl;

	std::cout << "----- ----- ----- ----- -----\n";
	std::cout << "b++" << std::endl;
	std::cout << "b++" << std::endl;
	b++;
	b++;
	std::cout << "a is: " << a << std::endl;
	std::cout << "b is: " << b << std::endl;
	std::cout << "a + b: " << (a + b) << std::endl;

	std::cout << "----- ----- ----- ----- -----\n";
	std::cout << "a - b: " << (a - b) << std::endl;
	std::cout << "b - a: " << (b - a) << std::endl;

	std::cout << "----- ----- ----- ----- -----\n";
	std::cout << "a * b: " << (a * b) << std::endl;
	std::cout << "b * a: " << (b * a) << std::endl;
	
	std::cout << "----- ----- ----- ----- -----\n";
	std::cout << "a / b: " << (a / b) << std::endl;
	std::cout << "b / a: " << (b / a) << std::endl;

	std::cout << "----- ----- ----- ----- -----\n";
	return (0);
}
