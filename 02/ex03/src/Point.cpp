/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:32:09 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/15 14:26:17 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"

// PUBLIC
// ORTHODOX CANONICAL CONSTRUCTORS, DESTRUCTOR AND OPERATOR
//Default constructor.
Point::Point(void)
{

}

//Copy constructor.
Point::Point(const Point & point)
{
	*this = point;
}

//CopDefault destructor.
Point::~Point(void)
{

}

//Copy assignment operator overload.
Point & Point::operator=(const Point & other)
{
	if (this != &other)
		new (this) Point(other.getx().toFloat(), other.gety().toFloat());
	return (*this);
}

// CUSTOM FUNCTIONS
//Constructor for float input coordinates.
Point::Point(const float xco, const float yco): x(Fixed(xco)), y(Fixed(yco))
{

}

bool	Point::operator==(const Point & other) const
{
	bool	samex = (this->getx().toFloat() == other.getx().toFloat());
	bool	samey = (this->gety().toFloat() == other.gety().toFloat());

	if (samex && samey) 
		return (true);
	else
		return (false);
}

Fixed	Point::getx(void) const
{
	return (x);
}

Fixed	Point::gety(void) const
{
	return (y);
}

// PRIVATE