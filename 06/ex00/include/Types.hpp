/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Types.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:31:37 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/06 11:23:22 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES
# define TYPES

# include <string>
# include <cstdlib>
# include <cctype>
# include <stdexcept>
# include <iostream>

typedef enum
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	OTHER
}	type;

bool	isChar(std::string str);
bool	isInt(std::string str);
bool	isFloat(std::string str);
bool	isDouble(std::string str);

type	determineType(char ch);
type	determineType(std::string str);

#endif
