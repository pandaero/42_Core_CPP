/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 22:41:27 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/10 13:51:16 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

//Program takes string arguments and rewrites them out in uppercase.
int	main(int argc, char **argv)
{
	int				i = 1;
	char			ch;
	std::string 	in, str;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while (argc > 1 && i < argc)
	{
		in = argv[i];
		for (int j = 0; j < (int) in.length(); j++)
		{
			ch = toupper(in[j]);
			std::cout << ch;
		}
		i++;
	}
	std::cout << std::endl;
	return (0);
}
