/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 22:48:00 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/06 01:05:39 by pandalaf         ###   ########.fr       */
/*                                   c2w                                         */
/* ************************************************************************** */

#ifndef PHONEBOOK
# define PHONEBOOK
# include "Contact.hpp"


class	PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);
		int			get_num_contacts(void);
		Contact *	add_contact(void);
		Contact	*	search(int ind);

	private:
		int			num_contacts;
		Contact *	contacts[8];
};
#endif
