/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:05:24 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/16 10:21:57 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP
# define CLAPTRAP
# include <string>

class	ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(const ClapTrap & claptrap);
		~ClapTrap();
		ClapTrap &	operator=(const ClapTrap & other);

		ClapTrap(std::string name);

		void	attack(const std::string & target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		
	protected:
		std::string	name;
		int			hitpoints;
		int			energypts;
		int			attackdmg;
};
#endif
