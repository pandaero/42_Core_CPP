/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ExchangeData.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:26:37 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/17 21:50:40 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ExchangeData.hpp"

#include <iostream>
#include <cstdlib>

ExchangeData::ExchangeData():
	_date(Date()),
	_value(0)
{

}

ExchangeData::ExchangeData(const ExchangeData & other):
	_date(other._date),
	_value(other._value)
{
	
}

ExchangeData::~ExchangeData()
{

}

ExchangeData &	ExchangeData::operator=(const ExchangeData & other)
{
	if (this != &other)
	{
		new (this) ExchangeData(other);
	}
	return (*this);
}

ExchangeData::ExchangeData(Date date, double value):
	_date(date),
	_value(value)
{
	if (value < 0 || value > 1000)
		throw invalidValueException();
}

ExchangeData::ExchangeData(std::string input):
	_date(Date()),
	_value(0)
{
	size_t	commaPos = input.find(',');

	std::string	dateStr = input.substr(0, commaPos);
	std::string	valueStr = input.substr(commaPos + 1, input.length());

	// std::cout << dateStr << ", " << valueStr << std::endl;

	try
	{
		new (this)	ExchangeData(Date(dateStr), std::atof(valueStr.c_str()));
	}
	catch (std::exception & exc)
	{
		// std::cerr << exc.what() << std::endl;
	}
}

bool	ExchangeData::operator<(const ExchangeData & rhs) const
{
	if (_date < rhs._date)
		return (true);
	return (false);
}

bool	ExchangeData::operator>(const ExchangeData & rhs) const
{
	return (rhs < *this);
}

bool	ExchangeData::operator<=(const ExchangeData & rhs) const
{
	return (!(*this > rhs));
}

bool	ExchangeData::operator>=(const ExchangeData & rhs) const
{
	return (!(*this < rhs));
}

bool	ExchangeData::operator==(const ExchangeData & rhs) const
{
	if (_date == rhs._date)
		return (true);
	return (false);
}

bool	ExchangeData::operator!=(const ExchangeData & rhs) const
{
	return (!(*this == rhs));
}

Date	ExchangeData::getDate() const
{
	return (_date);
}

double	ExchangeData::getValue() const
{
	return (_value);
}

void	ExchangeData::takeInput(std::string input)
{
	try
	{
		new (this) ExchangeData(input);
	}
	catch(const std::exception& exc)
	{
		// std::cerr << exc.what() << std::endl;
		throw invalidValueException();
	}	
}

const char *	ExchangeData::invalidValueException::what() const throw()
{
	return ("Error: ExchangeData: invalid value");
}