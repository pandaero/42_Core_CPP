/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 22:38:35 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/03 00:18:41 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PresidentialPardonForm.hpp"

//PUBLIC
//Default constructor
PresidentialPardonForm::PresidentialPardonForm(): isSigned(false), name("Robotomy Request Form"), signGrade(25), execGrade(5), target("default")
{

}

//Copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & other): AForm(other), isSigned(false), name(other.name), signGrade(other.signGrade), execGrade(other.execGrade), target(other.target)
{

}

//Default deconstructor
PresidentialPardonForm::~PresidentialPardonForm()
{

}

//Copy assignment operator
PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm & other)
{
	if (this != &other)
		isSigned = other.isSigned;
	return (*this);
}

//Target-initiating constructor
PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("Presidential Pardon Form", 25, 5), isSigned(false), name("Presidential Pardon Form"), signGrade(25), execGrade(5), target(target)
{

}

//Signs the form if bureaucrat is allowed.
bool	PresidentialPardonForm::beSigned(const Bureaucrat & bureaucrat)
{
	if (bureaucrat.getGrade() <= signGrade)
		isSigned = true;
	return (isSigned);
}

//Executes the form if executor is allowed.
bool	PresidentialPardonForm::execute(const Bureaucrat & executor) const
{
	if (executor.getGrade() <= execGrade)
	{
		std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
		return (true);
	}
	else
	{
		std::cout << "Could not execute form as " << executor.getName() << " is not of high enough grade" << std::endl;
		return (false);
	}
}
