/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 22:48:08 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/08 22:29:45 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <string>

//Function constructs a phone book object.
PhoneBook::PhoneBook(void)
{
	Contact *	one = new Contact();
	Contact *	two = new Contact();
	Contact *	three = new Contact();
	Contact *	four = new Contact();
	Contact *	five = new Contact();
	Contact *	six = new Contact();
	Contact *	seven = new Contact();
	Contact *	eight = new Contact();

	this->num_contacts = 0;
	this->contacts[0] = one;
	this->contacts[1] = two;
	this->contacts[2] = three;
	this->contacts[3] = four;
	this->contacts[4] = five;
	this->contacts[5] = six;
	this->contacts[6] = seven;
	this->contacts[7] = eight;
}

//Function destroys a phone book object.
PhoneBook::~PhoneBook(void)
{
	delete this->contacts[0];
	delete this->contacts[1];
	delete this->contacts[2];
	delete this->contacts[3];
	delete this->contacts[4];
	delete this->contacts[5];
	delete this->contacts[6];
	delete this->contacts[7];
}

//Function adds a contact with information to a phone book object.
Contact *	PhoneBook::add_contact(int time)
{
	Contact *	cont;
	std::string	input;

	cont = this->contacts[time % 8];
	cont->assign_index((time % 8) + 1);
	std::cout << "Index " << cont->get_index() << " / (8)\n";
	// Get first name
	std::cout << "First Name: ";
	std::getline(std::cin, input);
	while (input == "")
	{
		std::cout << "\nCannot be empty, try again: ";
		std::getline(std::cin, input);
	}
	cont->fill_firstname(input);
	// Get lastname
	std::cout << "Lastname: ";
	std::getline(std::cin, input);
	while (input == "")
	{
		std::cout << "\nCannot be empty, try again: ";
		std::getline(std::cin, input);
	}
	cont->fill_lastname(input);
	// Get nickname
	std::cout << "Nickname: ";
	std::getline(std::cin, input);
	while (input == "")
	{
		std::cout << "\nCannot be empty, try again: ";
		std::getline(std::cin, input);
	}
	cont->fill_nickname(input);
	// Get phone number
	std::cout << "Phone Number: ";
	std::getline(std::cin, input);
	while (input == "")
	{
		std::cout << "\nCannot be empty, try again: ";
		std::getline(std::cin, input);
	}
	cont->fill_phone(input);
	// Get darkest secret
	std::cout << "Darkest Secret: ";
	std::getline(std::cin, input);
	while (input == "")
	{
		std::cout << "\nCannot be empty, try again: ";
		std::getline(std::cin, input);
	}
	cont->fill_secret(input);
	// Check for last element
	if (this->num_contacts == 8)
		return (cont);
	else
		this->num_contacts++;
	return (cont);
}

//Function searches for a contact in a phone book object by its index.
Contact *	PhoneBook::search(int ind)
{
	Contact *	head;
	int			i = 1;

	head = this->contacts[0];
	while (i <= this->num_contacts)
	{
		if (head->get_index() == ind)
			return (head);
		if (i < this->num_contacts)
			head = this->contacts[i];
		i++;
	}
	return (NULL);
}

//Function returns the number of contacts stored in the phone book.
int	PhoneBook::get_num_contacts(void)
{
	return (this->num_contacts);
}
