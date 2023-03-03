/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:46:24 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/03 00:23:24 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"

//PUBLIC
//Default constructor.
Intern::Intern()
{

}

//Copy constructor.
// Intern::Intern(const Intern & other)
// {
	
// }

//Default deconstructor.
Intern::~Intern()
{
	
}

//Copy assignment operator.
// Intern &	Intern::operator=(const Intern & other)
// {
// 	return (*this);
// }

//Have the intern make a form.
AForm *	Intern::makeForm(std::string formName, std::string target)
{
	// AForm *	shrub	= new ShrubberyCreationForm(target);
	// AForm *	robo	= new RobotomyRequestForm(target);
	// AForm *	pres	= new PresidentialPardonForm(target);

	std::string	strarr[3] = {"Shrubbery Creation", "Robotomy Request", "Presidential Pardon"};

	int	i = 0;
	while (strarr[i] != formName && i <= 3)
		i++;

	switch (i)
	{
		case 0:
			{
				AForm *	shrub = new ShrubberyCreationForm(target);
				std::cout << strarr[i] << " Form was created." << std::endl;
				return (shrub);		
			}
		case 1:
			{
				AForm *	robo = new RobotomyRequestForm(target);
				std::cout << strarr[i] << " Form was created." << std::endl;
				return (robo);
			}
		case 2:
			{
				AForm *	pres = new PresidentialPardonForm(target);
				std::cout << strarr[i] << " Form was created." << std::endl;
				return (pres);
			}
		default:
			std::cout << "Form type does not exist and was not created." << std::endl;
			return (NULL);
	}


	// if (formName == "Shrubbery Creation")
	// {
	// 	delete robo;
	// 	delete pres;
	// 	return (shrub);
	// }
	// if (formName == "Robotomy Request")
	// {
	// 	delete shrub;
	// 	delete pres;
	// 	return (robo);
	// }
	// if (formName == "Presidential Pardon")
	// {
	// 	delete shrub;
	// 	delete robo;
	// 	return (pres);
	// }
	// return (NULL);
}
