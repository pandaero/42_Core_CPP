/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:24:01 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/02 18:13:56 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

int	main()
{
	std::cout << "----- ----- ----- ----- -----" << std::endl;
	
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

	std::cout << "----- ----- ----- ----- -----" << std::endl;
	
	return (0);
}
