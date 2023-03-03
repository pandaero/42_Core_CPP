/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:24:01 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/03 01:28:33 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"
#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

int	main()
{
	std::cout << "----- ----- ----- ----- -----" << std::endl;
	
	std::cout << "Constructing an intern..." << std::endl;
	Intern	allmighty;

	std::cout << "----- ----- ----- ----- -----" << std::endl;

	AForm *	shrub;
	AForm *	robo;
	AForm *	pres;
	AForm *	unot;

	std::cout << "Intern is making a Shrubbery form" << std::endl;
	shrub = allmighty.makeForm("Shrubbery Creation", "home");
	std::cout << "Intern is making a Robotomy form" << std::endl;
	robo = allmighty.makeForm("Robotomy Request", "Cindy");
	std::cout << "Intern is making a Pardon form" << std::endl;
	pres = allmighty.makeForm("Presidential Pardon", "Mike");
	std::cout << "Intern is making an unspecified form" << std::endl;
	unot = allmighty.makeForm("X-Factor Contestant Selection", "Dave");
	(void) unot;

	std::cout << "----- ----- ----- ----- -----" << std::endl;

	std::cout << "2 Bureaucrats being created..." << std::endl;

	Bureaucrat	bob("Bob", 1), daisy("Daisy", 150);
	std::cout << bob << std::endl;
	std::cout << daisy << std::endl;

	std::cout << "----- ----- ----- ----- -----" << std::endl;

	daisy.signForm(*shrub);
	daisy.signForm(*robo);
	daisy.signForm(*pres);
	bob.signForm(*shrub);
	bob.signForm(*robo);
	bob.signForm(*pres);

	std::cout << "----- ----- ----- ----- -----" << std::endl;

	daisy.executeForm(*shrub);
	daisy.executeForm(*robo);
	daisy.executeForm(*pres);
	bob.executeForm(*shrub);
	bob.executeForm(*robo);
	bob.executeForm(*pres);

	std::cout << "----- ----- ----- ----- -----" << std::endl;

	return (0);
}
