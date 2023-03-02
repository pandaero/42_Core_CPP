/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:24:01 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/03 00:21:59 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

int	main()
{
	std::cout << "----- ----- ----- ----- -----" << std::endl;
	
	std::cout << "Constructing 3 bureaucrats..." << std::endl;
	Bureaucrat	nick("Nick", 0);
	Bureaucrat	bob("Robert", 151);
	Bureaucrat	jeb("Jebediah", 75);

	std::cout << "----- ----- ----- ----- -----" << std::endl;

	std::cout << nick << std::endl;
	std::cout << jeb << std::endl;
	std::cout << bob << std::endl;

	std::cout << "----- ----- ----- FORMS ----- ----- -----" << std::endl;

	std::cout << "Creating shrubbery forms A and B" << std::endl;	
	ShrubberyCreationForm	a("garden");
	ShrubberyCreationForm	b("outback");

	std::cout << "----- ----- ----- ----- -----" << std::endl;

	std::cout << "Having Robert sign form B" << std::endl;
	bob.signForm(b);
	std::cout << "Having Jebediah sign form A" << std::endl;
	jeb.signForm(a);
	std::cout << "Having Robert execute form B" << std::endl;
	bob.executeForm(b);
	std::cout << "Having Jebediah execute form A" << std::endl;
	jeb.executeForm(a);

	std::cout << "----- ----- ----- ----- -----" << std::endl;

	std::cout << "Creating robotomy request forms C, D, and E" << std::endl;
	AForm *	c = new RobotomyRequestForm("Dude");
	AForm *	d = new RobotomyRequestForm("Lory");
	AForm *	e = new RobotomyRequestForm("Raquel");

	std::cout << "----- ----- ----- ----- -----" << std::endl;

	std::cout << "Having Robert sign form C" << std::endl;
	bob.signForm(*c);
	std::cout << "Having Robert execute form C" << std::endl;
	bob.executeForm(*c);
	std::cout << "Having Nick sign form D" << std::endl;
	nick.signForm(*d);
	std::cout << "Having Nick execute form D" << std::endl;
	nick.executeForm(*d);
	std::cout << "Having Nick sign form E" << std::endl;
	nick.signForm(*e);
	std::cout << "Having Nick execute form E" << std::endl;
	nick.executeForm(*e);

	delete c;
	delete d;
	delete e;

	std::cout << "----- ----- ----- ----- -----" << std::endl;

	std::cout << "Creating presidential pardon forms F and G" << std::endl;
	PresidentialPardonForm	f("Mike");
	PresidentialPardonForm	g("Clara");

	std::cout << "----- ----- ----- ----- -----" << std::endl;

	std::cout << "Having Jebediah sign form F" << std::endl;
	jeb.signForm(f);
	std::cout << "Having Nick sign form G" << std::endl;
	nick.signForm(g);
	std::cout << "Having Jebediah execute form F" << std::endl;
	jeb.executeForm(f);
	std::cout << "Having Nick execute form G" << std::endl;
	nick.executeForm(g);

	std::cout << "----- ----- ----- ----- -----" << std::endl;

	return (0);
}
