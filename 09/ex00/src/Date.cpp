/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:03:07 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/16 11:24:31 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Date.hpp"

#include <cctype>
#include <sstream>
#include <iomanip>
#include <cstdlib>

bool	isDateFormat(std::string str)
{
	if (str.length() == 10)
		return (true);
	for (size_t i = 0; i < str.length(); ++i)
	{
		if ((i == 4 || i == 7) && str[i] == '-')
			return (true);
		if (i < 4 && isdigit(str[i]))
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

std::ostream &	operator<<(std::ostream & outStream, const Date & date)
{
	outStream << std::setfill('0') << std::setw(4) << date.getYear();
	outStream << '-' << std::setfill('0') << std::setw(2) << date.getMonth();
	outStream << '-' << std::setfill('0') << std::setw(2) << date.getDay();
	return (outStream);
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
	if (this != &other)
	{
		new (this) Date(other);
	}
	return (*this);
}

Date::Date(int year, int month, int day):
	_year(year),
	_month(month),
	_day(day)
{
	if (year < -2000 || year > 3000)
		throw invalidYearException();
	if (month < 1 || month > 12)
		throw invalidMonthException();
	if (day < 1 || day > 31)
		throw invalidDayException();
}

Date::Date(std::string input):
	_year(0),
	_month(1),
	_day(1)
{
	size_t	commaPos = input.find(',');

	std::string	dateStr = input.substr(0, commaPos);
	std::string	valueStr = input.substr(commaPos + 1, input.length());

	std::string yearStr = dateStr.substr(0, 4);
	std::string monthStr = dateStr.substr(5, 6);
	std::string dayStr = dateStr.substr(8, 9);

	int	year = atoi(yearStr.c_str());
	int	month = atoi(monthStr.c_str());
	int	day = atoi(dayStr.c_str());

	new (this) Date(year, month, day);
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
			if (_day < rhs._day)
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

Date	Date::operator++()
{
	Date	copy = *this;
	int		febdays = 28;

	if (_year % 4 == 0)
		febdays = 29;
	switch (_month)
	{
		case 1: case 3: case 5: case 7: case 8: case 10:
			if (_day == 31)
				new (this) Date(_year, _month + 1, 1);
			else
				new (this) Date(_year, _month, _day + 1);
			break;
		case 4: case 6: case 9: case 11:
			if (_day == 30)
				new (this) Date(_year, _month + 1, _day + 1);
			else
				new (this) Date(_year, _month, _day + 1);
			break;
		case 2:
			if (_day == febdays)
				new (this) Date(_year, _month + 1, 1);
			else
				new (this) Date(_year, _month, _day + 1);
			break;
		case 12:
			if (_day == 31)
				new (this) Date(_year + 1, 1, 1);
			else
				new (this) Date(_year, _month, _day + 1);
			break;
		default:
			throw invalidDateException();
	}
	return (copy);
}

Date &	Date::operator++(int)
{
	int		febdays = 28;

	if (_year % 4 == 0)
		febdays = 29;
	switch (_month)
	{
		case 1: case 3: case 5: case 7: case 8: case 10:
			if (_day == 31)
				new (this) Date(_year, _month + 1, 1);
			else
				new (this) Date(_year, _month, _day + 1);
			return (*this);
			break;
		case 4: case 6: case 9: case 11:
			if (_day == 30)
				new (this) Date(_year, _month + 1, _day + 1);
			else
				new (this) Date(_year, _month, _day + 1);
			return (*this);
			break;
		case 2:
			if (_day == febdays)
				new (this) Date(_year, _month + 1, 1);
			else
				new (this) Date(_year, _month, _day + 1);
			return (*this);
			break;
		case 12:
			if (_day == 31)
				new (this) Date(_year + 1, 1, 1);
			else
				new (this) Date(_year, _month, _day + 1);
			return (*this);
			break;
		default:
			throw invalidDateException();
	}
}

Date	Date::operator--()
{
	Date	copy = *this;
	int		febdays = 28;

	if (_year % 4 == 0)
		febdays = 29;
	switch (_month)
	{
		case 1: 
			if (_day == 1)
				new (this) Date(_year - 1, 12, 31);
			else
				new (this) Date(_year, _month, _day - 1);
			break;
		case 3: 
			if (_day == 1)
				new (this) Date(_year, 2, febdays);
			else
				new (this) Date(_year, _month, _day - 1);
			break;
		case 5: case 7: case 10: case 12:
			if (_day == 1)
				new (this) Date(_year, _month - 1, 30);
			else
				new (this) Date(_year, _month, _day - 1);
			break;
		case 2: case 4: case 6: case 8: case 9: case 11:
			if (_day == 1)
				new (this) Date(_year, _month - 1, 31);
			else
				new (this) Date(_year, _month, _day - 1);
			break;
		default:
			throw invalidDateException();
	}
	return (copy);
}

Date &	Date::operator--(int)
{
	Date	copy = *this;
	int		febdays = 28;

	if (_year % 4 == 0)
		febdays = 29;
	switch (_month)
	{
		case 1: 
			if (_day == 1)
				new (this) Date(_year - 1, 12, 31);
			else
				new (this) Date(_year, _month, _day - 1);
			return (*this);
			break;
		case 3: 
			if (_day == 1)
				new (this) Date(_year, 2, febdays);
			else
				new (this) Date(_year, _month, _day - 1);
			return (*this);
			break;
		case 5: case 7: case 10: case 12:
			if (_day == 1)
				new (this) Date(_year, _month - 1, 30);
			else
				new (this) Date(_year, _month, _day - 1);
			return (*this);
			break;
		case 2: case 4: case 6: case 8: case 9: case 11:
			if (_day == 1)
				new (this) Date(_year, _month - 1, 31);
			else
				new (this) Date(_year, _month, _day - 1);
			return (*this);
			break;
		default:
			throw invalidDateException();
	}
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

	out << std::setfill('0') << std::setw(4) << _year;
	out << '-' << std::setfill('0') << std::setw(2) << _month;
	out << '-' << std::setfill('0') << std::setw(2) << _day;

	return (out.str());
}

void	Date::takeStr(std::string input)
{
	new (this) Date(input);
}

const char *	Date::invalidDateException::what() const throw()
{
	return ("Error: Date: invalid.");
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
