/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ExchangeData.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:26:37 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/15 13:29:30 by pandalaf         ###   ########.fr       */
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

ExchangeData::ExchangeData(std::string input):
	_date("2000-01-01"),
	_value(0)
{
	std::string	dateString, valueString;

	size_t	commaPos = input.find(',');

	dateString = input.substr(0, commaPos);
	valueString = input.substr(commaPos + 1, input.length());

	new (this)	ExchangeData(dateString, std::atof(valueString.c_str()));
}

bool	ExchangeData::operator<(const ExchangeData & rhs) const
{
	std::string	lyearStr, lmonthStr, ldayStr;
	int			lyear, lmonth, lday;

	lyearStr = _date.substr(0,3);
	lmonthStr = _date.substr(5,7);
	ldayStr = _date.substr(8,10);
	lyear = std::atoi(lyearStr.c_str());
	lmonth = std::atoi(lmonthStr.c_str());
	lday = std::atoi(ldayStr.c_str());

	std::string	ryearStr, rmonthStr, rdayStr;
	int			ryear, rmonth, rday;

	ryearStr = _date.substr(0,3);
	rmonthStr = _date.substr(5,7);
	rdayStr = _date.substr(8,10);
	ryear = std::atoi(ryearStr.c_str());
	rmonth = std::atoi(rmonthStr.c_str());
	rday = std::atoi(rdayStr.c_str());

	if (lyear < ryear)
		return (true);
	if (lyear == ryear)
	{
		if (lmonth < rmonth)
			return (true);
		if (lmonth == rmonth)
		{
			if (lday < rday)
				return (true);
		}
	}
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
	return ((*this < rhs && *this > rhs));
}

bool	ExchangeData::operator!=(const ExchangeData & rhs) const
{
	return (!(*this == rhs));
}

const char *	ExchangeData::invalidDateException::what() const throw()
{
	return ("Error: ExchangeData: invalid date");
}

const char *	ExchangeData::invalidValueException::what() const throw()
{
	return ("Error: ExchangeData: invalid value");
}