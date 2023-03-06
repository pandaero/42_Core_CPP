/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversions.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 13:39:16 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/06 11:26:52 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Conversions.hpp"

// ==================================== CHAR ===================================

char	strToChar(std::string literal)
{
	char	ch = literal[0];
	return (ch);
}

int	charToInt(char ch)
{
	int	num = static_cast<int>(ch);
	return (num);
}

float	charToFloat(char ch)
{
	float	num = static_cast<float>(ch);
	return (num);
}

double	charToDouble(char ch)
{
	double	num = static_cast<double>(ch);
	return (num);
}

// ==================================== INT ====================================

int	strToInt(std::string literal)
{
	int	num = std::atoi(literal.c_str());
	return (num);
}

char	intToChar(int num)
{
	char	ch = static_cast<char>(num);
	return (ch);
}

float	intToFloat(int num)
{
	float	number = static_cast<float>(num);
	return (number);
}

double	intToDouble(int num)
{
	double	number = static_cast<double>(num);
	return (number);
}

// =================================== FLOAT ===================================

float	strToFloat(std::string literal)
{
	float	num = static_cast<float>(std::atof(literal.c_str()));
	return (num);
}

char	floatToChar(float num)
{
	char	ch = static_cast<char>(num);
	return	(ch);
}

int		floatToInt(float num)
{
	int	number = static_cast<int>(num);
	return (number);
}

double	floatToDouble(float num)
{
	double	number = static_cast<double>(num);
	return (number);
}

// =================================== DOUBLE ==================================

double	strToDouble(std::string literal)
{
	double	num = std::atof(literal.c_str());
	return (num);
}

char	doubleToChar(double num)
{
	char	ch = static_cast<char>(num);
	return (ch);
}

int		doubleToInt(double num)
{
	int	number = static_cast<int>(num);
	return (number);
}

float	doubleToFloat(double num)
{
	float	number = static_cast<float>(num);
	return (number);
}
