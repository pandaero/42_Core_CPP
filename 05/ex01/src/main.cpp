/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:24:01 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/02 21:13:11 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

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

	std::cout << "----- ----- ----- ----- -----" << std::endl;

	std::cout << "Attempting to increase Nick's grade" << std::endl;
	nick.increaseGrade();
	std::cout << "Attempting to decrease Robert's grade" << std::endl;
	bob.decreaseGrade();

	std::cout << "----- ----- ----- ----- -----" << std::endl;
	
	std::cout << nick << std::endl;
	std::cout << jeb << std::endl;
	std::cout << bob << std::endl;

	std::cout << "----- ----- ----- FORMS ----- ----- -----" << std::endl;

	std::cout << "Creating three forms: A, B, and C" << std::endl;	
	Form	a("A", 0, 0);
	Form	b("B", 50, 1);
	Form	c("C", 50, 1);
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;

	std::cout << "----- ----- ----- ----- -----" << std::endl;

	std::cout << nick << std::endl;
	std::cout << jeb << std::endl;

	std::cout << "----- ----- ----- ----- -----" << std::endl;

	std::cout << "Having Nick sign form B" << std::endl;
	nick.signForm(b);

	std::cout << "Having Jebediah sign form A" << std::endl;
	jeb.signForm(a);

	std::cout << "Having Jebediah sign form C" << std::endl;
	jeb.signForm(c);

	std::cout << "----- ----- ----- ----- -----" << std::endl;

	return (0);
}
