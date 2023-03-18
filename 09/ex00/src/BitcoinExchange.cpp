/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:06:18 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/17 21:52:17 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"

#include <iterator>
#include <iostream>
#include <fstream>
#include <sstream>

BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange & other)
{
	_exchangeHistory = other._exchangeHistory;
}

BitcoinExchange::~BitcoinExchange()
{

}

BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange & other)
{
	if (this != &other)
	{
		_exchangeHistory = other._exchangeHistory;
	}
	return (*this);
}

BitcoinExchange::BitcoinExchange(std::string dataFileName)
{
	std::fstream	dataFile;
	
	try
	{
		dataFile.open(dataFileName.c_str());
	}
	catch (std::exception & exc)
	{
		std::cerr << exc.what() << std::endl;
		throw invalidFileException();
	}

	std::string	buffer;
	while (std::getline(dataFile, buffer))
	{
		std::stringstream	bufferStream(buffer);
		std::string			dataLine;

		bufferStream >> dataLine;
		if (dataLine == "date,exchange_rate")
			continue;
		
		ExchangeData	dataPoint;

		try
		{
			dataPoint.takeInput(dataLine);
		}
		catch(const std::exception& exc)
		{
			// std::cerr << exc.what() << std::endl;
			continue;
		}

		_exchangeHistory.insert(dataPoint);
	}
}

double	BitcoinExchange::findValue(Date date) const
{
	ExchangeData	search(date, 0);

	std::set<ExchangeData>::reverse_iterator	end = _exchangeHistory.rbegin();
	std::advance(end, 1);
	
	// std::cout << end->getDate() << std::endl;

	if (date > (end->getDate()))
		return (end->getValue());
	if (date < _exchangeHistory.begin()->getDate())
		throw datePredatesException();
	if (date == _exchangeHistory.begin()->getDate())
		return (_exchangeHistory.begin()->getValue());

	return (_exchangeHistory.lower_bound(search)->getValue());

	// while (_exchangeHistory.find(newSearch) == _exchangeHistory.end() && newSearch.getDate() > _exchangeHistory.begin()->getDate())
	// {
	// 	Date	newDate = newSearch.getDate();
	// 	--newDate;
	// 	ExchangeData	newestSearch(newDate, 0);
	// 	newSearch = newestSearch;
	// }
	// return (_exchangeHistory.find(newSearch)->getValue());
}

const char *	BitcoinExchange::invalidFileException::what() const throw()
{
	return ("Error: Exchange: Data input file invalid.");
}

const char *	BitcoinExchange::dateExceedsException::what() const throw()
{
	return ("Error: Exchange: Date exceeds exchange.");
}

const char *	BitcoinExchange::datePredatesException::what() const throw()
{
	return ("Error: Exchange: Date predates exchange.");
}
