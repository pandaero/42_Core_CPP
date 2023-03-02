/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:46:24 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/02 18:08:49 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"

//GLOBAL
//Output streaming overload for Form object.
std::ostream &	operator<<(std::ostream & outStream, const AForm & form)
{
	outStream << "Form " << form.getName() << ", signing grade: " << form.getSignGrade() << ", execution grade: " << form.getExecGrade() << ", status: " << form.getSignStatus();
	return (outStream);
}

//PUBLIC
//Default constructor.
AForm::AForm(): name("Unnamed Form"), signGrade(150), execGrade(150), isSigned(false)
{

}

//Copy constructor.
AForm::AForm(const AForm & other): name(other.name), signGrade(other.signGrade), execGrade(other.execGrade), isSigned(other.isSigned)
{

}

//Default deconstructor.
AForm::~AForm()
{

}

//Copy assignment operator.
AForm &	AForm::operator=(const AForm & other)
{
	if (this != &other)
	{

	}
	return (*this);
}

//Name and Grade-initiating constructor.
AForm::AForm(std::string name, int sign, int exec): name(name), signGrade(sign), execGrade(exec), isSigned(false)
{
	try
	{
		if (sign < 1 && exec < 1)
		{
			// new (this) AForm(name, 1, 1);
			throw GradeTooHighException();
		}
		else if (exec > 150 && exec > 150)
		{
			// new (this) AForm(name, 150, 150);
			throw GradeTooLowException();
		}
		else if (sign < 1 && exec > 150)
		{
			// new (this) AForm(name, 1, 150);
			throw GradeTooHighException();
		}
		else if (sign > 150 && exec < 1)
		{
			// new (this) AForm(name, 150, 1);
			throw GradeTooLowException();
		}
		else if (sign < 1)
		{
			// new (this) AForm(name, 1, exec);
			throw GradeTooHighException();
		}
		else if (sign > 150)
		{
			// new (this) AForm(name, 150, exec);
			throw GradeTooLowException();
		}
		else if (execGrade < 1)
		{
			// new (this) AForm(name, sign, 1);
			throw GradeTooHighException();
		}
		else if (execGrade > 150)
		{
			// new (this) AForm(name, sign, 150);
			throw GradeTooLowException();
		}
	}
	catch(const std::logic_error & except)
	{
		std::cerr << "Constructing " << name << ": " << except.what() << " Constructing to closest bounds." << std::endl;
	}
}

//Get the name attribute.
std::string	AForm::getName() const
{
	return (name);
}

//Get the isSigned attribute.
bool	AForm::getSignStatus() const
{
	return (isSigned);
}

//Get the signGrade attribute.
int	AForm::getSignGrade() const
{
	return (signGrade);
}

//Get execGrade attribute.
int	AForm::getExecGrade() const
{
	return (execGrade);
}

//Have a form be signed by a bureaucrat if allowed.
bool	AForm::beSigned(const Bureaucrat & bureaucrat)
{
	if (bureaucrat.getGrade() <= signGrade)
		isSigned = true;
	return (isSigned);
}

//Exception for grade being too high.
std::logic_error	AForm::GradeTooHighException()
{
	std::logic_error	exc("Invalid: grade too high.");

	return (exc);
}

//Exception for grade being too low.
std::logic_error	AForm::GradeTooLowException()
{
	std::logic_error	exc("Invalid: grade too low.");

	return (exc);
}
