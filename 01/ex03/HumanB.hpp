/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:14:15 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/10 09:47:01 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB
# define HUMANB
# include "Weapon.hpp"
# include <string>

//Class for human B.
class	HumanB
{
	public:
		HumanB(std::string name);
		void	setWeapon(Weapon& weapon);
		void	attack(void);
	
	private:
		std::string	name;
		Weapon*		weapon;
};
#endif
