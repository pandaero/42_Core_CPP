/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 23:34:58 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/09 00:42:23 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

//Program demonstrates pointers and references on a string.
int	main(void)
{
	std::string		var = "HI THIS IS BRAIN";
	std::string *	stringPTR = &var;
	std::string &	stringREF = var;
	//std::string		stringREF = var;

	std::cout << "Memory Addresses\n";
	std::cout << "String:    " << &var;
	std::cout << "\nstringPTR: " << &stringPTR;
	std::cout << "\nstringREF: " << &stringREF;
	std::cout << std::endl;
	std::cout << "Values\n";
	std::cout << "String:    " << var;
	std::cout << "\nstringPTR: " << stringPTR;
	std::cout << "\nstringREF: " << stringREF;
	std::cout << std::endl;
	return (0);
}
