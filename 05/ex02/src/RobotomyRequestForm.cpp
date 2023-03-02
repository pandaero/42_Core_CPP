/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 22:38:35 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/02 23:57:51 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RobotomyRequestForm.hpp"

//Static Attributes
int	RobotomyRequestForm::robotomyCount = 0;

//PUBLIC
//Default constructor
RobotomyRequestForm::RobotomyRequestForm(): isSigned(false), name("Robotomy Request Form"), signGrade(72), execGrade(45), target("default")
{

}

//Copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & other): AForm(other), isSigned(false), name(other.name), signGrade(other.signGrade), execGrade(other.execGrade), target(other.target)
{

}

//Default deconstructor
RobotomyRequestForm::~RobotomyRequestForm()
{

}

//Copy assignment operator
RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm & other)
{
	if (this != &other)
		isSigned = other.isSigned;
	return (*this);
}

//Target-initiating constructor
RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("Robotomy Request Form", 72, 45), isSigned(false), name("Robotomy Request Form"), signGrade(72), execGrade(45), target(target)
{

}

//Signs the form if bureaucrat is allowed.
bool	RobotomyRequestForm::beSigned(const Bureaucrat & bureaucrat)
{
	if (bureaucrat.getGrade() <= signGrade)
		isSigned = true;
	return (isSigned);
}

//Executes the form if executor is allowed.
void	RobotomyRequestForm::execute(const Bureaucrat & executor) const
{
	if (executor.getGrade() <= execGrade)
	{
		if (robotomyCount % 2 == 0)
			std::cout << target << " has been successfully robotomised." << std::endl;
		else
			std::cout << target << " has not been robotomised successfully." << std::endl;
		robotomyCount++;
	}
	else
		std::cout << "Could not execute form as " << executor.getName() << " is not of high enough grade" << std::endl;
}
