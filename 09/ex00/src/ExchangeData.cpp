/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ExchangeData.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:26:37 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/15 12:55:36 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ExchangeData.hpp"

#include <cctype>

bool	isDateFormat(std::string str)
{
	if (str.length() != 10)
		return (false);
	for (size_t i = 0; i < str.length(); ++i)
	{
		if ((i == 4 || i == 7) && str[i] != '-')
			return (false);
		if (i >= 0 && i < 4 && !isdigit(str[i]))
			return (false);
		if (i > 4 && i < 7 && !isdigit(str[i]))
			return (false);
		if (i > 7 && i < 10 && !isdigit(str[i]))
			return (false);
	}
	return (true);
}

ExchangeData::ExchangeData():
	_date("2000-01-01"),
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
		new (this) ExchangeData(other._date, other._value);
	}
	return (*this);
}

ExchangeData::ExchangeData(std::string date, double value):
	_date(date),
	_value(value)
{
	if (!isDateFormat(date))
		throw invalidDateException();
	if (value < 0 || value > 1000)
		throw invalidValueException();
}

ExchangeData::ExchangeData(std::string input)
{
	std::string	dateString, valueString;

	size_t	commaPos = input.find(',');

	dateString = input.substr(0, commaPos);
	valueString = input.substr(commaPos + 1, input.length());

	new (this)	ExchangeData(dateString, std::atof(valueString.c_str()));
}

const char *	ExchangeData::invalidDateException::what() const throw()
{
	return ("Error: ExchangeData: invalid date");
}

const char *	ExchangeData::invalidValueException::what() const throw()
{
	return ("Error: ExchangeData: invalid value");
}