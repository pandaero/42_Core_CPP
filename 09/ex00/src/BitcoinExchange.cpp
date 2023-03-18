/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 10:19:05 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/18 23:22:32 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"

#include <iterator>
#include <utility>
#include <cstdlib>
#include <fstream>

bool	validDate(std::string str)
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

BitcoinExchange::BitcoinExchange():
	_exchange(std::map<std::string, double>())
{

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange & other):
	_exchange(other._exchange)
{
	
}

BitcoinExchange::~BitcoinExchange()
{
	
}

BitcoinExchange &	BitcoinExchange::operator=(const BitcoinExchange & other)
{
	if (this != &other)
	{
		new (this) BitcoinExchange(other);
	}
	return (*this);
}

BitcoinExchange::BitcoinExchange(std::map<std::string, double> map):
	_exchange(map)
{

}

BitcoinExchange::BitcoinExchange(std::string dataFileName):
	_exchange(std::map<std::string, double>())
{
	std::map<std::string, double>	data;
	std::fstream					dataFile(dataFileName.c_str());

	if (dataFile.fail())
		throw	invalidFileException();

	std::string	buffer;
	while (getline(dataFile, buffer))
	{
		if (buffer == "date,exchange_rate")
			continue;
		
		std::size_t	commaPos = buffer.find(',');
		std::string	dateStr(buffer.substr(0, commaPos));
		std::string	priceStr(buffer.substr(commaPos + 1, buffer.length()));

		std::pair<std::string, double>	pair;
		pair = make_pair(dateStr, atof(priceStr.c_str()));
		data.insert(pair);
	}
	dataFile.close();
	new (this) BitcoinExchange(data);
}

double	BitcoinExchange::find(std::string date)
{
	if (date >= lastDate())
	{
		std::map<std::string, double>::const_reverse_iterator end;
		end = _exchange.rbegin();
		return (end->second);
	}
	return(_exchange.lower_bound(date)->second);
}

std::string	BitcoinExchange::firstDate()
{
	return (_exchange.begin()->first);
}

std::string	BitcoinExchange::lastDate()
{
	std::map<std::string, double>::const_reverse_iterator end;
	end = _exchange.rbegin();
	return (end->first);
}

const char *	BitcoinExchange::invalidFileException::what() const throw()
{
	return ("Error: BitcoinExchange: invalid data file.");
}
