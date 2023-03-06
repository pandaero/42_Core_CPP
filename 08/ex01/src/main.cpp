/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:22:39 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/06 22:46:39 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Span.hpp"

int	main()
{
	std::cout << "----- ----- ----- -----" << std::endl;

	{
		unsigned int	size = 4;
		Span			a(size);

		std::cout << "Initialised a Span size " << size << "." << std::endl;
		a.addNumber(6);
		a.addNumber(2);
		a.addNumber(10);
		a.addNumber(10);
		std::cout << "Filled the span." << std::endl;
		a.addNumber(1);

		std::cout << "Shortest span: " << a.shortestSpan() << std::endl;
		std::cout << "Longest span: " << a.longestSpan() << std::endl;
	}

	std::cout << "----- ----- ----- -----" << std::endl;

	{
		unsigned int	size = 50000;
		Span			a(size);

		std::srand(std::time(0));
		std::cout << "Initialised a Span size " << size << "." << std::endl;
		for (unsigned int i = 0; i < size; i++)
			a.addNumber(std::rand());
		std::cout << "Filled the span." << std::endl;

		std::cout << "Shortest span: " << a.shortestSpan() << std::endl;
		std::cout << "Longest span: " << a.longestSpan() << std::endl;
	}

	std::cout << "----- ----- ----- -----" << std::endl;

	return (0);
}