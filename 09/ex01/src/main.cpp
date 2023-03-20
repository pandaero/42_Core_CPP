/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:46:18 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/20 14:11:50 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RPN.hpp"

#include <iostream>

int	main(int argc, char ** argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: invalid number of arguments." << std::endl;
		return (1);
	}

	RPN	expr;
	try
	{
		RPN	expression(argv[1]);
		expr = expression;
	}
	catch (std::exception & exc)
	{
		std::cerr << exc.what() << std::endl;
		return (1);
	}
	std::cout << expr.getResult() << std::endl;

	return (0);
}
