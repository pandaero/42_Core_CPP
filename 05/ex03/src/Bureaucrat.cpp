/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:46:24 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/03 00:23:24 by pandalaf         ###   ########.fr       */
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
	catch(const std::logic_error & except)
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

//Increase the bureaucrat's grade if possible.
void	Bureaucrat::increaseGrade()
{
	try
	{
		if (grade <= 1)
			throw GradeTooHighException();
		else
			grade--;
	}
	catch (const std::logic_error & except)
	{
		std::cout << except.what() << std::endl;
	}
}

//Decrease the bureaucrat's grade if possible.
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

//Have the bureaucrat sign a form.
void	Bureaucrat::signForm(AForm & form)
{
	bool	status;

	status = form.beSigned(*this);
	if (status)
		std::cout << name << " signed " << form.getName() << std::endl;
	else
		std::cout << name << " couldn\'t sign " << form.getName() << " because the signing grade is higher than his." << std::endl;
}

//Have the bureaucrat execute a form.
void	Bureaucrat::executeForm(AForm & form)
{
	bool	status;

	status = form.execute(*this);
	if (status)
		std::cout << name << " executed " << form.getName() << std::endl;
	else
		std::cout << name << " couldn\'t execute " << form.getName() << " because the execution grade is higher than his." << std::endl;
}

//Exception for grade being too high.
std::logic_error	Bureaucrat::GradeTooHighException()
{
	std::logic_error	exc("Invalid: grade too high.");

	return (exc);
}

//Exception for grade being too low.
std::logic_error	Bureaucrat::GradeTooLowException()
{
	std::logic_error	exc("Invalid: grade too low.");

	return (exc);
}
