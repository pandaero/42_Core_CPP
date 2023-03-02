/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:24:01 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/02 22:37:03 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"

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

	std::cout << "Having Robert execute form B" << std::endl;
	b.execute(bob);
	std::cout << "Having Jebediah execute form A" << std::endl;
	a.execute(jeb);

	std::cout << "----- ----- ----- ----- -----" << std::endl;

	std::cout << "Creating robotomy request forms C and D" << std::endl;
	RobotomyRequestForm	c("Dude");
	RobotomyRequestForm	d("Lory");

	std::cout << "----- ----- ----- ----- -----" << std::endl;

	std::cout << "Having Robert execute form C" << std::endl;
	c.execute(bob);
	std::cout << "Having Nick execute form D" << std::endl;
	d.execute(nick);

	std::cout << "----- ----- ----- ----- -----" << std::endl;

	std::cout << "Creating presidential pardon forms E and F" << std::endl;
	PresidentialPardonForm	e("Mike");
	PresidentialPardonForm	f("Clara");

	std::cout << "----- ----- ----- ----- -----" << std::endl;

	std::cout << "Having Jebediah execute form E" << std::endl;
	c.execute(jeb);
	std::cout << "Having Nick execute form F" << std::endl;
	d.execute(nick);

	std::cout << "----- ----- ----- ----- -----" << std::endl;

	return (0);
}
