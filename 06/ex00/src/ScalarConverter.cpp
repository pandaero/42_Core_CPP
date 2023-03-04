/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:17:47 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/04 14:32:16 by pandalaf         ###   ########.fr       */
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

static std::string	convertChar(std::string str)
{
	std::stringstream	stream;

	stream << str;
	return (stream.str());
}

static std::string	convertInt(std::string str)
{
	std::stringstream	stream;

	stream << str;
	return (stream.str());
}

static std::string	convertFloat(std::string str)
{
	std::stringstream	stream;

	stream << str;
	return (stream.str());
}

static std::string	convertDouble(std::string str)
{
	std::stringstream	stream;

	stream << str;
	return (stream.str());
}

//Function prints out the conversion for the input (including pseudo)literal.
void	ScalarConverter::convert(std::string literal)
{
	std::cout << convertChar(literal) << std::endl;
	std::cout << convertInt(literal) << std::endl;
	std::cout << convertFloat(literal) << std::endl;
	std::cout << convertDouble(literal) << std::endl;

	// switch (typ)
	// {
	// 	case CHAR:
	// 		convertChar(literal);
	// 		break;
	// 	case INT:
	// 		convertInt(literal);
	// 		break;
	// 	case FLOAT:
	// 		convertFloat(literal);
	// 		break;
	// 	case DOUBLE:
	// 		convertDouble(literal);
	// 		break;
	// 	default:
	// 		std::cout << "Conversion not possible." << std::endl;
	// 		break;
	// }
}
