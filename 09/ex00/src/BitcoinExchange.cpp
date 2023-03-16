/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:06:18 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/16 11:27:37 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"

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

// void	BitcoinExchange::initExchange(std::string dataFileName)
// {
// 	new (this) BitcoinExchange(dataFileName);
// }

double	BitcoinExchange::findValue(Date date) const
{
	ExchangeData	search(date, 0);

	if (search.getDate() < _exchangeHistory.begin()->getDate())
		throw datePredatesException();
	if (search.getDate() == _exchangeHistory.begin()->getDate())
		return (_exchangeHistory.begin()->getValue());
	
	ExchangeData	newSearch(--search.getDate(), 0);

	while (_exchangeHistory.find(newSearch) == _exchangeHistory.end() && newSearch.getDate() > _exchangeHistory.begin()->getDate())
	{
		Date	newDate = newSearch.getDate();
		--newDate;
		ExchangeData	newestSearch(newDate, 0);
		newSearch = newestSearch;
	}
	return (_exchangeHistory.find(newSearch)->getValue());
}

const char *	BitcoinExchange::invalidFileException::what() const throw()
{
	return ("Error: Exchange: Data input file invalid.");
}

const char *	BitcoinExchange::datePredatesException::what() const throw()
{
	return ("Error: Exchange: Date predates exchange.");
}
