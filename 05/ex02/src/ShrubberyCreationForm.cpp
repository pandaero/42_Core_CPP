/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 21:47:31 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/02 23:57:18 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"

#include <fstream>

//GLOBAL
//Create shrubbery at target file.
void	createShrubbery(std::string target)
{
	std::string		filename = target + "_shrubbery";
	std::fstream	file;

	file.open(filename.c_str(), std::ios::out);
	if (!file)
	{
		std::cout << "Error creating file" << std::endl;
		file.close();
	}
	else
	{
		file << "  /\\     "  << "  /\\\n";
		file << " //\\\\    " << " //\\\\\n";
		file << "//||\\\\   " << "//||\\\\\n";
		file << "  ||     "   << "  ||" << std::endl;
		file.close();
	}
}

//PUBLIC
//Default constructor.
ShrubberyCreationForm::ShrubberyCreationForm(): isSigned(false), name("Shrubbery Creation Form"), signGrade(145), execGrade(137), target("default")
{

}

//Copy constructor.
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & other): AForm(other), isSigned(false), name(other.name), signGrade(other.signGrade), execGrade(other.execGrade), target(other.target)
{

}

//Default deconstructor.
ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

//Copy assignment operator.
ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm & other)
{
	if (this != &other)
		isSigned = other.isSigned;
	return (*this);
}

//Target-initiating constructor
ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("Shrubbery Creation Form", 145, 137), isSigned(false), name("Shrubbery Creation Form"), signGrade(145), execGrade(137), target(target)
{

}

//Signs the form if bureaucrat is allowed.
bool	ShrubberyCreationForm::beSigned(const Bureaucrat & bureaucrat)
{
	if (bureaucrat.getGrade() <= signGrade)
		isSigned = true;
	return (isSigned);
}

//Executes the form if executor is allowed.
void	ShrubberyCreationForm::execute(const Bureaucrat & executor) const
{
	if (executor.getGrade() <= execGrade)
		createShrubbery(target);
	else
		std::cout << "Could not execute form as " << executor.getName() << " is not of high enough grade" << std::endl;
}
