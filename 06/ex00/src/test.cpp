/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:02:50 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/04 19:01:41 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Types.hpp"

int	main ()
{
	std::cout << "----- ----- -----  INT TEST   ----- ----- -----" << std::endl;

	std::string str[8] = {"2001, A Space Odyssey", "40c3", "-10010110001010010", "-1234513452345234523452345", "-1235", "1235", "5", "-"};

	for (int i = 0; i < 8; i++)
	{
		bool	res = isInt(str[i]);
		std::cout << "Test: \"" << str[i] << "\", isInt: " << res << std::endl;
	}
	
	std::cout << "----- ----- -----  TYPE TEST  ----- ----- -----" << std::endl;

	std::cout << "Types: 0 - char | 1 - int | 2 - float | 3 - double | 4 - other" << std::endl;

	type	typ;
	typ = determineType('c');
	std::cout << "Test: \'c\', type: "<< typ << std::endl;

	std::string str2[20] = {"nanf", "+inff", "-inff", "+inf", "-inf", "nan", "2001, A Space Odyssey", "40c3", "4.2f", "123451523345f", "1234.51523345f", "-1234513452345234523452345", "-1234513452345234523452345.0", "-1235", "1235", "5", "-", "2345234563456345634563456345634564", "234523456345634563456345634563456.4", "0.2"};
	for (int i = 0; i < 20; i++)
	{
		typ = determineType(str2[i]);
		std::cout << "Test: \"" << str2[i] << "\", type: " << typ << std::endl;
	}

	std::cout << "----- ----- ----- ----- ----- ----- ----- -----" << std::endl;

	return (0);
}
