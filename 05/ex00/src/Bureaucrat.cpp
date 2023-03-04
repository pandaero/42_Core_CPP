/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:46:24 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/04 23:30:16 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

//GLOBAL

//Output streaming overload for Bureaucrat object.
std::ostream &	operator<<(std::ostream & outStream, const Bureaucrat & bureaucrat)
{
	outStream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (outStream);
}

//PUBLIC
//Default constructor.
Bureaucrat::Bureaucrat()
{

}

//Copy constructor.
Bureaucrat::Bureaucrat(const Bureaucrat & other): name(other.name), grade(other.grade)
{
	
}

//Default deconstructor.
Bureaucrat::~Bureaucrat()
{
	
}

//Copy assignment operator.
Bureaucrat &	Bureaucrat::operator=(const Bureaucrat & other)
{
	if (this != &other)
		new (this) Bureaucrat(other);
	return (*this);
}

//Name and Grade-initiating constructor.
Bureaucrat::Bureaucrat(std::string name, int grade): name(name)
{
	try
	{
		if (grade < 1)
		{
			Bureaucrat::grade = 1;
			throw GradeTooHighException();
		}
		else if (grade > 150)
		{
			Bureaucrat::grade = 150;
			throw GradeTooLowException();
		}
		else
			Bureaucrat::grade = grade;
	}
	catch(const std::exception & except)
	{
		std::cerr << "Constructing " << name << ": " << except.what() << " Constructing to closest bounds." << std::endl;
	}
}

//Get the name attribute.
std::string	Bureaucrat::getName() const
{
	return (name);
}

//Get the grade attribute.
int	Bureaucrat::getGrade() const
{
	return (grade);
}

//Increase the 
void	Bureaucrat::increaseGrade()
{
	try
	{
		if (grade <= 1)
			throw GradeTooHighException();
		else
			grade--;
	}
	catch (const std::exception & except)
	{
		std::cout << except.what() << std::endl;
	}
}

void	Bureaucrat::decreaseGrade()
{
	try
	{
		if (grade >= 150)
			throw GradeTooLowException();
		else
			grade++;
	}
	catch (const std::exception & except)
	{
		std::cout << except.what() << std::endl;
	}
}

const char *	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Invalid: grade too high.");
}

const char *	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Invalid: grade too low.");
}
