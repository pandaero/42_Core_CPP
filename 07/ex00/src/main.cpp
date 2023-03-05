/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:22:39 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/05 18:44:21 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Whatever.hpp"

#include <iostream>
#include <string>

int	main()
{
	std::cout << "----- ----- ----- -----" << std::endl;

	{
		int	a = 10;
		int	b = 5;

		std::cout << "Created int a: " << a << std::endl;
		std::cout << "Created int b: " << b << std::endl;
		std::cout << "min: " << min(a, b) << std::endl;
		std::cout << "max: " << max(a, b) << std::endl;
		swap(a, b);
		std::cout << "swapped" << std::endl;
		std::cout << "int a: " << a << std::endl;
		std::cout << "int b: " << b << std::endl;
	}

	std::cout << "----- ----- ----- -----" << std::endl;

	{
		float	a = 10.2f;
		float	b = 5.3f;

		std::cout << "Created float a: " << a << std::endl;
		std::cout << "Created float b: " << b << std::endl;
		std::cout << "min: " << min(a, b) << std::endl;
		std::cout << "max: " << max(a, b) << std::endl;
		swap(a, b);
		std::cout << "swapped" << std::endl;
		std::cout << "float a: " << a << std::endl;
		std::cout << "float b: " << b << std::endl;
	}

	std::cout << "----- ----- ----- -----" << std::endl;

	{
		std::string	a = "hello world";
		std::string	b = "goodbye world";

		std::cout << "Created string a: \"" << a << "\"" << std::endl;
		std::cout << "Created string b: \"" << b << "\"" << std::endl;
		std::cout << "min: \"" << min(a, b) << "\"" << std::endl;
		std::cout << "max: \"" << max(a, b) << "\"" << std::endl;
		swap(a, b);
		std::cout << "swapped" << std::endl;
		std::cout << "string a: \"" << a << "\"" << std::endl;
		std::cout << "string b: \"" << b << "\"" << std::endl;
	}

	std::cout << "----- ----- ----- -----" << std::endl;

	return (0);
}