/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 20:41:33 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/10 09:49:32 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON
# define WEAPON
# include <string>

//Class for a Weapon.
class	Weapon
{
	public:
		Weapon(void);
		Weapon(std::string type);
		bool		operator!(void);
		std::string	getType(void);
		void		setType(std::string type);

	private:
		std::string	type;
};
#endif
