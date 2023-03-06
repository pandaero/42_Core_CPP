/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:17:47 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/06 14:58:58 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"

//PUBLIC
//Default constructor
ScalarConverter::ScalarConverter()
{

}

//Default deconstructor
ScalarConverter::~ScalarConverter()
{

}

static std::string	charConvert(std::string str)
{
	std::stringstream	out;

	switch (determineType(str))
	{
		case CHAR:
			out << "\'" << str << "\'";
			break;
		case INT:
			if (isprint(strToInt(str)))
				out << intToChar(strToInt(str));
			else if (strToInt(str) >= 0 && strToInt(str) <= 255)
				out << "non-displayable";
			else
				out << "impossible";
			break;
		case FLOAT:
			if (!remainderf(strToFloat(str), 1.0f) && isprint(floatToInt(strToFloat(str))))
				out << "\'" << intToChar(floatToInt(strToFloat(str))) << "\'";
			else if (!remainderf(strToFloat(str), 1.0f) && (strToFloat(str) >= 0 && strToFloat(str) <= 255))
				out << "non-displayable";
			else
				out << "impossible";
			break;
		case DOUBLE:
			if (!remainder(strToDouble(str), 1.0) && isprint(doubleToInt(strToDouble(str))))
				out << "\'" << intToChar(doubleToInt(strToDouble(str))) << "\'";
			else if (!remainder(strToDouble(str), 1.0) && (strToDouble(str) >= 0 && strToDouble(str) <= 255))
				out << "non-displayable";
			else
				out << "impossible";
			break;
		default:
			out << "impossible";
			break;
	}
	return (out.str());
}

static std::string	intConvert(std::string str)
{
	std::stringstream	out;

	switch (determineType(str))
	{
		case CHAR:
			out << charToInt(strToChar(str));
			break;
		case INT:
			out << strToInt(str);
			break;
		case FLOAT:
			if (!remainderf(strToFloat(str), 1.0f) && (strToFloat(str) >= LONG_MIN && strToFloat(str) <= LONG_MAX))
				out << floatToInt(strToFloat(str));
			else
				out << "impossible";
			break;
		case DOUBLE:
			if (!remainder(strToDouble(str), 1.0f) && (strToDouble(str) >= LONG_MIN && strToFloat(str) <= LONG_MAX))
				out << doubleToInt(strToDouble(str));
			else
				out << "impossible";
			break;
		default:
			out << "impossible";
			break;
	}
	return (out.str());
}

static std::string	floatConvert(std::string str)
{
	std::stringstream	out;

	switch (determineType(str))
	{
		case CHAR:
			out << std::fixed << std::setprecision(1) << charToFloat(strToChar(str)) << "f";
			break;
		case INT:
			out << std::fixed << std::setprecision(1) << intToFloat(strToInt(str)) << "f";
			break;
		case FLOAT:
			out << std::fixed << strToFloat(str) << "f";
			break;
		case DOUBLE:
			out << std::fixed << doubleToFloat(strToDouble(str)) << "f";
			break;
		default:
			out << "impossible";
			break;
	}
	return (out.str());
}

static std::string	doubleConvert(std::string str)
{
	std::stringstream	out;

	switch (determineType(str))
	{
		case CHAR:
			out << std::fixed << std::setprecision(1) << charToDouble(strToChar(str));
			break;
		case INT:
			out << std::fixed << std::setprecision(1) << intToDouble(strToInt(str));
			break;
		case FLOAT:
			out << std::fixed << floatToDouble(strToFloat(str));
			break;
		case DOUBLE:
			out << std::fixed << strToDouble(str);
			break;
		default:
			out << "impossible";
			break;
	}
	return (out.str());
}

//Function prints out the conversion for the input (including pseudo)literal.
void	ScalarConverter::convert(std::string literal)
{
	std::cout << "char  : " << charConvert(literal) << std::endl;
	std::cout << "int   : " << intConvert(literal) << std::endl;
	std::cout << "float : " << floatConvert(literal) << std::endl;
	std::cout << "double: " << doubleConvert(literal) << std::endl;
}
