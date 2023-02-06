/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 22:48:00 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/06 01:05:39 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK
# define PHONEBOOK

# include "Contact.hpp"
# include <string>

class	PhoneBook
{
	public:
		void		initialise(void);
		Contact *	add_contact(void);
		Contact *	search(int ind);
		void		replace_contact(Contact * replace, Contact * cont);
		int			get_num_contacts(void);
		void		close(void);

	private:
		int			num_contacts;
		Contact *	contacts[8];
};
#endif
