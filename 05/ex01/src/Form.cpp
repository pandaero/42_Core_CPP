/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:46:24 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/02 18:08:49 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"

//GLOBAL
//Output streaming overload for Form object.
std::ostream &	operator<<(std::ostream & outStream, const Form & form)
{
	outStream << "Form " << form.getName() << ", signing grade: " << form.getSignGrade() << ", execution grade: " << form.getExecGrade() << ", status: " << form.getSignStatus();
	return (outStream);
}

//PUBLIC
//Default constructor.
Form::Form(): name("Unnamed Form"), signGrade(150), execGrade(150), isSigned(false)
{

}

//Copy constructor.
Form::Form(const Form & other): name(other.name), signGrade(other.signGrade), execGrade(other.execGrade), isSigned(other.isSigned)
{

}

//Default deconstructor.
Form::~Form()
{

}

//Copy assignment operator.
Form &	Form::operator=(const Form & other)
{
	if (this != &other)
		new (this) Form(other);
	return (*this);
}

//Name and Grade-initiating constructor.
Form::Form(std::string name, int sign, int exec): name(name), signGrade(sign), execGrade(exec), isSigned(false)
{
	try
	{
		if (sign < 1 && exec < 1)
		{
			new (this) Form(name, 1, 1);
			throw GradeTooHighException();
		}
		else if (exec > 150 && exec > 150)
		{
			new (this) Form(name, 150, 150);
			throw GradeTooLowException();
		}
		else if (sign < 1 && exec > 150)
		{
			new (this) Form(name, 1, 150);
			throw GradeTooHighException();
		}
		else if (sign > 150 && exec < 1)
		{
			new (this) Form(name, 150, 1);
			throw GradeTooLowException();
		}
		else if (sign < 1)
		{
			new (this) Form(name, 1, exec);
			throw GradeTooHighException();
		}
		else if (sign > 150)
		{
			new (this) Form(name, 150, exec);
			throw GradeTooLowException();
		}
		else if (execGrade < 1)
		{
			new (this) Form(name, sign, 1);
			throw GradeTooHighException();
		}
		else if (execGrade > 150)
		{
			new (this) Form(name, sign, 150);
			throw GradeTooLowException();
		}
	}
	catch(const std::logic_error & except)
	{
		std::cerr << "Constructing " << name << ": " << except.what() << " Constructing to closest bounds." << std::endl;
	}
}

//Get the name attribute.
std::string	Form::getName() const
{
	return (name);
}

//Get the isSigned attribute.
bool	Form::getSignStatus() const
{
	return (isSigned);
}

//Get the signGrade attribute.
int	Form::getSignGrade() const
{
	return (signGrade);
}

//Get execGrade attribute.
int	Form::getExecGrade() const
{
	return (execGrade);
}

//Have a form be signed by a bureaucrat if allowed.
bool	Form::beSigned(const Bureaucrat & bureaucrat)
{
	if (bureaucrat.getGrade() <= signGrade)
		isSigned = true;
	return (isSigned);
}

//Exception for grade being too high.
std::logic_error	Form::GradeTooHighException()
{
	std::logic_error	exc("Invalid: grade too high.");

	return (exc);
}

//Exception for grade being too low.
std::logic_error	Form::GradeTooLowException()
{
	std::logic_error	exc("Invalid: grade too low.");

	return (exc);
}
