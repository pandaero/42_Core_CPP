/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 20:50:22 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/10 09:50:15 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA
# define HUMANA
# include "Weapon.hpp"

//Class for human A.
class	HumanA
{
	public:
		HumanA(std::string name, Weapon& weapon);
		void	attack(void);
	private:
		std::string	name;
		Weapon&	weapon;
};
#endif
