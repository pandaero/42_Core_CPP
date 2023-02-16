/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 10:57:42 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/16 11:30:29 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP
# define DIAMONDTRAP
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class	DiamondTrap: public ScavTrap, public FragTrap
{
	public:
		DiamondTrap(void);
		DiamondTrap(const DiamondTrap & other);
		~DiamondTrap(void);
		DiamondTrap &	operator=(const DiamondTrap & other);

		DiamondTrap(const std::string name);
		void	whoAmI(void);

	private:
		std::string	name;
};
#endif
