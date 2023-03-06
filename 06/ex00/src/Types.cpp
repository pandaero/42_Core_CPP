/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Types.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:31:43 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/06 11:24:40 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Types.hpp"

bool	isChar(std::string str)
{
	if (str.length() == 1)
		return (true);
	return (false);
}

bool	isInt(std::string str)
{
	if (str.length() > 1 && (str[0] == '+' || str[0] == '-' || isdigit(str[0])))
	{
		for (int i = 1; i < (int) str.length(); i++)
		{
			if (!isdigit(str[i]))
				return (false);
		}
	}
	try
	{
		int num = std::atoi(str.c_str());
		(void) num;
	}
	catch (std::exception & exc)
	{
		// std::cout << exc.what() << std::endl;
		return (false);
	}
	return (true);
}

bool	isFloat(std::string str)
{
	if (str == "+inff" || str == "-inff" || str == "inff" || str == "nanf")
		return (true);
	if (str[str.length() - 1] != 'f')
		return (false);
	if (!isdigit(str[str.length() - 2]))
		return (false);
	if (str.find('.') == std::string::npos)
		return (false);
	if (str.length() > 1 && (str[0] == '+' || str[0] == '-' || isdigit(str[0])))
	{
		for (int i = 1; i < (int) str.length() - 1; i++)
		{
			if (!isdigit(str[i]) && !(str[i] == '.')) 
				return (false);
		}
	}
	try
	{
		double num = std::atof(str.c_str());
		(void) num;
	}
	catch (std::exception & exc)
	{
		// std::cout << exc.what() << std::endl;
		return (false);
	}
	return (true);
}

bool	isDouble(std::string str)
{
	if (str == "+inf" || str == "-inf" || str == "inf" || str == "nan")
		return (true);
	if (str.find('.') == std::string::npos)
		return (false);
	if (!isdigit(str[str.length() - 1]))
		return (false);
	if (str.length() > 1 && (str[0] == '+' || str[0] == '-' || isdigit(str[0])))
	{
		for (int i = 1; i < (int) str.length(); i++)
		{
			if (!isdigit(str[i]) && !(str[i] == '.'))
				return (false);
		}
	}
	try
	{
		double num = std::atof(str.c_str());
		(void) num;
	}
	catch (std::exception & exc)
	{
		// std::cout << exc.what() << std::endl;
		return (false);
	}
	return (true);
}

type	determineType(char ch)
{
	(void) ch;
	return (CHAR);
}

type	determineType(std::string str)
{
	if (isInt(str))
		return (INT);
	if (isChar(str))
		return (CHAR);
	if (isFloat(str))
		return (FLOAT);
	if (isDouble(str))
		return (DOUBLE);
	return (OTHER);
}
