/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 22:48:02 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/06 01:12:32 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <string>

//Function makes and prints out the header for the search list.
void	print_search_header(void)
{
	std::stringstream	headerelm;

	headerelm << std::setw(10) << "index";
	std::cout << headerelm.str();
	headerelm.str("");
	headerelm << std::setw(10) << "first name";
	std::cout << "|" << headerelm.str();
	headerelm.str("");
	headerelm << std::setw(10) << "lastname";
	std::cout << "|" << headerelm.str();
	headerelm.str("");
	headerelm << std::setw(10) << "nickname";
	std::cout << "|" << headerelm.str() << std::endl;
}

//Function handles the search menu.
void	search_menu(PhoneBook book)
{
	int			num;
	int			ser = 1;
	std::string	input;

	print_search_header();
	while (ser <= book.get_num_contacts())
	{
		book.search(ser)->print();
		ser++;
	}
	std::cout << std::endl << "Select contact for details (index): ";
	std::getline(std::cin, input);
	std::istringstream(input) >> num;
	if (num >= 1 && num <= book.get_num_contacts())
		book.search(num)->print_details();
	else
		std::cout << "NO SUCH CONTACT\n";
}

//Program creates an 8-entry max contact book and allows adding and searching.
int	main(void)
{
	std::string	mode, input;
	PhoneBook	book;
	Contact *	head;

	book.initialise();
	std::cout << "----- Awesome Phone Book -----\nYou may: ADD - SEARCH - EXIT" << std::endl;
	std::getline(std::cin, mode);
	while (mode != "EXIT")
	{
		if (mode == "ADD")
		{
			std::cout << "Add Contact" << std::endl;
			head = book.add_contact();
			if (book.search(book.get_num_contacts()) == head)
				std::cout << "Successfully added contact.\n";
			else
				std::cout << "Error: couldn't add contact.\n";
			std::cout << std::endl << "MAIN MENU - ADD - SEARCH - EXIT" << std::endl;
		}
		else if (mode == "SEARCH")
		{
			search_menu(book);
			std::cout << std::endl << "MAIN MENU - ADD - SEARCH - EXIT" << std::endl;
		}
		else
			std::cout << "\nTry again\n\nMAIN MENU - ADD - SEARCH - EXIT\n";
		std::getline(std::cin, mode);
	}
	book.close();
	return (0);
}
