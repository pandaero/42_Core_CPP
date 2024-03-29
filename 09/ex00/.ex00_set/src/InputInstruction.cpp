/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InputInstruction.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:26:37 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/15 23:33:42 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/InputInstruction.hpp"

#include <iostream>
#include <cstdlib>

InputInstruction::InputInstruction():
	_date(Date()),
	_value(0),
	_error("")
{

}

InputInstruction::InputInstruction(const InputInstruction & other):
	_date(other._date),
	_value(other._value),
	_error(other._error)
{
	
}

InputInstruction::~InputInstruction()
{

}

InputInstruction &	InputInstruction::operator=(const InputInstruction & other)
{
	if (this != &other)
	{
		new (this) InputInstruction(other);
	}
	return (*this);
}

InputInstruction::InputInstruction(Date date, double value, std::string error):
	_date(date),
	_value(value),
	_error(error)
{

}

InputInstruction::InputInstruction(Date date, double value):
	_date(date),
	_value(value),
	_error("")
{
	if (value < 0)
	{
		new (this) InputInstruction(date, value, negValueException().what());
		throw negValueException();
	}
	if (value > 1000)
	{
		new (this) InputInstruction(date, value, negValueException().what());
		throw largeValueException();
	}
}

InputInstruction::InputInstruction(std::string input):
	_date(Date()),
	_value(0),
	_error("")
{
	size_t	pipePos = input.find('|');

	if (pipePos == std::string::npos)
		throw invalidInputException();

	std::string	dateStr = input.substr(0, pipePos - 1);
	std::string	valueStr = input.substr(pipePos + 2, input.length());

	try
	{
		new (this)	InputInstruction(Date(dateStr), atof(valueStr.c_str()));
	}
	catch (Date::invalidDateException & exc)
	{
		new (this) InputInstruction(Date(), 0, invalidDateException().what());
	}
	catch (Date::invalidMonthException & exc)
	{
		new (this) InputInstruction(Date(), 0, invalidDateException().what());
	}
	catch (Date::invalidDayException & exc)
	{
		new (this) InputInstruction(Date(), 0, invalidDateException().what());
	}
	catch (Date::invalidYearException & exc)
	{
		new (this) InputInstruction(Date(), 0, invalidDateException().what());
	}
	catch (largeValueException & exc)
	{
		new (this) InputInstruction(Date(), 0, exc.what());
	}
	catch (negValueException & exc)
	{
		new (this) InputInstruction(Date(), 0, exc.what());
		// std::cerr << exc.what() << std::endl;
	}
}

Date	InputInstruction::getDate() const
{
	return (_date);
}

double	InputInstruction::getValue() const
{
	return (_value);
}

std::string	InputInstruction::getError() const
{
	return (_error);
}

void	InputInstruction::takeInput(std::string input)
{
	try
	{
		new (this) InputInstruction(input);
	}
	catch(const invalidDateException & exc)
	{
		std::cerr << exc.what() << std::endl;
	}	
	catch(const negValueException & exc)
	{
		std::cerr << exc.what() << std::endl;
	}	
}

const char *	InputInstruction::invalidInputException::what() const throw()
{
	return ("Error: InputInstruction: invalid input.");
}

const char *	InputInstruction::largeValueException::what() const throw()
{
	return ("Error: InputInstruction: value too large.");
}

const char *	InputInstruction::negValueException::what() const throw()
{
	return ("Error: InputInstruction: negative value.");
}

const char *	InputInstruction::invalidDateException::what() const throw()
{
	return ("Error: InputInstruction: invalid date.");
}