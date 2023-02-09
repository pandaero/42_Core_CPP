/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 20:41:33 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/09 22:21:47 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON
# define WEAPON
# include <string>

//Class for a Weapon.
class	Weapon
{
	public:
		bool		operator!(void);
		std::string	getType(void);
		void		setType(std::string type);

	private:
		std::string	type;
};
#endif
