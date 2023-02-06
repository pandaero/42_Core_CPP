/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 22:48:10 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/06 01:41:09 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

//Function assigns an index to the contact.
void	Contact::assign_index(int ind)
{
	this->index = ind;
}

//Function fills the first name field of the contact information.
void	Contact::fill_firstname(std::string str)
{
	this->firstname = str;
}

//Function fills the lastname field of the contact information.
void	Contact::fill_lastname(std::string str)
{
	this->lastname = str;
}

//Function fills the nickname field of the contact information.
void	Contact::fill_nickname(std::string str)
{
	this->nickname = str;
}

//Function fills the phone number field of the contact information.
void	Contact::fill_phone(std::string str)
{
	this->phone = str;
}

//Function fills the darkest secret field of the contact information.
void	Contact::fill_secret(std::string str)
{
	this->darksecret = str;
}

//Function returns the index of the contact.
int	Contact::get_index(void)
{
	return (this->index);
}

//Function returns the string corresponding to the first name.
std::string	Contact::get_firstname(void)
{
	return (this->firstname);
}

//Function returns the string corresponding to the lastname.
std::string	Contact::get_lastname(void)
{
	return (this->lastname);
}

//Function returns the string corresponding to the nickname.
std::string	Contact::get_nickname(void)
{
	return (this->nickname);
}

//Function returns the string corresponding to the phone number.
std::string	Contact::get_phone(void)
{
	return (this->phone);
}

//Function returns the string corresponding to the dark secret.
std::string	Contact::get_secret(void)
{
	return (this->darksecret);
}

//Function displays a contact's information preview.
void	Contact::print(void)
{
	std::stringstream	indstr, first, last, nick;
	indstr << std::setw(10) << index;
	if (firstname.length() > 10)
		first << firstname.substr(0, 9) << ".";
	else
		first << std::setw(10) << firstname;
	if (lastname.length() > 10)
		last << lastname.substr(0, 9) << ".";
	else
		last << std::setw(10) << lastname;
	if (nickname.length() > 10)
		nick << nickname.substr(0, 9) << ".";
	else
		nick << std::setw(10) << nickname;
	std::cout << '|' << indstr.str() << '|' << first.str() << '|' << last.str() << '|' << nick.str();
	std::cout << '|' << std::endl;	
}

//Function displays a contact's full information.
void	Contact::print_details(void)
{
	std::cout << "CONTACT - " << index << "\n";
	std::cout << "First name: " << firstname << "\n";
	std::cout << "Last name: " << lastname << "\n";
	std::cout << "Nickname: " << nickname << "\n";
	std::cout << "Phone number: " << phone << "\n";
	std::cout << "Darkest secret: " << darksecret << "\n";
}

