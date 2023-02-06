/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 22:48:08 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/06 01:21:21 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

//Function initialises the private attributes of the object.
void	PhoneBook::initialise(void)
{
	this->num_contacts = 0;
}

//Function adds a contact with information to a phone book object.
Contact *	PhoneBook::add_contact(void)
{
	Contact *	cont;
	std::string	input;

	cont = new Contact();
	contacts[this->num_contacts] = cont;
	cont->assign_index(this->num_contacts + 1);
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
	if (num_contacts == 8)
	{
		replace_contact(this->search(8), cont);
		delete cont;
		return (this->search(8));
	}
	else
		num_contacts++;
	return (cont);
}

//Function searches for a contact in a phone book object by its index.
Contact *	PhoneBook::search(int ind)
{
	Contact *	head;
	int			i = 0;

	head = contacts[i];
	while (i <= this->num_contacts)
	{
		if (head->get_index() == ind)
			return (head);
		if (i < this->num_contacts)
			head = contacts[i];
		i++;
	}
	return (NULL);
}

//Function returns the number of contacts stored in the phone book.
int	PhoneBook::get_num_contacts(void)
{
	return (this->num_contacts);
}

//Function writes over contact information from one to another.
void	PhoneBook::replace_contact(Contact * replace, Contact * cont)
{
	replace->fill_firstname(cont->get_firstname());
	replace->fill_lastname(cont->get_lastname());
	replace->fill_nickname(cont->get_nickname());
	replace->fill_phone(cont->get_phone());
	replace->fill_secret(cont->get_secret());
}

//Function deletes any contacts in the book.
void	PhoneBook::close(void)
{
	int			i = 0;
	Contact *	head;

	while (i < this->num_contacts)
	{
		head = contacts[i];
		delete head;
		i++;
	}
}
