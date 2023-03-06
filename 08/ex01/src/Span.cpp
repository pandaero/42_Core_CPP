/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:27:31 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/06 23:47:19 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Span.hpp"

Span::Span():
	allocated(0),
	size(0),
	vector(std::vector<int>())
{

}

Span::Span(const Span & other):
	allocated(other.vector.size()),
	size(other.size),
	vector(std::vector<int>())
{
	vector.reserve(other.vector.size());
}

Span::~Span()
{

}

Span &	Span::operator=(const Span & other)
{
	if (this != &other)
	{
		allocated = other.vector.size();
		size = other.size;
		vector = std::vector<int>();
		vector.reserve(other.vector.size());

		for (unsigned int i = 0; i < other.size; i++)
			vector[i] = other.vector[i];
	}
	return (*this);
}

Span::Span(unsigned int n):
	allocated(0),
	size(n),
	vector(std::vector<int>())
{
	vector.reserve(n);
}

void	Span::addNumber(int num)
{
	try
	{
		if (vector.size() == size)
			throw overflowException();
		else
			vector.push_back(num);
	}
	catch (std::exception & exception)
	{
		std::cerr << exception.what() << std::endl;
	}
}

void	Span::addNumbers(int no, ...)
{
	va_list	args;

	va_start(args, no);
	try
	{
		for (int i = 0; i < no; i++)
		{
			if (vector.size() == size)
			{
				va_end(args);
				throw overflowException();
			}
			else
				vector.push_back(va_arg(args, int));
		}
		va_end(args);
	}
	catch (std::exception & exception)
	{
		std::cerr << exception.what() << std::endl;
	}
}

void	Span::addVec(std::vector<int>::const_iterator first, std::vector<int>::const_iterator last)
{
	std::vector<int>::const_iterator	iter;

	iter = first;
	while (iter != last)
	{
		try
		{
			if (vector.size() == size)
				throw overflowException();
			else
				vector.push_back(*iter);
		}
		catch (std::exception & exception)
		{
			std::cerr << exception.what() << std::endl;
		}
		iter++;
	}
}

void	Span::addRandom(int qty)
{
	std::srand(std::time(0));
	try
	{
		for (int i = 0; i < qty; i++)
		{
			if (vector.size() == size)
				throw overflowException();
			else
				vector.push_back(std::rand());
		}
	}
	catch (std::exception & exception)
	{
		std::cerr << exception.what() << std::endl;
	}
}

unsigned int	Span::shortestSpan()
{
	try
	{
		if (size == 0 || size == 1)
			throw noSpanException();
		else
		{
			std::vector<int>	copy(vector);

			std::sort(copy.begin(), copy.end());
			std::adjacent_difference(copy.begin(), copy.end(), copy.begin());

			
			return (*std::min_element(++copy.begin(), copy.end()));
		}
	}
	catch (std::exception & exception)
	{
		std::cerr << exception.what() << std::endl;
		return (0);
	}
}

unsigned int	Span::longestSpan()
{
	try
	{
		if (size == 0 || size == 1)
			throw noSpanException();
		else
			return (*std::max_element(vector.begin(), vector.end()) - *std::min_element(vector.begin(), vector.end()));
	}
	catch (std::exception & exception)
	{
		std::cerr << exception.what() << std::endl;
		return (0);
	}
}

const char *	Span::overflowException::what() const throw()
{
	return ("Span already full.");
}

const char *	Span::noSpanException::what() const throw()
{
	return ("No span can be determined.");
}
