/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 20:41:33 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/09 21:09:31 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON
# define WEAPON
# include <string>

//Class for a Weapon.
class	Weapon
{
	public:
		std::string	getType(void);
		void		setType(std::string type);

	private:
		std::string	type;
};
#endif
