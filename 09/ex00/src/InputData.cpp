/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InputData.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 00:19:26 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/16 13:35:12 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/InputData.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

InputData	*readInput(std::string inputFile)
{
	std::fstream	inFile(inputFile);
	
	if (inFile.bad())
		throw InputData::invalidFileException();

	std::string	buffer;
	int	i = 0;
	while (std::getline(inputFile, buffer))
	{
		if (buffer == "date | value")
			continue;
		++i;
	}
	
	Input Data *	arr = new InputData[i];
	
	i = 0;
	while (std::getline(inputFile, buffer))
	{
		std::stringstream	bufferStream(buffer);
		std::stringstream	outLineStream;
		std::string			inputLine;

		bufferStream >> inputLine;
		if (inputLine == "date | value")
			continue;

		std::string	dateStr = inputLine.substr(0, pipePos - 1);

		Date	date;
		try
		{
			date.takeDateStr(dateStr);
		}
		catch (std::exception & exc)
		{
			InputData::invalidDateInputException	sec;
			outLineStream << sec.what() << std::endl;
		}

		double	val;
		{
			size_t		pipePos = inputLine.find('|');

			std::string	valueStr = inputLine.substr(pipePos + 1, inputLine.length());
			double		value = atof(valueStr.c_str());

			if (double < 0)
			{
				InputData::negativeValueException	exc;
				outLineStream << exc.what() << std::endl;
			}
			if (double > 1000)
			{
				InputData::largeValueException	exc;
				outLineStream << exc.what() << std::endl;
			}
			val = value;
		}

		if (outLineStream.str().empty())
		{
			outLineStream << date << " => " << 
		}

		InputData	parsed(date, val, outLineStream.str());
		arr[i++] = parsed;
	}
	return (arr);
}

const char *	InputData::invalidFileException::what() const throw()
{
	return ("Error: input file error.");
}

const char *	InputData::invalidDateInputException::what() const throw()
{
	return ("Error: invalid date input.");
}

const char *	InputData::negativeValueException::what() const throw()
{
	return ("Error: negative value.");
}

const char *	InputData::largeValueException::what() const throw()
{
	return ("Error: value too large.");
}
