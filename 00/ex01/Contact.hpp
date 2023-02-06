/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 22:47:57 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/06 01:05:22 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT
# define CONTACT
# include <string>
# include <iomanip>
# include <iostream>
# include <sstream>

class Contact
{
	public:
		void		assign_index(int ind);
		void		fill_firstname(std::string str);
		void		fill_lastname(std::string str);
		void		fill_nickname(std::string str);
		void		fill_phone(std::string str);
		void		fill_secret(std::string str);
		int			get_index(void);
		std::string	get_firstname(void);
		std::string	get_lastname(void);
		std::string	get_nickname(void);
		std::string	get_phone(void);
		std::string	get_secret(void);
		void		print(void);
		void		print_details(void);

	private:
		int			index;
		std::string	firstname, lastname, nickname, phone, darksecret;
};
#endif
