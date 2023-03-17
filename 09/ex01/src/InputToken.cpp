/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InputToken.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 02:48:48 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/17 03:19:35 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/InputToken.hpp"

#include <cctype>

bool	isValid(const char ch)
{
	std::string valid("0123456789+-*/");

	for (size_t i = 0; i < valid.length(); ++i)
	{
		if (valid.find(ch) != std::string::npos)
			return (true);
	}
	return (false);
}

bool	isValid(const std::string & str)
{
	std::string valid("0123456789+-*/");

	if (str.length() != 1)
		return (false);

	for (size_t i = 0; i < valid.length(); ++i)
	{
		if (valid.find(str[0]) != std::string::npos)
			return (true);
	}
	return (false);
}

bool	containsValid(char * str)
{
	std::string parse(str);
	std::string	valid(" 0123456789+-*/");

	for (size_t i = 0; i < valid.length(); ++i)
	{
		if (parse.find(valid[i]) != std::string::npos)
			return (true);
	}
	return (false);
}

t_tokenType	tokType(const char ch)
{
	switch (ch)
	{
		case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
			return (NUM);
		case '+':
			return (PLUS);
		case '-':
			return (MINUS);
		case '*':
			return (MULTIPLY);
		case '/':
			return (DIVIDE);
		default:
			return (INVALID);
	}
}

int	tokNum(const char ch)
{
	if (isdigit(ch))
		return (ch - 48);
	return (-1);
}

InputToken::InputToken():
	_token('\0')
{

}

InputToken::InputToken(const InputToken & other):
	_token(other._token.raw)
{

}

InputToken::~InputToken()
{

}

InputToken::InputToken(const char ch):
	_token(ch)
{
	if (!isValid(ch))
		throw invalidInputException();
}

InputToken &	InputToken::operator=(const InputToken & other)
{
	if (this != &other)
	{
		new (this) InputToken(other);
	}
	return (*this);
}

t_tokenType	InputToken::getType() const
{
	return (_token.type);
}

int	InputToken::getNum() const
{
	return (_token.num);
}

char	InputToken::getRaw() const
{
	return (_token.raw);
}

const char *	InputToken::invalidInputException::what() const throw()
{
	return ("Error: InputToken: invalid input.");
}
