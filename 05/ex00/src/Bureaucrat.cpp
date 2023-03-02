/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:46:24 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/02 18:08:49 by pandalaf         ###   ########.fr       */
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
	catch(const std::invalid_argument & except)
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
	catch (const std::invalid_argument & except)
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
	catch (const std::invalid_argument & except)
	{
		std::cout << except.what() << std::endl;
	}
}

//Exception for grade being too high.
std::invalid_argument	Bureaucrat::GradeTooHighException()
{
	std::invalid_argument	arg("Invalid: grade too high.");

	return (arg);
}

//Exception for grade being too low.
std::invalid_argument	Bureaucrat::GradeTooLowException()
{
	std::invalid_argument	arg("Invalid: grade too low.");

	return (arg);
}
