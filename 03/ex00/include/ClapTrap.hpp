/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:05:24 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/15 21:33:26 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP
# define CLAPTRAP
# include <string>

class	ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(const ClapTrap & fixed);
		~ClapTrap();
		ClapTrap &	operator=(const ClapTrap & other);

		ClapTrap(std::string name);

		void	attack(const std::string & target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		
	private:
		std::string	name;
		int			hitpoints;
		int			energypts;
		int			attackdmg;
};
#endif
