/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 22:41:27 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/05 22:41:29 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

//Function to check for lowercase characters and make them uppercase. Return same otherwise.
char	upperwhenlower(char ch)
{
	if (ch >= 'a' && ch <= 'z')
		return (ch + 'A' - 'a');
	return (ch);
}

//Function turns a whole string to uppercase until null.
std::string	*stringupperwhenlower(char *str)
{
	int				i = 0;
	std::string *	out = new std::string();

	while (str[i] != '\0')
	{
		out->push_back(upperwhenlower(str[i]));
		i++;
	}
	return (out);
}

//Program takes string arguments and rewrites them out in uppercase.
int	main(int argc, char **argv)
{
	int				i = 1;
	std::string *	str = NULL;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while (argc > 1 && i < argc)
	{
		str = stringupperwhenlower(argv[i]);
		std::cout << *str;
		delete str;
		i++;
	}
	std::cout << std::endl;
	return (0);
}
