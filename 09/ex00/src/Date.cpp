/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:03:07 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/15 19:44:33 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Date.hpp"

#include <cctype>
#include <sstream>

bool	isDateFormat(std::string str)
{
	if (str.length() == 10)
		return (true);
	for (size_t i = 0; i < str.length(); ++i)
	{
		if ((i == 4 || i == 7) && str[i] == '-')
			return (true);
		if (i >= 0 && i < 4 && isdigit(str[i]))
			return (true);
		if (i > 4 && i < 7 && isdigit(str[i]))
			return (true);
		if (i == 5 && (str[i] == '0' || str[i] == '1'))
			return (true);
		if (i > 7 && i < 10 && isdigit(str[i]))
			return (true);
	}
	return (false);
}

Date::Date():
	_year(0),
	_month(1),
	_day(1)
{

}

Date::Date(const Date & other):
	_year(other._year),
	_month(other._month),
	_day(other._day)
{

}

Date::~Date()
{

}

Date &	Date::operator=(const Date & other)
{
	if (this == &other)
	{
		new (this) Date(other._year, other._month, other._day);
	}
	return (*this);
}

Date::Date(int year, int month, int date):
	_year(year),
	_month(month),
	_date(date)
{
	if (year < -2000 || year > 3000)
		throw invalidYearException();
	if (month < 1 || month > 12)
		throw invalidMonthException();
	if (date < 1 || date > 31)
		throw invalidDayException();
}

bool	Date::operator<(const Date & rhs) const
{
	if (_year < rhs._year)
		return (true);
	if (_year == rhs._year)
	{
		if (_month < rhs._month)
			return (true);
		if (_month == rhs._month)
		{
			if (_day < rhs._month)
				return (true);
		}
	}
	return (false);
}

bool	Date::operator>(const Date & rhs) const
{
	return (rhs < *this);
}

bool	Date::operator<=(const Date & rhs) const
{
	return (!(*this > rhs));
}

bool	Date::operator>=(const Date & rhs) const
{
	return (!(*this < rhs));
}

bool	Date::operator==(const Date & rhs) const
{
	if (_year == rhs._year && _month == rhs._month && _day == rhs._day)
		return (true);
	return (false);
}

bool	Date::operator!=(const Date & rhs) const
{
	return (!(*this == rhs));
}

int	Date::getYear() const
{
	return (_year);
}

int	Date::getMonth() const
{
	return (_month);
}

int	Date::getDay() const
{
	return (_day);
}

std::string	Date::str()
{
	std::stringstream	out;

	out << _year << '-' << _month << '-' << _day;

	return (out.str());
}

const char *	Date::invalidYearException::what() const throw()
{
	return ("Error: Date: invalid year.");
}

const char *	Date::invalidMonthException::what() const throw()
{
	return ("Error: Date: invalid month.");
}

const char *	Date::invalidDayException::what() const throw()
{
	return ("Error: Date: invalid day.");
}
