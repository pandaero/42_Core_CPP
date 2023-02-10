/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:14:15 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/10 09:08:49 by pandalaf         ###   ########.fr       */
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
		void	setWeapon(Weapon & weapon);
		void	attack(void);
	private:
		std::string	name;
		Weapon		weapon;
};
#endif
